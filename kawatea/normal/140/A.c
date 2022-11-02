#include <stdio.h>
#include <math.h>

int main()
{
     int n, R, r;

     scanf("%d %d %d", &n, &R, &r);

     if (r > R) {
	  puts("NO");
     } else if (r * 2 > R) {
	  if (n == 1) {
	       puts("YES");
	  } else {
	       puts("NO");
	  }
     } else {
	  if (n == 1 || sin(acos(-1) / n) + 1e-9 >= (double)r / (R - r)) {
	       puts("YES");
	  } else {
	       puts("NO");
	  }
     }

     return 0;
}