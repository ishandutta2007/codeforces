#include <stdio.h>

int main()
{
     int l, b, f, n, p = 0, i, j, k;
     int a[100][3];

     scanf("%d %d %d", &l, &b, &f);
     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  if (x == 1) {
	       if (p == 0) {
		    if (y <= l) {
			 a[p][0] = 0;
			 a[p][1] = y;
			 a[p++][2] = i + 1;

			 puts("0");
		    } else {
			 puts("-1");
		    }
	       } else {
		    if (y + f <= a[0][0]) {
			 for (j = p; j > 0; j--) {
			      a[j][0] = a[j - 1][0];
			      a[j][1] = a[j - 1][1];
			      a[j][2] = a[j - 1][2];
			 }

			 a[0][0] = 0;
			 a[0][1] = y;
			 a[0][2] = i + 1;

			 p++;

			 puts("0");

			 continue;
		    }

		    for (j = 0; j < p - 1; j++) {
			 if (a[j][0] + a[j][1] + b + y + f <= a[j + 1][0]) {
			      for (k = p; k > j + 1; k--) {
				   a[k][0] = a[k - 1][0];
				   a[k][1] = a[k - 1][1];
				   a[k][2] = a[k - 1][2];
			      }

			      a[j + 1][0] = a[j][0] + a[j][1] + b;
			      a[j + 1][1] = y;
			      a[j + 1][2] = i + 1;

			      p++;

			      printf("%d\n", a[j + 1][0]);

			      break;
			 }
		    }

		    if (j >= p - 1) {
			 if (a[p - 1][0] + a[p - 1][1] + b + y <= l) {
			      a[p][0] = a[p - 1][0] + a[p - 1][1] + b;
			      a[p][1] = y;
			      a[p++][2] = i + 1;

			      printf("%d\n", a[p - 1][0]);
			 } else {
			      puts("-1");
			 }
		    }
	       }
	  } else {
	       for (j = 0; j < p; j++) {
		    if (a[j][2] == y) {
			 for (k = j; k < p; k++) {
			      a[k][0] = a[k + 1][0];
			      a[k][1] = a[k + 1][1];
			      a[k][2] = a[k + 1][2];
			 }

			 p--;
		    }
	       }
	  }
     }

     return 0;
}