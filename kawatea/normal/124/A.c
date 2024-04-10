#include <stdio.h>

int main()
{
     int n, a, b, sum = 0, i;

     scanf("%d %d %d", &n, &a, &b);

     for (i = a; i < n; i++) {
	  if (n - i - 1 <= b) sum++;
     }

     printf("%d\n", sum);

     return 0;
}