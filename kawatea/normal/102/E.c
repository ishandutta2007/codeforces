#include <stdio.h>

int main()
{
     long long x1, y1, x2, y2, x3, y3, tmp, i;

     scanf("%I64d %I64d", &x1, &y1);
     scanf("%I64d %I64d", &x2, &y2);
     scanf("%I64d %I64d", &x3, &y3);

     for (i = 0; i < 4; i++) {
	  long long p = x3 * x3 + y3 * y3;

	  if (p == 0) {
	       if (x1 == x2 && y1 == y2) {
		    puts("YES");

		    return 0;
	       }
	  } else if ((x3 * (x2 - x1) + y3 * (y2 - y1)) % p == 0 && (y3 * (x2 - x1) - x3 * (y2 - y1)) % p == 0) {
	       puts("YES");

	       return 0;
	  }

	  tmp = x1;
	  x1 = y1;
	  y1 = -tmp;
     }

     puts("NO");

     return 0;
}