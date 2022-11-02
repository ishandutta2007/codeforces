#include <stdio.h>

int main()
{
     int n, max, min, sum = 0, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     max = min = a[0];

     for (i = 1; i < n; i++) {
	  if (a[i] > max) max = a[i];
	  if (a[i] < min) min = a[i];
     }

     for (i = 0; i < n; i++) {
	  if (a[i] == max) break;
     }

     sum += i;

     for (i = n - 1; i >= 0; i--) {
	  if (a[i] == min) break;
     }

     sum += n - i - 1;

     if (sum > n - 2) sum--;

     printf("%d\n", sum);

     return 0;
}