#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
     if (a < b) return gcd(b, a);

     if (a % b == 0) {
	  return b;
     } else {
	  return gcd(b, a % b);
     }
}

int cmp(const void *a, const void *b)
{
     return *((int *)b) - *((int *)a);
}

int main()
{
     int a, b, g, n, p = 0, i, j;
     int c[10000];

     scanf("%d %d", &a, &b);
     scanf("%d", &n);

     g = gcd(a, b);

     for (i = 1; i * i <= g; i++) {
	  if (g % i == 0) {
	       c[p++] = i;
	       c[p++] = g / i;
	  }
     }

     qsort(c, p, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  int l, r;

	  scanf("%d %d", &l, &r);

	  for (j = 0; j < p; j++) {
	       if (c[j] >= l && c[j] <= r) {
		    printf("%d\n", c[j]);

		    break;
	       }
	  }

	  if (j == p) puts("-1");
     }

     return 0;
}