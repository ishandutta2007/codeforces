#include <stdio.h>

int main()
{
     int n, i, j, k;
     int a[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 3; i <= n; i++) {
	  if (n % i > 0) continue;

	  for (j = 0; j < n / i; j++) {
	       for (k = 0; j + n / i * k < n; k++) {
		    if (a[j + n / i * k] == 0) break;
	       }

	       if (j + n / i * k >= n) {
		    puts("YES");

		    return 0;
	       }
	  }
     }

     puts("NO");

     return 0;
}