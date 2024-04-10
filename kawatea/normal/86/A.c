#include <stdio.h>

long long max(long long a, long long b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

long long min(long long a, long long b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

long long reverse(long long n)
{
     long long r = 0, d = 1;
     int i;

     while (n) {
	  r += (9 - n % 10) * d;
	  n /= 10;
	  d *= 10;
     }

     return r;
}

int main()
{
     int l, r, c, i;
     long long d = 1;

     scanf("%d %d", &l, &r);

     c = r;

     while (c) {
	  c /= 10;
	  d *= 10;
     }

     d /= 10;

     l = max(l, d);

     if (r < d * 5) {
	  printf("%I64d\n", (long long)r * reverse(r));
     } else if (l > d * 5) {
	  printf("%I64d\n", (long long)l * reverse(l));
     } else {
	  printf("%I64d\n", (long long)d * 5 * reverse(d * 5));
     }

     return 0;
}