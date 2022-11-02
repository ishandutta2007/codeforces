#include <stdio.h>

int main()
{
     int n, m, x1, x2, y1, y2, i, j;
     char s[50][51];

     scanf("%d %d", &n, &m);

     x1 = 0; x2 = n;
     y1 = 0; y2 = m;

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '*') break;
	  }

	  if (j == m) {
	       x1++;
	  } else {
	       break;
	  }
     }

     for (i = n - 1; i > 0; i--) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '*') break;
	  }

	  if (j == m) {
	       x2--;
	  } else {
	       break;
	  }
     }

     for (i = 0; i < m; i++) {
	  for (j = 0; j < n; j++) {
	       if (s[j][i] == '*') break;
	  }

	  if (j == n) {
	       y1++;
	  } else {
	       break;
	  }
     }

     for (i = m - 1; i > 0; i--) {
	  for (j = 0; j < n; j++) {
	       if (s[j][i] == '*') break;
	  }

	  if (j == n) {
	       y2--;
	  } else {
	       break;
	  }
     }

     for (i = x1; i < x2; i++) {
	  for (j = y1; j < y2; j++) {
	       printf("%c", s[i][j]);
	  }
	  puts("");
     }

     return 0;
}