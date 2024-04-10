#include <stdio.h>

int main()
{
     int a, b, n, p = 0, i, j;
     int c[10];

     scanf("%d %d", &a, &b);

     if (a < b) {
	  printf("%d\n", b);

	  return 0;
     }

     n = b;

     while (n) {
	  c[p++] = n % 10;
	  n /= 10;
     }

     for (i = a + 1; ; i++) {
	  int d[10];
	  int q = 0, r = i;

	  while (r) {
	       if (r % 10 == 4 || r % 10 == 7) d[q++] = r % 10;
	       r /= 10;
	  }

	  if (p != q) continue;

	  for (j = 0; j < p; j++) {
	       if (c[j] != d[j]) break;
	  }

	  if (j == p) {
	       printf("%d\n", i);

	       return 0;
	  }
     }

     return 0;
}