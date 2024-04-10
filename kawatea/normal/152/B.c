#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, m, x, y, k, i;
     long long sum = 0;

     scanf("%d %d", &n, &m);

     scanf("%d %d", &x, &y);

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  int dx, dy, p;

	  scanf("%d %d", &dx, &dy);

	  if (dx == 0) {
	       if (dy > 0) {
		    p = (m - y) / dy;
	       } else {
		    p = (1 - y) / dy;
	       }
	  } else if (dy == 0) {
	       if (dx > 0) {
		    p = (n - x) / dx;
	       } else {
		    p = (1 - x) / dx;
	       }
	  } else if (dx > 0 && dy > 0) {
	       p = min((n - x) / dx, (m - y) / dy);
	  } else if (dx > 0) {
	       p = min((n - x) / dx, (1 - y) / dy);
	  } else if (dy > 0) {
	       p = min((1 - x) / dx, (m - y) / dy);
	  } else {
	       p = min((1 - x) / dx, (1 - y) / dy);
	  }

	  sum += p;

	  x += p * dx;
	  y += p * dy;
     }

     printf("%I64d\n", sum);

     return 0;
}