#include <stdio.h>

int main()
{
     int n, k = 0, i, j;
     int a[300], b[300], c[300];
     int d[100000][2];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);
     for (i = 0; i < n; i++) scanf("%d", &b[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (b[i] == a[j]) {
		    c[i] = j;

		    a[j] = 0;

		    break;
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 1; j < n - i; j++) {
	       if (c[j] < c[j - 1]) {
		    int tmp = c[j];
		    c[j] = c[j - 1];
		    c[j - 1] = tmp;

		    d[k][0] = j;
		    d[k++][1] = j + 1;
	       }
	  }
     }

     printf("%d\n", k);

     for (i = 0; i < k; i++) {
	  printf("%d %d\n", d[i][0], d[i][1]);
     }

     return 0;
}