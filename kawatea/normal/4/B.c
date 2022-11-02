#include <stdio.h>

int main()
{
     int d, sum, p = 0, q = 0, i;
     int a[30][2];

     scanf("%d %d", &d, &sum);

     for (i = 0; i < d; i++) {
	  scanf("%d %d", &a[i][0], &a[i][1]);

	  p += a[i][0];
	  q += a[i][1];
     }

     if (p > sum || q < sum) {
	  puts("NO");
     } else {
	  puts("YES");

	  for (i = 0; i < d; i++) {
	       if (i > 0) putchar(' ');

	       if (q > sum) {
		    if (a[i][1] - a[i][0] <= q - sum) {
			 printf("%d", a[i][0]);
			 q -= a[i][1] - a[i][0];
		    } else {
			 printf("%d", a[i][1] + sum - q);
			 q = sum;
		    }
	       } else {
		    printf("%d", a[i][1]);
	       }
	  }
	  puts("");
     }

     return 0;
}