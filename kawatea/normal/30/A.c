#include <stdio.h>

int main()
{
     int a, b, n, f = 1, i, j;

     scanf("%d %d %d", &a, &b, &n);

     if (a < 0) {
	  f *= -1;
	  a *= -1;
     }

     if (b < 0) {
	  f *= -1;
	  b *= -1;
     }

     if (f == -1 && n % 2 == 0 && b > 0) {
	  puts("No solution");

	  return 0;
     }

     if (a == 0) {
	  if (b == 0) {
	       puts("1");
	  } else {
	       puts("No solution");
	  }

	  return 0;
     }

     if (b % a) {
	  puts("No solution");

	  return 0;
     }

     b /= a;

     for (i = 0; i <= b; i++) {
	  int x = 1;

	  for (j = 0; j < n; j++) {
	       x *= i;

	       if (x > b) break;
	  }

	  if (x == b) {
	       i *= f;

	       printf("%d\n", i);

	       return 0;
	  }
     }

     puts("No solution");

     return 0;
}