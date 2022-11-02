#include <stdio.h>
#include <string.h>

int main()
{
     char s[200001], c[200001];
     int n, p = 0, i;

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  if (i < n - 1 && s[i] == s[i + 1]) {
	       i++;
	  } else if (p > 0 && s[i] == c[p - 1]) {
	       p--;
	  } else {
	       c[p++] = s[i];
	  }
     }

     c[p] = '\0';

     printf("%s\n", c);

     return 0;
}