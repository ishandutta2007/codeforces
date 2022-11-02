#include <stdio.h>

int main()
{
     int n, k, c, p = 0, sum = 0, i;
     int a[366] = {0};

     scanf("%d %d", &n, &k);

     scanf("%d", &c);

     for (i = 0; i < c; i++) {
	  int x;

	  scanf("%d", &x);

	  a[x] = 1;
     }

     for (i = 1; i <= n; i++) {
	  if (a[i] == 1 || p + k == i) {
	       sum++;
	       p = i;
	  }
     }

     printf("%d\n", sum);

     return 0;
}