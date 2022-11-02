#include <stdio.h>

int main()
{
     int max, min, n, sum = 0, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%d", &x);

	  if (i == 0) {
	       max = min = x;
	  } else {
	       if (x > max) {
		    max = x;

		    sum++;
	       } else if (x < min) {
		    min = x;

		    sum++;
	       }
	  }
     }

     printf("%d\n", sum);

     return 0;
}