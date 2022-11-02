#include <stdio.h>
#include <string.h>

int main()
{
     int n, m, min, i, j;
     char s1[2001], s2[2001];

     scanf("%s", s1);
     scanf("%s", s2);

     n = strlen(s1);
     m = strlen(s2);

     min = m;

     for (i = 0; i < n; i++) {
	  int c = 0;

	  for (j = 0; j < n - i && j < m; j++) {
	       if (s1[i + j] != s2[j]) c++;
	  }

	  if (m > n - i) c += m - n + i;

	  if (c < min) min = c;
     }

     for (i = 0; i < m; i++) {
	  int c = 0;

	  for (j = 0; j < m - i && j < n; j++) {
	       if (s1[j] != s2[i + j]) c++;
	  }

	  c += i;

	  if (n + i < m) c += m - n - i;

	  if (c < min) min = c;
     }

     printf("%d\n", min);

     return 0;
}