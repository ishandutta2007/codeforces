#include <stdio.h>

int main()
{
     int a, b, m, i;

     scanf("%d %d %d", &a, &b, &m);

     if (b >= m - 1) {
	  puts("2");
     } else {
	  for (i = 0; i < m && i <= a; i++) {
	       int p = (long long)i * 1000000000 % m;

	       if (p > 0 && p <= m - b - 1) break;
	  }

	  if (i < m && i <= a) {
	       printf("1 %09d\n", i);
	  } else {
	       puts("2");
	  }
     }

     return 0;
}