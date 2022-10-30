#include <stdio.h>

int main()
{
     int n, p = 0, i;
     int a[100], b[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  if (a[i] == p + 1) {
	       b[p++] = 2001 + i;
	  }
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  if (i > 0) putchar(' ');
	  printf("%d", b[i]);
     }

     puts("");

     return 0;
}