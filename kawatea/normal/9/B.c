#include <stdio.h>
#include <math.h>

int main()
{
     int n, vb, vs, xu, yu, num = 0, i;
     int a[100];
     double min1 = 1e9, min2 = 1e9;

     scanf("%d %d %d", &n, &vb, &vs);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     scanf("%d %d", &xu, &yu);

     for (i = 1; i < n; i++) {
	  double d = sqrt((double)(a[i] - xu) * (a[i] - xu) + (double)yu * yu);
	  double t = (double)a[i] / vb + d / vs;

	  if (t < min1) {
	       min1 = t; min2 = d; num = i;
	  } else if (t == min1 && d < min2) {
	       min2 = d; num = i;
	  }
     }

     printf("%d\n", num + 1);

     return 0;
}