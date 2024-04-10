#include <stdio.h>
#include <math.h>

int main()
{
     int n, p, m = 2, i;
     double b, c;
     int a[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     if (n == 1 || (n == 2 && a[0] != 0)) {
	  puts("0");

	  return 0;
     }

     if (n == 2 && a[0] == 0) {
	  if (a[1] == 0) {
	       puts("0");
	  } else {
	       puts("1");
	  }

	  return 0;
     }

     if (a[0] == 0) {
	  if (a[1] == 0) {
	       p = 0;

	       for (i = 0; i < n; i++) {
		    if (a[i] != 0) p++;
	       }

	       if (p <= 1) {
		    printf("%d\n", p);

		    return 0;
	       }
	  }
	  if (a[2] == 0) {
	       p = 0;

	       for (i = 0; i < n; i++) {
		    if (a[i] != 0) p++;
	       }

	       if (p <= 1) {
		    printf("%d\n", p);

		    return 0;
	       }
	  }
     } else {
	  c = a[0];
	  b = (double)a[1] / a[0];
	  p = 0;

	  for (i = 1; i < n; i++) {
	       if (fabs(a[i] - c * b) > 1e-6) {
		    p++;
	       } else {
		    c = a[i];
	       }
	  }

	  if (p < m) m = p;

	  c = a[0];
	  b = (double)a[2] / a[0];
	  p = 1;

	  for (i = 2; i < n; i++) {
	       if (fabs(a[i] - c * b) > 1e-6) {
		    p++;
	       } else {
		    c = a[i];
	       }
	  }

	  if (p < m) m = p;
     }

     if (a[1] == 0) {
	  if (a[2] == 0) {
	       for (i = 3; i < n; i++) {
		    if (a[i] != 0) break;
	       }

	       if (i == n) {
		    if (m > 1) m = 1;

		    printf("%d\n", m);

		    return 0;
	       }
	  }
     } else {
	  c = a[1];
	  b = (double)a[2] / a[1];
	  p = 1;

	  for (i = 2; i < n; i++) {
	       if (fabs(a[i] - c * b) > 1e-6) {
		    p++;
	       } else {
		    c = a[i];
	       }
	  }

	  if (p < m) m = p;
     }

     printf("%d\n", m);

     return 0;
}