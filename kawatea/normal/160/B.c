#include <stdio.h>

int main()
{
     int n, f = 0, i, j;
     int a[10][2] = {0};
     int b[10][2] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%1d", &x);

	  a[x][0]++;
	  a[x][1]++;
     }

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%1d", &x);

	  b[x][0]++;
	  b[x][1]++;
     }

     for (i = 9; i >= 0; i--) {
	  if (a[i][0] > 0) {
	       for (j = i - 1; j >= 0; j--) {
		    if (b[j][0] < a[i][0]) {
			 a[i][0] -= b[j][0];

			 b[j][0] = 0;
		    } else {
			 b[j][0] -= a[i][0];

			 a[i][0] = 0;

			 break;
		    }
	       }

	       if (a[i][0] > 0) {
		    f = 1;

		    break;
	       }
	  }
     }

     if (f == 0) {
	  puts("YES");

	  return 0;
     }

     for (i = 9; i >= 0; i--) {
	  if (b[i][1] > 0) {
	       for (j = i - 1; j >= 0; j--) {
		    if (a[j][1] < b[i][1]) {
			 b[i][1] -= a[j][1];

			 a[j][1] = 0;
		    } else {
			 a[j][1] -= b[i][1];

			 b[i][1] = 0;

			 break;
		    }
	       }

	       if (b[i][1] > 0) {
		    puts("NO");

		    return 0;
	       }
	  }
     }

     puts("YES");

     return 0;
}