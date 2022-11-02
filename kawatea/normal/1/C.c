#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2)
{
     return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
     double x1, y1, x2, y2, x3, y3, x, y, r, p = acos(-1);
     double a, b, c, d, e, f, s1, s2, s3;
     int i;

     scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

     a = x2 - x1;
     b = y2 - y1;
     c = a * (x1 + x2) / 2 + b * (y1 + y2) / 2;

     d = x3 - x2;
     e = y3 - y2;
     f = d * (x2 + x3) / 2 + e * (y2 + y3) / 2;

     if (a == 0) {
	  y = c / b;
	  x = f - e * y / d;
     } else if (b == 0) {
	  x = c / a;
	  y = f - d * x / e;
     } else {
	  x = (c * e / b - f) / (a * e / b - d);
	  y = (c - a * x) / b;
     }

     r = dist(x, y, x1, y1);

     x1 -= x; x2 -= x; x3 -= x;
     y1 -= y; y2 -= y; y3 -= y;

     s1 = asin(fabs(x1 * y2 - x2 * y1) / r / r);
     s2 = asin(fabs(x2 * y3 - x3 * y2) / r / r);
     s3 = asin(fabs(x3 * y1 - x1 * y3) / r / r);

     a = dist(x1, y1, x2, y2);
     b = dist(x2, y2, x3, y3);
     c = dist(x3, y3, x1, y1);

     if (acos((2 * r * r - a * a) / (2 * r * r)) > p / 2) s1 = p - s1;
     if (acos((2 * r * r - b * b) / (2 * r * r)) > p / 2) s2 = p - s2;
     if (acos((2 * r * r - c * c) / (2 * r * r)) > p / 2) s3 = p - s3;

     for (i = 3; ; i++) {
	  double x = 2.0 * p / i;
	  double d1 = s1 / x;
	  double d2 = s2 / x;
	  double d3 = s3 / x;

	  if (fabs(d1 - round(d1)) > 0.01) continue;
	  if (fabs(d2 - round(d2)) > 0.01) continue;
	  if (fabs(d3 - round(d3)) > 0.01) continue;

	  printf("%.9lf\n", r * r * sin(2.0 * p / i) / 2 * i);

	  return 0;
     }

     return 0;
}