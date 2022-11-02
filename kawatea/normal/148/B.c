#include <stdio.h>

int main()
{
     int vp, vd, t, f, c, sum = 1;
     double x, y;

     scanf("%d %d %d %d %d", &vp, &vd, &t, &f, &c);

     if (vp >= vd || vp * t >= c || vd * vp * t >= c * (vd - vp)) {
	  puts("0");

	  return 0;
     }

     x = (double)vp * t / (vd - vp);
     y = vp * (t + x);

     while (1) {
	  y += vp * (x + f);
	  x = y / (vd - vp);
	  y += vp * x;

	  if (y >= c) break;

	  sum++;
     }

     printf("%d\n", sum);

     return 0;
}