#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int i;
} proficiency;

int cmp(const void *a, const void *b)
{
     return ((proficiency *)a)->a - ((proficiency *)b)->a;
}

int main()
{
     int n, k, q, m, x = 0, c = 0, i, j;
     proficiency p[100];
     int b[100][100];
     int f[100] = {0};
     double m1 = 1e9, m2 = 0;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) {
	  scanf("%d", &p[i].a);
	  p[i].i = i;
     }

     scanf("%d", &q);

     for (i = 0; i < q; i++) {
	  int d = 0;

	  m = 0;

	  for (j = 0; j < n / k; j++) {
	       scanf("%d", &b[i][j]);

	       m += p[b[i][j] - 1].a;

	       if (f[b[i][j] - 1] == 0) d = 1;

	       f[b[i][j] - 1] = 1;
	  }

	  if (d == 1) c++;

	  if ((double)m / (n / k) < m1) m1 = (double)m / (n / k);
	  if ((double)m / (n / k) > m2) m2 = (double)m / (n / k);
     }

     qsort(p, n, sizeof(proficiency), cmp);

     m = 0;

     for (i = 0; i < n; i++) {
	  if (f[p[i].i] == 0) {
	       m += p[i].a;
	       x++;

	       if (x == n / k) break;
	  }
     }

     if (x < n / k || c >= k) {
	  printf("%.9lf %.9lf\n", m1, m2);
     } else {
	  if ((double)m / x < m1) m1 = (double)m / x;

	  m = 0; x = 0;

	  for (i = n - 1; i >= 0; i--) {
	       if (f[p[i].i] == 0) {
		    m += p[i].a;
		    x++;

		    if (x == n / k) break;
	       }
	  }

	  if ((double)m / x > m2) m2 = (double)m / x;

	  printf("%.9lf %.9lf\n", m1, m2);
     }

     return 0;
}