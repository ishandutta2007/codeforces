#include <stdio.h>

int main()
{
     int n, i;
     long long sum = 0;
     int t[21] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%d", &x);

	  t[10 + x]++;
     }

     if (t[10] > 1) {
	  sum += (long long)t[10] * (t[10] - 1) / 2;
     }

     for (i = 1; i <= 10; i++) {
	  if (t[10 + i] > 0 && t[10 - i] > 0) {
	       sum += (long long)t[10 + i] * t[10 - i];
	  }
     }

     printf("%I64d\n", sum);

     return 0;
}