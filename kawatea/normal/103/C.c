#include <stdio.h>

int main()
{
     long long n, k, x;
     int p, i;

     scanf("%I64d %I64d %d", &n, &k, &p);

     if (n % 2 == 1 && k > 0) {
	  n--;
	  k--;
     }

     for (i = 0; i < p; i++) {
	  scanf("%I64d", &x);

	  if (x > n) {
	       putchar('X');
	  } else if (k >= n / 2) {
	       if (x % 2 == 1 && (x + 1) / 2 <= n - k) {
		    putchar('.');
	       } else {
		    putchar('X');
	       }
	  } else if ((n - k + 1) / 2 > n / 2) {
	       if (x <= n - k) {
		    putchar('.');
	       } else {
		    putchar('X');
	       }
	  } else {
	       if (x % 2 == 1 || x / 2 <= n / 2 - k) {
		    putchar('.');
	       } else {
		    putchar('X');
	       }
	  }
     }

     return 0;
}