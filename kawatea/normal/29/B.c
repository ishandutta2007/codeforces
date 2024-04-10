#include <stdio.h>

int main()
{
     int l, d, v, g, r, x;

     scanf("%d %d %d %d %d", &l, &d, &v, &g, &r);

     x = d / v % (g + r);

     if (x >= g) {
	  printf("%.9lf\n", d / v + g + r - x + (double)(l - d) / v);
     } else {
	  printf("%.9lf\n", (double)l / v);
     }

     return 0;
}