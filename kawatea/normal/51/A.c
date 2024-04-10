#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, c = 0, i, j;
     int a[1000][4];
     int b[1000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  if (i > 0) scanf("%*s");

	  for (j = 0; j < 4; j++) scanf("%1d", &a[i][j]);

	  for (j = 0; j < 4; j++) {
	       int x, tmp;

	       x = a[i][0] * 1000 + a[i][1] * 100 + a[i][3] * 10 + a[i][2];

	       if (x > b[i]) b[i] = x;

	       tmp = a[i][0]; a[i][0] = a[i][1]; a[i][1] = a[i][3];
	       a[i][3] = a[i][2]; a[i][2] = tmp;
	  }
     }

     qsort(b, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  int x = b[i];

	  for (j = i; j < n; j++) {
	       if (b[i] != b[j]) break;
	  }

	  i = j - 1;
	  c++;
     }

     printf("%d\n", c);

     return 0;
}