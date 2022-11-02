#include <stdio.h>

int main()
{
     int n, m, i, j, k;
     char s[100][101];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       for (k = 0; k < n; k++) {
		    if (k == i) continue;

		    if (s[i][j] == s[k][j]) break;
	       }

	       if (k < n) continue;

	       for (k = 0; k < m; k++) {
		    if (k == j) continue;

		    if (s[i][j] == s[i][k]) break;
	       }

	       if (k == m) printf("%c", s[i][j]);
	  }
     }
     puts("");

     return 0;
}