#include <stdio.h>

int a[30000], b[30000], c[30000];
int n, p, q;

int dfs(int x)
{
     if (x == n) return 1;
     if (a[x] - b[p - 1] == b[1] - b[0]) {
	  b[p++] = a[x];

	  if (dfs(x + 1) == 1) return 1;

	  p--;

	  if (q >= 2 && a[x] - c[q - 1] == c[1] - c[0]) {
	       c[q++] = a[x];

	       if (dfs(x + 1) == 1) return 1;

	       q--;
	  }
     } else if (q <= 1 || a[x] - c[q - 1] == c[1] - c[0]) {
	  c[q++] = a[x];

	  if (dfs(x + 1) == 1) return 1;

	  q--;
     }

     return 0;
}

int main()
{
     int i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     b[0] = a[0];
     b[1] = a[1];
     p = 2;

     if (dfs(2) == 1) {
	  if (q == 0) c[q++] = b[--p];

	  for (i = 0; i < p; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", b[i]);
	  }
	  puts("");

	  for (i = 0; i < q; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", c[i]);
	  }
	  puts("");

	  return 0;
     }

     b[0] = a[0];
     b[1] = a[2];
     c[0] = a[1];
     p = 2;
     q = 1;

     if (dfs(3) == 1) {
	  for (i = 0; i < p; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", b[i]);
	  }
	  puts("");

	  for (i = 0; i < q; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", c[i]);
	  }
	  puts("");

	  return 0;
     }

     b[0] = a[1];
     b[1] = a[2];
     c[0] = a[0];
     p = 2;
     q = 1;

     if (dfs(3) == 1) {
	  for (i = 0; i < p; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", b[i]);
	  }
	  puts("");

	  for (i = 0; i < q; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", c[i]);
	  }
	  puts("");

	  return 0;
     }

     puts("No solution");

     return 0;
}