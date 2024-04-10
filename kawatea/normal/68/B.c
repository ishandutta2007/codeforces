#include <stdio.h>

int main()
{
     int n, k, i;
     int a[10000];
     double l = 0, r = 1000, u = 500;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     while (r - l > 0.000000001) {
	  double res = 0;

	  for (i = 0; i < n; i++) {
	       if (a[i] < u) {
		    res -= u - a[i];
	       } else {
		    res += (a[i] - u) * (100 - k) / 100;
	       }
	  }

	  if (res > 0) {
	       l = u;
	       u = (l + r) / 2;
	  } else {
	       r = u;
	       u = (l + r) / 2;
	  }
     }

     printf("%.9lf\n", u);

     return 0;
}