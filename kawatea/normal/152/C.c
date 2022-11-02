#include <stdio.h>

int main()
{
     int n, m, mod = 1000000007, i, j;
     long long sum = 1;
     int a[100][26] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  char s[101];

	  scanf("%s", s);

	  for (j = 0; j < m; j++) a[j][s[j] - 'A'] = 1;
     }

     for (i = 0; i < m; i++) {
	  int c = 0;

	  for (j = 0; j < 26; j++) c += a[i][j];

	  sum = sum * c % mod;
     }

     printf("%d\n", (int)sum);

     return 0;
}