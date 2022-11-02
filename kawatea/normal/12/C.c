#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, m, p = 0, min = 0, max = 0, i, j;
     int a[100], b[100] = {0};
     char s[100][35];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < m; i++) {
	  char c[35];

	  scanf("%s", c);

	  for (j = 0; j < p; j++) {
	       if (strcmp(c, s[j]) == 0) break;
	  }

	  if (j == p) strcpy(s[p++], c);

	  b[j]++;
     }

     qsort(a, n, sizeof(int), cmp);

     qsort(b, p, sizeof(int), cmp);

     for (i = 0; i < p; i++) {
	  min += b[p - i - 1] * a[i];
	  max += b[p - i - 1] * a[n - i - 1];
     }

     printf("%d %d\n", min, max);

     return 0;
}