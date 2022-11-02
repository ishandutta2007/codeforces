#include <stdio.h>
#include <string.h>

int main()
{
     char s1[205], s2[205];
     int i, j;

     fgets(s1, 205, stdin);
     fgets(s2, 205, stdin);

     for (i = 0; i < strlen(s2); i++) {
	  if (s2[i] == ' ') continue;

	  for (j = 0; j < strlen(s1); j++) {
	       if (s2[i] == s1[j]) {
		    s1[j] = '.';

		    break;
	       }
	  }

	  if (j == strlen(s1)) {
	       puts("NO");

	       return 0;
	  }
     }

     puts("YES");

     return 0;
}