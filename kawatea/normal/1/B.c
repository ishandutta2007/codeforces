#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, i, j;
     char s[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", s);

	  for (j = 0; ; j++) {
	       if (s[j] >= '0' && s[j] <= '9') break;
	  }

	  for (; ; j++) {
	       if (s[j] < '0' || s[j] > '9') break;
	  }

	  if (s[j] == 'C') {
	       int x, y, p = 0;
	       char c[10];

	       x = atoi(&s[1]);
	       y = atoi(&s[j + 1]);

	       while (y) {
		    int z = y % 26;

		    if (z == 0) z = 26;

		    c[p++] = z + 'A' - 1;
		    y--;
		    y /= 26;
	       }

	       for (j = p - 1; j >= 0; j--) printf("%c", c[j]);
	       printf("%d\n", x);
	  } else {
	       int x = 0, y;

	       for (j = 0; ; j++) {
		    if (s[j] >= 'A' && s[j] <= 'Z') {
			 x = x * 26 + s[j] - 'A' + 1;
		    } else {
			 break;
		    }
	       }

	       y = atoi(&s[j]);

	       printf("R%dC%d\n", y, x);
	  }
     }

     return 0;
}