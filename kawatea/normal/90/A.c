#include <stdio.h>

int main()
{
     int n, sum = 0, i;
     int a[3];

     scanf("%d %d %d", &a[0], &a[1], &a[2]);

     n = a[0] + a[1] + a[2];

     for (i = 0; ; i++) {
	  if (a[i % 3] >= 2) {
	       a[i % 3] -= 2;
	       n -= 2;
	  } else if (a[i % 3] == 1) {
	       a[i % 3]--;
	       n--;
	  }

	  if (n == 0) break;
     }

     printf("%d\n", i + 30);

     return 0;
}