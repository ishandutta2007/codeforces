#include <stdio.h>

int main()
{
     int n, i;
     long long mx, my, j;
     int a[100000][2];

     scanf("%d %I64d", &n, &j);

     scanf("%I64d %I64d", &mx, &my);

     for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);

     if (j / n % 2 == 1) {
	  for (i = 0; i < n; i++) {
	       mx *= -1;
	       mx += 2 * a[i][0];

	       my *= -1;
	       my += 2 * a[i][1];
	  }
     }

     j %= n;

     for (i = 0; i < j; i++) {
	  mx *= -1;
	  mx += 2 * a[i][0];

	  my *= -1;
	  my += 2 * a[i][1];
     }

     printf("%I64d %I64d\n", mx, my);

     return 0;
}