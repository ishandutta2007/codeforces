#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int t, n, m, x1, y1, x2, y2, i;

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int p, q, r, s;

	  scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);

	  p = min(x1, x2);
	  q = min(y1, y2);

	  x1 -= p; x2 -= p;
	  y1 -= q; y2 -= q;

	  r = 2 * max(x1, x2) - min(x1, x2) - n;
	  s = 2 * max(y1, y2) - min(y1, y2) - m;

	  if (r < 0) r = 0;
	  if (s < 0) s = 0;

	  if (r == 0 && s == 0) {
	       printf("%I64d\n", (long long)(max(x1, x2) - min(x1, x2)) * (max(y1, y2) - min(y1, y2)) * 2);
	  } else if (r == 0) {
	       printf("%I64d\n", (long long)s * n + (long long)(m - max(y1, y2)) * max(x1, x2) * 2);
	  } else if (s == 0) {
	       printf("%I64d\n", (long long)r * m + (long long)(n - max(x1, x2)) * max(y1, y2) * 2);
	  } else{
	       printf("%I64d\n", (long long)(max(x1, x2) - min(x1, x2)) * (max(y1, y2) - min(y1, y2)) * 2 - (long long)r * s);
	  }
     }

     return 0;
}