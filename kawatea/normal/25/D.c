#include <stdio.h>

int par[1000];

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

     par[x] = y;
}

int same(int x, int y)
{
     if (find(x) == find(y)) {
	  return 1;
     } else {
	  return 0;
     }
}

int main()
{
     int n, p = 0, i, j;
     int c[1000][2];

     scanf("%d", &n);

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 0; i < n - 1; i++) {
	  int a, b;

	  scanf("%d %d", &a, &b);

	  if (same(a - 1, b - 1) == 1) {
	       c[p][0] = a;
	       c[p++][1] = b;
	  } else {
	       unite(a - 1, b - 1);
	  }
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  for (j = 0; j < n; j++) {
	       if (same(c[i][0] - 1, j) == 0) {
		    unite(c[i][0] - 1, j);

		    printf("%d %d %d %d\n", c[i][0], c[i][1], c[i][0], j + 1);

		    break;
	       }
	  }
     }

     return 0;
}