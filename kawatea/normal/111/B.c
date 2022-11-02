#include <stdio.h>

int main()
{
     int n, x, y, i, j;
     int a[100001];

     for (i = 0; i <= 100000; i++) a[i] = -1;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int c = 0, p = 0;
	  int b[1000];

	  scanf("%d %d", &x, &y);

	  for (j = 1; j * j <= x; j++) {
	       if (x % j == 0) {
		    b[p++] = j;
		    b[p++] = x / j;
	       }
	  }

	  for (j = 0; j < p; j++) {
	       if (a[b[j]] == -1 || a[b[j]] < i - y) c++;

	       a[b[j]] = i;
	  }

	  printf("%d\n", c);
     }

     return 0;
}