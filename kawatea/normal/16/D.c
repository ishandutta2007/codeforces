#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, p = 1, q = 0, i;
     char s[100][100];
     int a[100][2], f[100] = {0};

     scanf("%d%*c", &n);

     for (i = 0; i < n; i++) fgets(s[i], 100, stdin);

     for (i = 0; i < n; i++) {
	  char c;

	  sscanf(&s[i][1], "%d:%d %c", &a[i][0], &a[i][1], &c);

	  if (a[i][0] == 12) a[i][0] = 0;

	  if (c == 'p') f[i] = 1;
     }

     for (i = 0; i < n - 1; i++) {
	  if (f[i] < f[i + 1]) {
	       q = 0;

	       continue;
	  }
	  if (f[i] > f[i + 1]) {
	       p++;
	       q = 0;

	       continue;
	  }

	  if (a[i][0] < a[i + 1][0]) {
	       q = 0;

	       continue;
	  }
	  if (a[i][0] > a[i + 1][0]) {
	       p++;
	       q = 0;

	       continue;
	  }

	  if (a[i][1] > a[i + 1][1]) {
	       p++;
	       q = 0;

	       continue;
	  }
	  if (a[i][1] == a[i + 1][1]) {
	       q++;

	       if (q == 10) {
		    p++;
		    q = 0;
	       }
	  }
     }

     printf("%d\n", p);

     return 0;
}