#include <stdio.h>

int main()
{
     long long n;
     int x = 0, i;

     scanf("%I64d", &n);

     while (n) {
      int m = n % 10;

      if (m == 4 || m == 7) x++;

      n /= 10;
     }

     if (x == 4 || x == 7) {
      puts("YES");
     } else {
      puts("NO");
     }

     return 0;
}