#include <stdio.h>

int par[100];

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
     int n, i;
     int a[100], b[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);
     for (i = 0; i < n; i++) scanf("%d", &b[i]);

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 0; i < n; i++) {
	  if (b[i] <= i) {
	       unite(i, i - b[i]);
	  }

	  if (b[i] + i < n) {
	       unite(i, b[i] + i);
	  }
     }

     for (i = 0; i < n; i++) {
	  if (same(i, a[i] - 1) == 0) {
	       puts("NO");

	       return 0;
	  }
     }

     puts("YES");

     return 0;
}