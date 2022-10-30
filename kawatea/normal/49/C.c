#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     for (i = 0; i < n - 1; i++) {
	  printf("%d ", i + 2);
     }

     puts("1");

     return 0;
}