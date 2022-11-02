#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, i;
     int a[3] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%d", &x);

	  a[x % 3]++;
     }

     printf("%d\n", a[0] / 2 + min(a[1], a[2]));

     return 0;
}