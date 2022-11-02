#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, sum = 0, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  sum += a[i];
     }

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (sum % 2 == 1) break;

	  if (a[i] % 2 == 1) sum -= a[i];
     }

     if (sum % 2 == 0) {
	  puts("0");
     } else {
	  printf("%d\n", sum);
     }

     return 0;
}