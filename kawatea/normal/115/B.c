#include <stdio.h>

int main()
{
     int n, m, x = 0, f = 0, sum = 0, i, j;
     char s[150][151];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  if (i % 2 == 0) {
	       for (j = m - 1; j >= x; j--) {
		    if (s[i][j] == 'W') break;

		    if (i < n - 1 && s[i + 1][j] == 'W') break;
	       }

	       if (j >= x) {
		    sum += j - x;

		    x = j;

		    f = i;
	       }
	  } else {
	       for (j = 0; j <= x; j++) {
		    if (s[i][j] == 'W') break;

		    if (i < n - 1 && s[i + 1][j] == 'W') break;
	       }

	       if (j <= x) {
		    sum += x - j;

		    x = j;

		    f = i;
	       }
	  }
     }

     printf("%d\n", sum + f);

     return 0;
}