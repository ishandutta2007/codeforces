#include <stdio.h>

int main()
{
     int n, x, a = 1000, b = 1000, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &x);

	  if (x < a) {
	       b = a; a = x;
	  } else if (x != a && x < b) {
	       b = x;
	  }
     }

     if (b == 1000) {
	  puts("NO");
     } else {
	  printf("%d\n", b);
     }

     return 0;
}