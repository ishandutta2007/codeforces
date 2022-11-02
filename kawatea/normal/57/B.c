#include <stdio.h>

int main()
{
     int n, m, k, i, j;
     int a[100000], b[100000], c[100000];
     long long sum = 0;

     scanf("%d %d %d", &n, &m, &k);

     for (i = 0; i < m; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);

     for (i = 0; i < k; i++) {
	  int x;

	  scanf("%d", &x);

	  for (j = 0; j < m; j++) {
	       if (a[j] <= x && b[j] >= x) sum += c[j] + x - a[j];
	  }
     }

     printf("%I64d\n", sum);

     return 0;
}