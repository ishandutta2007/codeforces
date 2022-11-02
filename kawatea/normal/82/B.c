#include <stdio.h>

int a[20000][200] = {0};

int main()
{
     int n, x, i, j, k;
     int b[200] = {0};

     scanf("%d", &n);

     if (n == 2) {
	  scanf("%d", &k);

	  for (i = 0; i < k; i++) scanf("%d", &b[i]);

	  printf("1 %d\n", b[0]);

	  printf("%d", k - 1);
	  for (i = 1; i < k; i++) printf(" %d", b[i]);
	  puts("");

	  return 0;
     }

     for (i = 0; i < n * (n - 1) / 2; i++) {
	  scanf("%d", &k);

	  for (j = 0; j < k; j++) {
	       scanf("%d", &x);

	       a[i][x - 1] = 1;
	       b[x - 1] = 1;
	  }
     }

     for (i = 0; i < 200; i++) {
	  int p = -1, q = -1;
	  int s = 0;

	  if (b[i] == 0) continue;

	  for (j = 0; j < n * (n - 1) / 2; j++) {
	       if (a[j][i] == 1) {
		    if (p == -1) {
			 p = j;
		    } else {
			 q = j; break;
		    }
	       }
	  }

	  for (j = i; j < 200; j++) {
	       if (a[p][j] == 1 && a[q][j] == 1) s++;
	  }

	  printf("%d", s);

	  for (j = i; j < 200; j++) {
	       if (a[p][j] == 1 && a[q][j] == 1) {
		    printf(" %d", j + 1);

		    b[j] = 0;

		    for (k = p; k < n * (n - 1) / 2; k++) a[k][j] = 0;
	       }
	  }
	  puts("");
     }

     return 0;
}