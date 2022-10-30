#include <stdio.h>

int main()
{
     int n, a, b, c, sum = 0, i, j;
     int d[10001] = {0};

     scanf("%d %d %d %d", &n, &a, &b, &c);

     for (i = 0; i <= a / 2; i++) d[i]++;

     for (i = a / 2; i >= 0; i--) {
	  for (j = 1; j <= b && i + j <= n; j++) {
	       d[i + j]++;
	  }
     }

     for (i = 0; i <= c; i++) {
	  if (n - i * 2 >= 0) sum += d[n - i * 2];
     }

     printf("%d\n", sum);

     return 0;
}