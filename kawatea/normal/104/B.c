#include <stdio.h>

int main()
{
     int n, i;
     int a[100];
     long long sum = 0;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < n; i++) {
	  sum += a[i] + (long long)(a[i] - 1) * i;
     }

     printf("%I64d\n", sum);

     return 0;
}