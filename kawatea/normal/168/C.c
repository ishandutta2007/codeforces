#include <stdio.h>
#include <math.h>

int main()
{
     int n, a, d, i;
     double p = 0;

     scanf("%d %d %d", &n, &a, &d);

     for (i = 0; i < n; i++) {
	  int t, v;

	  scanf("%d %d", &t, &v);

	  if ((double)v * v / a / 2 < d) {
	       double x = (d - (double)v * v / a / 2) / v + (double)v / a;

	       if (t + x > p) {
		    printf("%.10lf\n", t + x);

		    p = t + x;
	       } else {
		    printf("%.10lf\n", p);
	       }
	  } else {
	       double x = sqrt(2.0 * d / a);

	       if (t + x > p) {
		    printf("%.10lf\n", t + x);

		    p = t + x;
	       } else {
		    printf("%.10lf\n", p);
	       }
	  }
     }

     return 0;
}