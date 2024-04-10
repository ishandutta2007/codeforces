#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, k, i, j, l;
     int d[300][300];
     long long sum = 0;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       scanf("%d", &d[i][j]);
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       for (l = 0; l < n; l++) {
		    d[j][l] = min(d[j][l], d[j][i] + d[i][l]);
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = i + 1; j < n; j++) {
	       sum += d[i][j];
	  }
     }

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  int a, b, c;

	  scanf("%d %d %d", &a, &b, &c);

	  if (d[a - 1][b - 1] > c) {
	       sum -= d[a - 1][b - 1] - c;

	       d[a - 1][b - 1] = d[b - 1][a - 1] = c;

	       for (j = 0; j < n; j++) {
		    for (l = j + 1; l < n; l++) {
			 int p = d[j][a - 1] + c + d[b - 1][l];
			 int q = d[j][b - 1] + c + d[a - 1][l];

			 p = min(p, q);

			 if (d[j][l] > p) {
			      sum -= d[j][l] - p;
			      d[j][l] = d[l][j] = p;
			 }
		    }
	       }
	  }

	  if (i > 0) putchar(' ');

	  printf("%I64d", sum);
     }
     puts("");

     return 0;
}