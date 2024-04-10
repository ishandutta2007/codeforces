#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int maximum(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int minimum(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int a[2000];
     int p = 0, q = 1, x = 1, i, j;
     int pl, pr, vl, vr, k;
     long long c = 0, d;

     a[0] = 0;

     for (i = 0; i < 9; i++) {
	  for (j = p; j < q; j++) {
	       a[x++] = a[j] * 10 + 4;
	       a[x++] = a[j] * 10 + 7;
	  }

	  p = q; q = x;
     }

     qsort(a, x, sizeof(int), cmp);

     a[x] = 1000000001;

     scanf("%d %d %d %d %d", &pl, &pr, &vl, &vr, &k);

     d = (long long)(pr - pl + 1) * (vr - vl + 1);

     for (i = 1; i <= x - k; i++) {
	  if (pl <= a[i] && vr >= a[i + k - 1]) {
	       int s1 = minimum(a[i], pr);
	       int s2 = maximum(a[i - 1] + 1, pl);
	       int t1 = maximum(a[i + k - 1], vl);
	       int t2 = minimum(a[i + k] - 1, vr);

	       if (s1 - s2 >= 0 && t2 - t1 >= 0) {
		    c += (long long)(s1 - s2 + 1) * (t2 - t1 + 1);
	       }
	  }
	  if (vl <= a[i] && pr >= a[i + k - 1]) {
	       int s1 = minimum(a[i], vr);
	       int s2 = maximum(a[i - 1] + 1, vl);
	       int t1 = maximum(a[i + k - 1], pl);
	       int t2 = minimum(a[i + k] - 1, pr);

	       if (s1 - s2 >= 0 && t2 - t1 >= 0) {
		    c += (long long)(s1 - s2 + 1) * (t2 - t1 + 1);
	       }
	  }
     }

     if (k == 1) {
	  for (i = 1; i < x; i++) {
	       if (pl <= a[i] && pr >= a[i] && vl <= a[i] && vr >= a[i]) c--;
	  }
     }

     printf("%.20lf\n", (double)c / d);

     return 0;
}