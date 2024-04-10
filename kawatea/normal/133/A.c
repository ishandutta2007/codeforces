#include <stdio.h>
#include <string.h>

int main()
{
     int i;
     char s[101];

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
	       puts("YES");

	       return 0;
	  }
     }

     puts("NO");

     return 0;
}