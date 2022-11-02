#include <stdio.h>

int main()
{
     int n, x, p = 0, q = 0, r = 0, sum = 0, i;

     scanf("%d %d", &n, &x);

     for (i = 0; i < n; i++) {
	  int y;

	  scanf("%d", &y);

	  if (y < x) {
	       p++;
	  } else if (y > x) {
	       q++;
	  } else {
	       r++;
	  }
     }

     n++;

     if (r == 0) {
	  n++;
	  r++;
	  sum++;
     }

     if (n / 2 > p + r) {
	  while (n / 2 > p + r) {
	       n++;
	       p++;
	       sum++;
	  }
     } else if (p >= n / 2) {
	  while (p >= n / 2) {
	       n++;
	       q++;
	       sum++;
	  }
     }

     printf("%d\n", sum);

     return 0;
}