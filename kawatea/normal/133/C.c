#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     int n, p = 0, i, j;
     char s[105];

     fgets(s, 105, stdin);

     n = strlen(s);

     s[n--] = '\0';

     for (i = 0; i < n; i++) {
	  int x = s[i], y = 0;

	  for (j = 0; j < 8; j++) {
	       y *= 2;
	       y += x % 2;
	       x /= 2;
	  }

	  p -= y;
	  p += 256;
	  p %= 256;

	  printf("%d\n", p);

	  p = y;
     }

     return 0;
}