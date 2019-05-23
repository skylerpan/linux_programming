#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //getopt

#define DBG(...) printf("== sk == "); printf(__VA_ARGS__)

int usage(void) {
	return 0;
}

int main(int argc, char *argv[]) {
	int opt = 0;

	opterr = 1; // Enable print opterr msg

	while(1) {

		opt = getopt(argc, argv,"ds:");
		if(opt == -1)
			break;

		switch(opt)	{
			case 'd':
				break;
			case 's':
				printf("%s", optarg);
				break;
			default: // '?'
		        DBG("TEST\n");
				usage();
				return 0;
		}
	}
	//Do we have args?
	if (argc > optind) {
		int i = 0;
		for (i = optind; i < argc; i++) {
			fprintf(stderr, "argv[%d] = %s\n", i, argv[i]);
		}
	}
	return 0;
}
