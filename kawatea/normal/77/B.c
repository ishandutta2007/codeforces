#include <stdio.h>
#include <math.h>

int main()
{
     int t, i;

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int a, b;

	  scanf("%d %d", &a, &b);

	  if (a == 0 && b == 0) {
	       puts("1");
	  } else if (4 * b < a) {
	       printf("%.9lf\n", 1 - (double)b / a);
	  } else {
	       printf("%.9lf\n", 0.5 + (double)a / (16 * b));
	  }
     }

     return 0;
}