#include <stdio.h>

int main()
{
     int n, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%1d", &a[i]);

     if (n % 2 == 0) {
	  for (i = 0; i < n; i++) {
	       if (i > 0 && i % 2 == 0) putchar('-');
	       printf("%d", a[i]);
	  }
	  puts("");
     } else {
	  for (i = 0; i < n - 3; i++) {
	       if (i > 0 && i % 2 == 0) putchar('-');
	       printf("%d", a[i]);
	  }
	  if (i > 0) putchar('-');
	  for (; i < n; i++) printf("%d", a[i]);
	  puts("");
     }

     return 0;
}