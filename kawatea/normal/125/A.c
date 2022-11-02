#include <stdio.h>

int main()
{
     int n, a, b;

     scanf("%d", &n);

     a = n / 36;
     b = n / 3 - a * 12;

     if (n - (a * 12 + b) * 3 == 2) b++;

     if (b == 12) {
	  a++;
	  b = 0;
     }

     printf("%d %d\n", a, b);

     return 0;
}