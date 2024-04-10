#include <stdio.h>

int main()
{
     int n, m, sum = 0, i, j;
     int a[100][100];
     int b[100] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       scanf("%1d", &a[i][j]);
	  }
     }

     for (i = 0; i < m; i++) {
	  int max = 0;

	  for (j = 0; j < n; j++) {
	       if (a[j][i] > max) max = a[j][i];
	  }

	  for (j = 0; j < n; j++) {
	       if (a[j][i] == max) b[j] = 1;
	  }
     }

     for (i = 0; i < n; i++) sum += b[i];

     printf("%d\n", sum);

     return 0;
}