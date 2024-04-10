#include <stdio.h>

int main()
{
     int n, l = 0, r = 0, i, j;
     int a[1000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  if (a[i] != i + 1) {
	       for (j = i + 1; j < n; j++) {
		    if (a[j] == i + 1) break;
	       }

	       l = i + 1; r = j + 1;

	       for (j = l - 1; j < r; j++) {
		    if (a[j] != r + l - j - 1) break;
	       }

	       if (j < r) {
		    puts("0 0");

		    return 0;
	       }

	       for (j = r; j < n; j++) {
		    if (a[j] != j + 1) {
			 puts("0 0");

			 return 0;
		    }
	       }

	       printf("%d %d\n", l, r);

	       return 0;
	  }
     }

     puts("0 0");

     return 0;
}