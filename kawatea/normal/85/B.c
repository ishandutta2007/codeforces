#include <stdio.h>

int main()
{
     int k1, k2, k3, n, i;
     int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
     long long t1, t2, t3, max = 0;
     long long a[100000], p1[100000], p2[100000], p3[100000];

     scanf("%d %d %d", &k1, &k2, &k3);
     scanf("%I64d %I64d %I64d", &t1, &t2, &t3);
     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%I64d", &a[i]);

     for (i = 0; i < n; i++) {
	  long long m = 0, z = a[i];


	  if (y1 - x1 < k1) {
	       p1[y1++] = a[i];

	       m += t1;

	       z = a[i] + t1;
	  } else {
	       if (p1[x1] + t1 > a[i]) {
		    p1[y1++] = p1[x1] + t1;

		    m += p1[x1] + 2 * t1 - a[i];

		    a[i] = p1[x1++] + t1;

		    z = a[i] + t1;
	       } else {
		    p1[y1++] = a[i];

		    x1++;

		    m += t1;

		    z = a[i] + t1;
	       }
	  }

	  if (y2 - x2 < k2) {
	       p2[y2++] = z;

	       m += t2;

	       z += t2;
	  } else {
	       if (p2[x2] + t2 > z) {
		    p2[y2++] = p2[x2] + t2;

		    m += p2[x2] + 2 * t2 - z;

		    z = p2[x2++] + t2;
	       } else {
		    p2[y2++] = z;

		    x2++;

		    m += t2;

		    z += t2;
	       }
	  }

	  if (y3 - x3 < k3) {
	       p3[y3++] = z;

	       m += t3;
	  } else {
	       if (p3[x3] + t3 > z) {
		    p3[y3++] = p3[x3] + t3;

		    m += p3[x3++] + 2 * t3 - z;
	       } else {
		    p3[y3++] = z;

		    x3++;

		    m += t3;
	       }
	  }

	  if (m > max) max = m;
     }

     printf("%I64d\n", max);

     return 0;
}