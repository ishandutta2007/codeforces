#include <stdio.h>

int main()
{
     int n, i;
     int a[100], b[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) b[a[i] - 1] = i + 1;

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", b[i]);
     }

     puts("");

     return 0;
}