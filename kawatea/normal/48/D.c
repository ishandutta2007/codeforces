#include <stdio.h>

int main()
{
     int n, i;
     int a[100000];
     int b[100000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  b[a[i] - 1]++;
     }

     for (i = 0; i < 99999; i++) {
	  if (b[i] < b[i + 1]) {
	       puts("-1");

	       return 0;
	  }
     }

     printf("%d\n", b[0]);

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", b[a[i] - 1]--);
     }
     puts("");

     return 0;
}