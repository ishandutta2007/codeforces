#include <stdio.h>
#include <string.h>

int main()
{
     int n, p = 0, q = 0, max = 0, i, j;
     char s[1000][33];
     char c[1000][33];
     int a[1000] = {0};
     int b[1000];
     int d[1000][2] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s %d", c[i], &b[i]);

	  for (j = 0; j < p; j++) {
	       if (strcmp(s[j], c[i]) == 0) break;
	  }

	  if (j == p) strcpy(s[p++], c[i]);

	  a[j] += b[i];
     }

     for (i = 0; i < p; i++) {
	  if (a[i] > max) max = a[i];
     }

     for (i = 0; i < p; i++) {
	  if (a[i] == max) d[q++][0] = i;
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < q; j++) {
	       if (strcmp(c[i], s[d[j][0]]) == 0) break;
	  }

	  if (j == q) continue;

	  d[j][1] += b[i];

	  if (d[j][1] >= max) break;
     }

     printf("%s\n", s[d[j][0]]);

     return 0;
}