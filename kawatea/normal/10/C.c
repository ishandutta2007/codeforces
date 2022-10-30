#include <stdio.h>

int main()
{
     int n, i, j;
     long long sum = 0;
     int a[9] = {0};

     scanf("%d", &n);

     for (i = 0; i < 9; i++) {
	  a[(i + 1) % 9] = n / 9;

	  if (n % 9 > i) a[(i + 1) % 9]++;
     }

     for (i = 0; i < 9; i++) {
	  for (j = 0; j < 9; j++) {
	       sum += (long long)a[i] * a[j] * a[i * j % 9];
	  }
     }

     for (i = 1; i <= n; i++) sum -= n / i;

     printf("%I64d\n", sum);

     return 0;
}