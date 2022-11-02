#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
     char s[105];
     char c[2][20] = {"2147483647", "9223372036854775807"};
     int i;

     scanf("%s", s);

     if (strlen(s) < 10) {
	  int x = atoi(s);

	  if (x <= 127) {
	       puts("byte");
	  } else if (x <= 32767) {
	       puts("short");
	  } else {
	       puts("int");
	  }
     } else if (strlen(s) == 10) {
	  for (i = 0; i < 10; i++) {
	       if (s[i] < c[0][i]) {
		    puts("int");

		    break;
	       } else if (s[i] > c[0][i]) {
		    puts("long");

		    break;
	       }
	  }

	  if (i == 10) puts("int");
     } else if (strlen(s) < 19) {
	  puts("long");
     } else if (strlen(s) == 19) {
	  for (i = 0; i < 19; i++) {
	       if (s[i] < c[1][i]) {
		    puts("long");

		    break;
	       } else if (s[i] > c[1][i]) {
		    puts("BigInteger");

		    break;
	       }
	  }

	  if (i == 19) puts("long");
     } else {
	  puts("BigInteger");
     }

     return 0;
}