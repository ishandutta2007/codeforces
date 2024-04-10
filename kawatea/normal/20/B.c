#include <stdio.h>
#include <math.h>

int main()
{
     int a, b, c;
     long long d;

     scanf("%d %d %d", &a, &b, &c);

     d = (long long)b * b - (long long)4 * a * c;

     if (a == 0) {
	  if (b == 0) {
	       if (c == 0) {
		    puts("-1");
	       } else {
		    puts("0");
	       }
	  } else {
	       puts("1");

	       printf("%.9lf\n", -(double)c / b);
	  }
     } else if (d < 0) {
	  puts("0");
     } else if (d == 0) {
	  puts("1");

	  printf("%.9lf\n", -b / (2.0 * a));
     } else {
	  double x, y;

	  puts("2");

	  x = (-b + sqrt(d)) / (2 * a);
	  y = (-b - sqrt(d)) / (2 * a);

	  if (x > y) {
	       double tmp = x;
	       x = y;
	       y = tmp;
	  }

	  printf("%.9lf\n%.9lf\n", x, y);
     }

     return 0;
}