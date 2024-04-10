#include <stdio.h>

int main()
{
     int a, b, c, d, e, f, m, n;

     scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

     m = a * c * e;
     n = b * d * f;

     if (c == 0 && d > 0 || a == 0 && b > 0 && d > 0) {
	  puts("Ron");
     } else if (m == 0) {
	  if (n == 0) {
	       puts("Hermione");
	  } else {
	       puts("Ron");
	  }
     } else {
	  if (m >= n) {
	       puts("Hermione");
	  } else {
	       puts("Ron");
	  }
     }

     return 0;
}