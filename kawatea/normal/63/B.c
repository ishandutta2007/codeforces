#include <stdio.h>

int main()
{
     int n, k, s = 0, i, j;
     int a[100];

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     while (a[0] < k) {
	  for (i = 0; i < n; i++) {
	       if (a[i] == k) break;
	       for (j = i + 1; j < n; j++) {
		    if (a[i] < a[j]) {
			 a[j - 1]++;
			 i = j - 1;

			 break;
		    }
	       }

	       if (j == n) {
		    a[n - 1]++;

		    break;
	       }
	  }

	  s++;
     }

     printf("%d\n", s);

     return 0;
}