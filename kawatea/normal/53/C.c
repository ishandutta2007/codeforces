#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  if (i % 2 == 0) {
	       printf("%d", i / 2 + 1);
	  } else {
	       printf("%d", n - i / 2);
	  }
     }

     puts("");

     return 0;
}