#include <stdio.h>
#include <string.h>

int main()
{
     int p = 0, m = 1000003, i, j;
     char s[101];
     char c[8] = "><+-.,[]";

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  for (j = 0; j < 8; j++) {
	       if (s[i] == c[j]) break;
	  }

	  p *= 16;
	  p += j + 8;
	  p %= m;
     }

     printf("%d\n", p);

     return 0;
}