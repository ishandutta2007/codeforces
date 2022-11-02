#include <stdio.h>

int main()
{
     int n, a = 0, b = 0, p, q, i;
     int t[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &t[i]);

     p = 0, q = n - 1;

     for (i = 0; i < n; i++) {
	  if (a <= b) {
	       a += t[p++];
	  } else {
	       b += t[q--];
	  }
     }

     printf("%d %d\n", p, n - q - 1);

     return 0;
}