#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, m, res = 0, i, j, k, l;
     char s[25][26];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       int x = m - 1;

	       for (k = i; k < n; k++) {
		    for (l = j; l <= x; l++) {
			 if (s[k][l] == '1') break;
		    }

		    x = l - 1;
	 
		    if (x >= j) res = max(res, (x - j + 1) * 2 + (k - i + 1) * 2);
	       }
	  }
     }

     printf("%d\n", res);

     return 0;
}