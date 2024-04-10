#include <stdio.h>

int a[100000];
int b[100000][2];
int c[100000];

int main()
{
     int n, m, sum = 0, p = 0, i;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     if (n == m) {
	  for (i = 0; i < n; i++) puts("Truth");

	  return 0;
     }

     for (i = 0; i < n; i++) {
	  if (a[i] > 0) {
	       b[a[i] - 1][0]++;
	  } else {
	       b[-a[i] - 1][1]++;

	       sum++;
	  }
     }

     for (i = 0; i < n; i++) {
	  int x = b[i][0] + sum - b[i][1];

	  if (x == m) {
	       c[i] = 1;

	       p++;
	  }
     }

     for (i = 0; i < n; i++) {
	  if (a[i] > 0) {
	       if (c[a[i] - 1] == 1) {
		    if (p == 1) {
			 puts("Truth");
		    } else {
			 puts("Not defined");
		    }
	       } else {
		    puts("Lie");
	       }
	  } else {
	       if (c[-a[i] - 1] == 0) {
		    puts("Truth");
	       } else {
		    if (p == 1) {
			 puts("Lie");
		    } else {
			 puts("Not defined");
		    }
	       }
	  }
     }

     return 0;
}