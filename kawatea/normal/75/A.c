#include <stdio.h>

int main()
{
     int a, b, c, d = 0, e = 0, f = 0, x = 1;

     scanf("%d %d", &a, &b);

     c = a + b;

     while (a) {
	  int p = a % 10;

	  a /= 10;

	  if (p == 0) continue;

	  d += p * x;

	  x *= 10;
     }

     x = 1;

     while (b) {
	  int p = b % 10;

	  b /= 10;

	  if (p == 0) continue;

	  e += p * x;

	  x *= 10;
     }

     x = 1;

     while (c) {
	  int p = c % 10;

	  c /= 10;

	  if (p == 0) continue;

	  f += p * x;
	  x *= 10;
     }

     if (d + e == f) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}