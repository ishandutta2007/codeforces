#include <stdio.h>

int main()
{
     int n, m, i, j;

     scanf("%d %d", &n, &m);

     for (i = n + 1; i <= m; i++) {
	  for (j = 2; j < i; j++) {
	       if (i % j == 0) break;
	  }

	  if (j == i) {
	       if (i == m) {
		    puts("YES");
	       } else {
		    puts("NO");
	       }

	       break;
	  }
     }

     if (i > m) puts("NO");

     return 0;
}