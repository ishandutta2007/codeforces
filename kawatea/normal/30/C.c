#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
     int x;
     int y;
     int t;
     double p;
} target;

int cmp(const void *a, const void *b)
{
     return ((target *)a)->t - ((target *)b)->t;
}

double maximum(double a, double b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

double dist(int x1, int y1, int x2, int y2)
{
     return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
     int n, i, j;
     target a[1000];
     double dp[1000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d %d %lf", &a[i].x, &a[i].y, &a[i].t, &a[i].p);
     }

     qsort(a, n, sizeof(target), cmp);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < i; j++) {
	       if (dist(a[i].x, a[i].y, a[j].x, a[j].y) <= a[i].t - a[j].t) {
		    dp[i] = maximum(dp[i], dp[j] + a[i].p);
	       }
	  }

	  dp[i] = maximum(dp[i], a[i].p);
     }

     for (i = 0; i < n; i++) dp[n - 1] = maximum(dp[n - 1], dp[i]);

     printf("%.9lf\n", dp[n - 1]);

     return 0;
}