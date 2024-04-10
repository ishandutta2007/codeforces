#include <stdio.h>
#include <string.h>

int main()
{
     char s[1001];
     int n, f = 0, i, j, k;

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  for (j = i + 1; j < n; j++) {
	       if (s[j] == '>') break;
	  }

	  if (s[i + 1] == '/') {
	       f--;

	       for (k = 0; k < f * 2; k++) putchar(' ');

	       for (k = i; k <= j; k++) putchar(s[k]);
	       puts("");
	  } else {
	       for (k = 0; k < f * 2; k++) putchar(' ');

	       for (k = i; k <= j; k++) putchar(s[k]);
	       puts("");

	       f++;
	  }

	  i = j;
     }

     return 0;
}