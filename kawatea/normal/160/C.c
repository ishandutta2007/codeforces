#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, i, j;
     long long k;
     int a[100000];

     scanf("%d %I64d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     k--;

     for (i = k / n; i >= 0; i--) {
	  if (a[i] != a[k / n]) break;
     }

     for (j = k / n; j < n; j++) {
	  if (a[j] != a[k / n]) break;
     }

     i++;
     j--;

     k -= (long long)i * n;

     printf("%d %d\n", a[i], a[k / (j - i + 1) % n]);

     return 0;
}