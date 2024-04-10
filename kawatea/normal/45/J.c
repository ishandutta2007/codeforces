#include <stdio.h>

int main()
{
     int n, m, i, j;
     int a[100][100];

     scanf("%d %d", &n, &m);

     if (n == 1 && m == 1) {
	  puts("1");

	  return 0;
     } else if (n == 1) {
	  if (m <= 3) {
	       puts("-1");

	       return 0;
	  } else if (m % 2 == 0) {
	       for (i = 0; i < m / 2; i++) {
		    a[0][i] = (i + 1) * 2;
		    a[0][m - i - 1] = m - i * 2 - 1;
	       }
	  } else {
	       for (i = 0; i < m / 2; i++) {
		    a[0][i] = (i + 1) * 2;
		    a[0][m - i - 1] = (i + 1) * 2 + 1;
	       }
	       a[0][m / 2] = 1;
	  }
     } else if (m == 1) {
	  if (n <= 3) {
	       puts("-1");

	       return 0;
	  } else if (n % 2 == 0) {
	       for (i = 0; i < n / 2; i++) {
		    a[i][0] = (i + 1) * 2;
		    a[n - i - 1][0] = n - i * 2 - 1;
	       }
	  } else {
	       for (i = 0; i < n / 2; i++) {
		    a[i][0] = (i + 1) * 2;
		    a[n - i - 1][0] = (i + 1) * 2 + 1;
	       }
	       a[n / 2][0] = 1;
	  }
     } else if (n == 2 && m == 2) {
	  puts("-1");

	  return 0;
     } else if (n == 2 && m == 3) {
	  a[0][0] = 1;
	  a[0][1] = 5;
	  a[0][2] = 3;
	  a[1][0] = 4;
	  a[1][1] = 2;
	  a[1][2] = 6;
     } else {
	  int p = 1;

	  for (i = 0; i < n; i++) {
	       for (j = i % 2; j < m; j += 2) {
		    a[i][j] = p++;
	       }
	  }

	  for (i = 0; i < n; i++) {
	       for (j = (i + 1) % 2; j < m; j += 2) {
		    a[i][j] = p++;
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (j > 0) putchar(' ');

	       printf("%d", a[i][j]);
	  }
	  puts("");
     }

     return 0;
}