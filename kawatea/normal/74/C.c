#include <stdio.h>

int par[4000000];
int f[4000000];

int find(int x)
{
     if (par[x] == x) {
	  return x;
     } else {
	  return par[x] = find(par[x]);
     }
}

void unite(int x, int y)
{
     x = find(x);
     y = find(y);

     if (x == y) return;

     par[x] = y;
}

int main()
{
     int n, m, sum = 0, i, j;

     scanf("%d %d", &n, &m);

     if (n < m) {
	  int tmp = n; n = m; m = tmp;
     }

     for (i = 0; i < 2 * n + 2 * m; i++) par[i] = i;

     for (i = 0; i < n; i++) {
	  if (i + m <= n) {
	       unite(n + i + m - 1, i);
	       unite(i + m - 1, n + i);
	  } else {
	       unite(3 * n + m - i - 1, i);
	       unite(n + 2 * m + i, n + i);
	  }

	  if (i >= m - 1) {
	       unite(n + i - m + 1, i);
	       unite(i - m + 1, n + i);
	  } else {
	       unite(2 * n + i, i);
	       unite(2 * n + m - i - 1, n + i);
	  }
     }

     for (i = 0; i < 2 * n + 2 * m; i++) f[find(i)]++;

     for (i = 0; i < 2 * n + 2 * m; i++) {
	  if (f[i] > 0) sum++;
     }

     printf("%d\n", sum);

     return 0;
}