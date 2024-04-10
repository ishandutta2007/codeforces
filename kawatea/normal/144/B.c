#include <stdio.h>

int dist(int x1, int y1, int x2, int y2)
{
     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int xa, ya, xb, yb, n, sum = 0, i, j;
     int a[1000][3];

     scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

     for (i = min(xa, xb); i <= max(xa, xb); i++) {
	  for (j = 0; j < n; j++) {
	       if (dist(i, ya, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) break;
	  }

	  if (j == n) sum++;

	  for (j = 0; j < n; j++) {
	       if (dist(i, yb, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) break;
	  }

	  if (j == n) sum++;
     }

     for (i = min(ya, yb); i <= max(ya, yb); i++) {
	  for (j = 0; j < n; j++) {
	       if (dist(xa, i, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) break;
	  }

	  if (j == n) sum++;

	  for (j = 0; j < n; j++) {
	       if (dist(xb, i, a[j][0], a[j][1]) <= a[j][2] * a[j][2]) break;
	  }

	  if (j == n) sum++;
     }

     for (i = 0; i < n; i++) {
	  if (dist(xa, ya, a[i][0], a[i][1]) <= a[i][2] * a[i][2]) break;
     }

     if (i == n) sum--;

     for (i = 0; i < n; i++) {
	  if (dist(xb, ya, a[i][0], a[i][1]) <= a[i][2] * a[i][2]) break;
     }

     if (i == n) sum--;

     for (i = 0; i < n; i++) {
	  if (dist(xa, yb, a[i][0], a[i][1]) <= a[i][2] * a[i][2]) break;
     }

     if (i == n) sum--;

     for (i = 0; i < n; i++) {
	  if (dist(xb, yb, a[i][0], a[i][1]) <= a[i][2] * a[i][2]) break;
     }

     if (i == n) sum--;

     printf("%d\n", sum);

     return 0;
}