#include <stdio.h>

int main()
{
     int k, i, j, l;

     scanf("%d", &k);

     for (i = 1; i < k; i++) {
	  for (j = 1; j < k; j++) {
	       int x = i * j, p = 0;
	       int a[3];

	       while (x) {
		    a[p++] = x % k;
		    x /= k;
	       }

	       if (j > 1) {
		    for (l = 2; l >= p; l--) putchar(' ');

		    for (; l >= 0; l--) printf("%d", a[l]);
	       } else {
		    printf("%d", i);
	       }
	  }
	  puts("");
     }

     return 0;
}