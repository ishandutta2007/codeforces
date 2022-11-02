#include <stdio.h>

int main()
{
     int t, m, x = 1, i, j, k;
     int a[101] = {0};
     int b[101] = {0};

     scanf("%d %d", &t, &m);

     for (i = 0; i < t; i++) {
	  char s[15];

	  scanf("%s", s);

	  if (s[0] == 'a') {
	       int n, f = 0;

	       scanf("%d", &n);

	       for (j = 1; j + n <= m + 1; j++) {
		    for (k = j; k < j + n; k++) {
			 if (a[k] > 0) break;
		    }

		    if (k == j + n) {
			 for (k = j; k < j + n; k++) {
			      a[k] = x;
			 }

			 b[x]++;
			 f = 1;

			 printf("%d\n", x++);

			 break;
		    }
	       }

	       if (f == 0) puts("NULL");
	  } else if (s[0] == 'e') {
	       int n;

	       scanf("%d", &n);

	       if (n <= 0 || n > 100 || b[n] == 0) {
		    puts("ILLEGAL_ERASE_ARGUMENT");
	       } else {
		    for (j = 1; j <= m; j++) {
			 if (a[j] == n) a[j] = 0;
		    }

		    b[n] = 0;
	       }
	  } else {
	       for (j = 1; j <= m; j++) {
		    for (k = j; k <= m; k++) {
			 if (a[k] > 0) {
			      a[j] = a[k];
			      if (j != k) a[k] = 0;

			      break;
			 }
		    }
	       }
	  }
     }

     return 0;
}