#include <stdio.h>

int main()
{
     int n, p = 0, i;
     long long sum = 0, x = 0, ans = 0;
     int a[100000], b[100000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  sum += a[i];
     }

     for (i = 0; i < n - 1; i++) {
	  x += a[i];

	  if (x * 3 == sum) b[i] = 1;
	  if (x * 3 == sum * 2) p++;
     }

     x = 0;

     for (i = 0; i < n - 2; i++) {
	  x += a[i];

	  if (x * 3 == sum * 2) p--;

	  if (b[i] == 1) ans += p;
     }

     printf("%I64d\n", ans);

     return 0;
}