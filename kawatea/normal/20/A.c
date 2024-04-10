#include <stdio.h>
#include <string.h>

int main()
{
     char s[101], c[101];
     int f = 0, p = 0, i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  if (s[i] != '/') {
	       c[p++] = s[i];
	       f = 0;
	  } else if (f == 0) {
	       c[p++] = s[i];
	       f = 1;
	  }
     }

     if (p > 2 && c[p - 1] == '/') p--;

     c[p] = '\0';

     printf("%s\n", c);

     return 0;
}