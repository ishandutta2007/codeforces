#include <stdio.h>

int main()
{
     int n, m, min = 10000000, i, j, k;
     int a[100];
     int b[100][100] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < m; i++) {
	  int u, v;

	  scanf("%d %d", &u, &v);

	  b[u - 1][v - 1] = b[v - 1][u - 1] = 1;
     }

     for (i = 0; i < n; i++) {
	  for (j = i + 1; j < n; j++) {
	       if (b[i][j] == 1) {
		    for (k = 0; k < n; k++) {
			 if (b[i][k] == 1 && b[j][k] == 1) {
			      int s = a[i] + a[j] + a[k];

			      if (s < min) min = s;
			 }
		    }
	       }
	  }
     }

     if (min < 10000000) {
	  printf("%d\n", min);
     } else {
	  puts("-1");
     }

     return 0;
}