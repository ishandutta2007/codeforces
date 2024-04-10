#include <stdio.h>

int max(int a, int b, int c)
{
     int m = a;

     if (b > m) m = b;
     if (c > m) m = c;

     return m;
}

int main()
{
     int n, x, i;
     int a[3] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &x);

	  a[x - 1]++;
     }

     printf("%d\n", a[0] + a[1] + a[2] - max(a[0], a[1], a[2]));

     return 0;
}