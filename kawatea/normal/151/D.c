#include <stdio.h>

int par[2000];

int find(int x)
{
    if (par[x] == x) return x;

    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;

    par[x] = y;
}

int same(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) {
	return 1;
    } else {
	return 0;
    }
}

int main()
{
     int n, m, k, mod = 1000000007, i, j;
     long long ans = 1;
     int a[2000] = {0};

     scanf("%d %d %d", &n, &m, &k);

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 0; i <= n - k; i++) {
	  for (j = 0; j <= k / 2; j++) {
	       unite(i + j, i + k - j - 1);
	  }
     }

     for (i = 0; i < n; i++) a[find(i)]++;

     for (i = 0; i < n; i++) {
	  if (a[i] > 0) {
	       ans = ans * m % mod;
	  }
     }

     printf("%d\n", (int)ans);

     return 0;
}