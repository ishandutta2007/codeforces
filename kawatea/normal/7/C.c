#include <stdio.h>
#include <stdlib.h>

long long extgcd(long long a, long long b, long long *x, long long *y)
{
     long long d = a;

     if (a < b) return extgcd(b, a, y, x);

     if (b != 0) {
	  d = extgcd(b, a % b, y, x);
	  *y -= (a / b) * (*x);
     } else {
	  *x = 1;
	  *y = 0;
     }

     return d;
}

int main()
{
     int a, b, c;
     long long x = 0, y = 0;

     scanf("%d %d %d", &a, &b, &c);

     if (a == 0) {
	  if (abs(c) % abs(b) == 0) {
	       printf("%d %d\n", 0, -c / b);
	  } else {
	       puts("-1");
	  }
     } else if (b == 0) {
	  if (abs(c) % abs(a) == 0) {
	       printf("%d %d\n", -c / a, 0);
	  } else {
	       puts("-1");
	  }
     } else {
	  long long d = extgcd(abs(a), abs(b), &x, &y);

	  if (abs(c) % d == 0) {
	       x *= -c / d;
	       y *= -c / d;

	       if (a < 0) x *= -1;
	       if (b < 0) y *= -1;

	       printf("%I64d %I64d\n", x, y);
	  } else {
	       puts("-1");
	  }
     }

     return 0;
}