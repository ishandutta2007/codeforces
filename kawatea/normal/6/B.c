#include <stdio.h>

int main()
{
     int n, m, sum = 0, i, j;
     char c;
     char s[100][101];
     int a[26] = {0};

     scanf("%d %d %c", &n, &m, &c);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == c) {
		    if (i > 0 && s[i - 1][j] >= 'A' && s[i - 1][j] <= 'Z') {
			 a[s[i - 1][j] - 'A'] = 1;
		    }

		    if (i < n - 1 && s[i + 1][j] >= 'A' && s[i + 1][j] <= 'Z') {
			 a[s[i + 1][j] - 'A'] = 1;
		    }

		    if (j > 0 && s[i][j - 1] >= 'A' && s[i][j - 1] <= 'Z') {
			 a[s[i][j - 1] - 'A'] = 1;
		    }

		    if (j < m - 1 && s[i][j + 1] >= 'A' && s[i][j + 1] <= 'Z') {
			 a[s[i][j + 1] - 'A'] = 1;
		    }
	       }
	  }
     }

     a[c - 'A'] = 0;

     for (i = 0; i < 26; i++) {
	  if (a[i] == 1) sum++;
     }

     printf("%d\n", sum);

     return 0;
}