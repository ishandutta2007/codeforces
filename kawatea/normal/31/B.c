#include <stdio.h>
#include <string.h>

int main()
{
     char s[201];
     int n = 0, i;

     scanf("%s", s);

     if (s[0] == '@' || s[strlen(s) - 1] == '@') {
	  puts("No solution");

	  return 0;
     }

     for (i = 0; i < strlen(s) - 1; i++) {
	  if (s[i] == '@') {
	       if (s[i + 1] == '@' || s[i + 2] == '@') {
		    puts("No solution");

		    return 0;
	       }

	       n++;
	  }
     }

     if (n == 0) {
	  puts("No solution");

	  return 0;
     }

     for (i = 0; i < strlen(s); i++) {
	  if (s[i] == '@') {
	       putchar(s[i]);
	       if (--n > 0) printf("%c,", s[++i]);
	  } else {
	       putchar(s[i]);
	  }
     }
     puts("");

     return 0;
}