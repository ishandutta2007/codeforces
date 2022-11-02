#include <stdio.h>

int par[100000];

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

int lucky(int x)
{
     while (x) {
	  if (x % 10 != 4 && x % 10 != 7) return 0;

	  x /= 10;
     }

     return 1;
}

int main()
{
     int n, i;
     int a[100000] = {0};
     long long sum = 0;

     scanf("%d", &n);

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 0; i < n - 1; i++) {
	  int u, v, w;

	  scanf("%d %d %d", &u, &v, &w);

	  if (lucky(w) == 0) unite(u - 1, v - 1);
     }

     for (i = 0; i < n; i++) a[find(i)]++;

     for (i = 0; i < n; i++) {
	  int p = n - a[find(i)];

	  if (p >= 2) sum += (long long)p * (p - 1);
     }

     printf("%I64d\n", sum);

     return 0;
}