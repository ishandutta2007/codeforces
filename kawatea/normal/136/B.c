#include <stdio.h>

int main()
{
     int a, b = 0, c, i;
     int p[3][20] = {0};

     scanf("%d %d", &a, &c);

     i = 0;

     while (a) {
	  p[0][i++] = a % 3;
	  a /= 3;
     }

     i = 0;

     while (c) {
	  p[1][i++] = c % 3;
	  c /= 3;
     }

     for (i = 0; i < 20; i++) {
	  p[2][i] = (p[1][i] - p[0][i] + 3) % 3;
     }

     for (i = 19; i >= 0; i--) {
	  b *= 3;
	  b += p[2][i];
     }

     printf("%d\n", b);

     return 0;
}