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
     int n, m;

     scanf("%d %d", &n, &m);

     if (n > m) {
	  int tmp = n;
	  n = m;
	  m = tmp;
     }

     if (n == 1) {
	  printf("%d\n", m);

	  return 0;
     }

     if (n == 2) {
	  printf("%d\n", m / 4 * 4 + min(m % 4, 2) * 2);

	  return 0;
     }

     printf("%d\n", (n * m + 1) / 2);

     return 0;
}