#include <stdio.h>

int n, k, a;
double max = 0;
int b[8], l[8];
int c[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
char f[80000001];

void dfs(int x, int y)
{
     int i, j;

     if (x == k) {
	  int p[8];
	  double all = 0;

	  if (f[y] == 1) return;

	  f[y] = 1;

	  for (i = 0; i < n; i++) {
	       p[i] = l[i] + y / c[i] % 10 * 10;

	       if (p[i] > 100) p[i] = 100;
	  }

	  for (i = 0; i < (1 << n); i++) {
	       int num = 0, sum = 0;
	       double m = 1;

	       for (j = 0; j < n; j++) {
		    if ((i >> j) & 1) {
			 m *= p[j] / 100.0;
			 num++;
		    } else {
			 m *= (100 - p[j]) / 100.0;
			 sum += b[j];
		    }
	       }

	       if (num <= n / 2) {
		    m *= (double)a / (a + sum);
	       }

	       all += m;
	  }

	  if (all > max) max = all;
     } else {
	  for (i = 0; i < n; i++) {
	       dfs(x + 1, y + c[i]);
	  }
     }
}

int main()
{
     int i;

     scanf("%d %d %d", &n, &k, &a);

     for (i = 0; i < n; i++) scanf("%d %d", &b[i], &l[i]);

     dfs(0, 0);

     printf("%.9lf\n", max);

     return 0;
}