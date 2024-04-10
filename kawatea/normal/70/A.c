#include <stdio.h>

int main()
{
     int n, a = 1, i;

     scanf("%d", &n);

     for (i = 1; i < n; i++) {
	  a *= 3;

	  a %= 1000003;
     }

     printf("%d\n", a);

     return 0;
}