#include <stdio.h>

int main()
{
     int n, m, k, sum = 0, i;
     int a[1000];

     for (i = 0; i < 1000; i++) a[i] = 10000000;

     scanf("%d %d %d", &n, &m, &k);

     for (i = 0; i < n; i++) {
	  int r, c;

	  scanf("%d %d", &r, &c);

	  if (a[r - 1] > c) a[r - 1] = c;
     }

     for (i = 0; i < 1000; i++) {
	  if (a[i] < 10000000) sum += a[i];
     }

     if (sum > k) {
	  printf("%d\n", k);
     } else {
	  printf("%d\n", sum);
     }

     return 0;
}