#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int w;
     int h;
     int i;
} envelope;

int cmp(const void *a, const void *b)
{
     if (((envelope *)a)->w != ((envelope *)b)->w) {
	  return ((envelope *)a)->w - ((envelope *)b)->w;
     } else {
	  return ((envelope *)a)->h - ((envelope *)b)->h;
     }
}

int main()
{
     int n, w, h, x = 0, y = 0, max = 0, i, j;
     envelope e[5001];
     int dp[5001] = {0}, p[5001], a[5001];

     scanf("%d %d %d", &n, &w, &h);

     for (i = 1; i <= n; i++) scanf("%d %d", &e[i].w, &e[i].h);

     for (i = 0; i <= n; i++) e[i].i = i;

     qsort(e + 1, n, sizeof(envelope), cmp);

     e[0].w = w; e[0].h = h;

     for (i = 1; i <= n; i++) {
	  for (j = 0; j < i; j++) {
	       if (dp[j] >= dp[i]) {
		    if (j > 0 && dp[j] == 0) continue;

		    if (e[i].w > e[j].w && e[i].h > e[j].h) {
			 dp[i] = dp[j] + 1;
			 p[i] = j;
		    }
	       }
	  }
     }

     for (i = 0; i <= n; i++) {
	  if (dp[i] > max) {
	       max = dp[i];
	       x = i;
	  }
     }

     printf("%d\n", dp[x]);

     n = dp[x];

     for (i = 0; i < n; i++) {
	  a[y++] = e[x].i;
	  x = p[x];
     }

     for (i = y - 1; i >= 0; i--) {
	  if (i < y - 1) putchar(' ');

	  printf("%d", a[i]);
     }
     puts("");

     return 0;
}