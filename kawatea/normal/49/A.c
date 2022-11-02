#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
     char s[105];
     char c[13] = "aeiouyAEIOUY";
     int i, j;

     fgets(s, 105, stdin);

     for (i = strlen(s); i >= 0; i--) {
	  if (isalpha(s[i])) {
	       for (j = 0; j < 12; j++) {
		    if (s[i] == c[j]) break;
	       }

	       if (j == 12) {
		    puts("NO");
	       } else {
		    puts("YES");
	       }

	       break;
	  }
     }

     return 0;
}