#include <stdio.h>

int main()
{
     int n, m, a, b, min = 10000, i, j, l, k;
     int c[50][50];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       scanf("%d", &c[i][j]);
	  }
     }

     scanf("%d %d", &a, &b);

     if (a <= n && b <= m) {
	  for (i = 0; i <= n - a; i++) {
	       for (j = 0; j <= m - b; j++) {
		    int d = 0;

		    for (k = i; k < i + a; k++) {
			 for (l = j; l < j + b; l++) {
			      if (c[k][l] == 1) d++;
			 }
		    }

		    if (d < min) min = d;
	       }
	  }
     }

     if (a <= m && b <= n) {
	  for (i = 0; i <= n - b; i++) {
	       for (j = 0; j <= m - a; j++) {
		    int d = 0;

		    for (k = i; k < i + b; k++) {
			 for (l = j; l < j + a; l++) {
			      if (c[k][l] == 1) d++;
			 }
		    }

		    if (d < min) min = d;
	       }
	  }
     }

     printf("%d\n", min);

     return 0;
}