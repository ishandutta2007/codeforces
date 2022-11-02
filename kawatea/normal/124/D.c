#include <stdio.h>
#include <stdlib.h>

long long maximum(long long a, long long b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     long long a, b, x1, y1, x2, y2, p, q, r, s;

     scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a, &b, &x1, &y1, &x2, &y2);

     a *= 2;
     b *= 2;

     p = (x1 + y1) / a;
     q = (x2 + y2) / a;

     if (x1 + y1 < 0) p--;
     if (x2 + y2 < 0) q--;

     r = (x1 - y1) / b;
     s = (x2 - y2) / b;

     if (x1 - y1 < 0) r--;
     if (x2 - y2 < 0) s--;

     printf("%I64d\n", maximum(abs(p - q), abs(r - s)));

     return 0;
}