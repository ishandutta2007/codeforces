#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int i;
} album;

int cmp(const void *a, const void *b)
{
     return ((album *)b)->a - ((album *)a)->a;
}

int main()
{
     int n, m, f = -1, p = 0, sum = 0, i;
     album a[40];
     int b[1000];

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  scanf("%d", &a[i].a);

	  a[i].i = i;

	  sum += a[i].a;
     }

     qsort(a, m, sizeof(album), cmp);

     if (sum < n || sum - a[0].a < (n + 1) / 2 || (n % 2 == 1 && m == 2)) {
	  puts("-1");

	  return 0;
     }

     for (i = 0; i < n; i++) {
	  qsort(a, m, sizeof(album), cmp);

	  if (a[0].i == f) {
	       b[p++] = a[1].i + 1;

	       a[1].a--;

	       f = a[1].i;
	  } else {
	       b[p++] = a[0].i + 1;

	       a[0].a--;

	       f = a[0].i;
	  }
     }

     if (b[0] == b[p - 1]) {
	  qsort(a, m, sizeof(album), cmp);

	  for (i = 0; i < m; i++) {
	       if (a[i].i + 1 != b[0] && a[i].i + 1 != b[p - 2] && a[i].a > 0) {
		    b[p - 1] = a[i].i + 1;

		    break;
	       }
	  }

	  if (i == m) {
	       for (i = 1; i < n - 1; i++) {
		    if (b[i] != b[0] && b[i - 1] != b[0] && (b[i + 1] != b[0] || i == n - 2)) {
			 int tmp = b[i];
			 b[i] = b[p - 1];
			 b[p - 1] = tmp;

			 break;
		    }
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", b[i]);
     }
     puts("");

     return 0;
}