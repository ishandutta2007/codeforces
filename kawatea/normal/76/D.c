#include <stdio.h>

int main()
{
     long long a, b, x, y;

     scanf("%I64d %I64d", &a, &b);

     x = (a - b) / 2;
     y = a - x;

     if (x >= 0 && (x ^ y) == b) {
	  printf("%I64d %I64d\n", x, y);
     } else {
	  puts("-1");
     }

     return 0;
}