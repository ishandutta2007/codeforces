#include <stdio.h>
#include <string.h>

int main()
{
     int k, a, b, n, p = 0, i, j, l;
     char s[201];

     scanf("%d %d %d", &k, &a, &b);
     scanf("%s", s);

     n = strlen(s);

     for (i = a; i <= b; i++) {
	  int x = n - i * (k - 1);

	  if (x >= a && x <= b) {
	       for (j = 0; j < k - 1; j++) {
		    for (l = 0; l < i; l++) putchar(s[p++]);
		    puts("");
	       }

	       for (l = 0; l < x; l++) putchar(s[p++]);
	       puts("");

	       return 0;
	  }
     }

     puts("No solution");

     return 0;
}