#include <stdio.h>

int main()
{
     int n, i;
     long long x, y, a;

     scanf("%d %I64d %I64d", &n, &x, &y);

     a = y - n + 1;

     if (a > 0 && a * a + n - 1 >= x) {
	  for (i = 0; i < n - 1; i++) puts("1");
	  printf("%I64d\n", a);
     } else {
	  puts("-1");
     }

     return 0;
}