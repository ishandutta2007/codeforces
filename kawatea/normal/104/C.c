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
     int n, m, x, y, i, j;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 0; i < m; i++) {
	  scanf("%d %d", &x, &y);

	  unite(x - 1, y - 1);
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (same(i, j) == 0) {
		    puts("NO");

		    return 0;
	       }
	  }
     }

     if (m == n) {
	  puts("FHTAGN!");
     } else {
	  puts("NO");
     }

     return 0;
}