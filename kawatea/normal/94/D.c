#include <stdio.h>

int main()
{
     int n, w, m, i, j;
     double a[50];
     int b[50][50];
     int p[50] = {0};
     int f[50] = {0};
     double c[50][50];

     scanf("%d %d %d", &n, &w, &m);

     for (i = 0; i < n; i++) a[i] = w;

     for (i = 0; i < m; i++) {
	  double d = (double)n * w / m;

	  for (j = 0; j < n; j++) {
	       if (a[j] > 0) {
		    if (d > a[j]) {
			 b[i][p[i]] = j + 1;
			 c[i][p[i]++] = a[j];

			 d -= a[j];
			 a[j] = 0;
			 f[j]++;

			 if (d < 1e-3) break;
		    } else {
			 b[i][p[i]] = j + 1;
			 c[i][p[i]++] = d;

			 a[j] -= d;
			 f[j]++;

			 if (a[j] < 1e-3) a[j] = 0;

			 break;
		    }
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  if (f[i] > 2) break;
     }

     if (i < n) {
	  puts("NO");
     } else {
	  puts("YES");

	  for (i = 0; i < m; i++) {
	       for (j = 0; j < p[i]; j++) {
		    if (j > 0) putchar(' ');
		    printf("%d %lf", b[i][j], c[i][j]);
	       }
	       puts("");
	  }
     }

     return 0;
}