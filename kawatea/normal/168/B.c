#include <stdio.h>

int main()
{
     int p = 0, q = 0, f, i, j;
     char s[1048577];

     while ((s[q] = getchar()) != EOF) q++;

     for (i = 0; i < q; i++) {
	  int c = 0;

	  for (j = p; j < q; j++) {
	       if (s[j] == ' ') continue;

	       if (s[j] == '#') {
		    c = 1;
	       }

	       break;
	  }

	  if (f == 0 && c == 1) putchar('\n');

	  f = c;

	  for (i = p; i < q; i++) {
	       if (s[i] == '\n') break;

	       if (f == 0 && s[i] == ' ') continue;

	       putchar(s[i]);
	  }

	  if (f == 1) putchar('\n');

	  p = i + 1;
     }

     if (f == 0) putchar('\n');

     return 0;
}