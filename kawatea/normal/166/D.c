#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int c;
     int s;
     int i;
} shoes;

typedef struct {
     int d;
     int l;
     int i;
} customer;

int cmp(const void *a, const void *b)
{
     return ((shoes *)a)->s - ((shoes *)b)->s;
}

int cmp2(const void *a, const void *b)
{
     if (((customer *)a)->l != ((customer *)b)->l) {
	  return ((customer *)a)->l - ((customer *)b)->l;
     } else {
	  return ((customer *)b)->d - ((customer *)a)->d;
     }
}

shoes a[100000];
customer b[100000];
customer c[100000];
int d[100000][2];

int main()
{
     int n, m, p = 0, q = 0, i, j;
     long long sum = 0;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &a[i].c, &a[i].s);

	  a[i].i = i + 1;
     }

     scanf("%d", &m);

     for (i = 0; i < m; i++) {
	  scanf("%d %d", &b[i].d, &b[i].l);

	  b[i].i = i + 1;
     }

     qsort(a, n, sizeof(shoes), cmp);
     qsort(b, m, sizeof(customer), cmp2);

     j = 0;

     for (i = 0; i < m; i++) {
	  int k = i;

	  while (j < n && a[j].s < b[i].l) j++;

	  if (j == n) break;

	  while (k < m && b[k].l == b[i].l) k++;

	  k--;

	  if (k > i && j < n - 1 && a[j].s + 1 == a[j + 1].s && a[j].c <= b[i].d && a[j + 1].c <= b[i].d && (a[j].c <= b[i + 1].d || a[j + 1].c <= b[i + 1].d)) {
	       c[q].d = b[i].d;
	       c[q].l = b[i].l;
	       c[q++].i = b[i].i;

	       c[q].d = b[i + 1].d;
	       c[q].l = b[i + 1].l;
	       c[q++].i = b[i + 1].i;
	  } else {
	       c[q].d = b[i].d;
	       c[q].l = b[i].l;
	       c[q++].i = b[i].i;
	  }

	  i = k;
     }

     m = q;

     j = 0;

     for (i = 0; i < m; i++) {
	  while (j < n && a[j].s < c[i].l) j++;

	  if (j == n) break;

	  if (a[j].s > c[i].l + 1) continue;

	  if (a[j].s == c[i].l + 1 || j == n - 1 || a[j + 1].s > c[i].l + 1) {
	       if (a[j].c <= c[i].d) {
		    sum += a[j].c;

		    d[p][0] = c[i].i;
		    d[p++][1] = a[j++].i;
	       }
	  } else {
	       if (a[j].c > c[i].d || a[j + 1].c > c[i].d) {
		    if (a[j].c <= c[i].d) {
			 sum += a[j].c;

			 d[p][0] = c[i].i;
			 d[p++][1] = a[j++].i;
		    } else if (a[j + 1].c <= c[i].d) {
			 sum += a[j + 1].c;

			 d[p][0] = c[i].i;
			 d[p++][1] = a[j + 1].i;

			 j += 2;
		    }
	       } else if (i == m - 1 || c[i + 1].l > c[i].l + 1) {
		    if (a[j].c < a[j + 1].c) {
			 sum += a[j + 1].c;

			 d[p][0] = c[i].i;
			 d[p++][1] = a[j + 1].i;
		    } else {
			 sum += a[j].c;

			 d[p][0] = c[i].i;
			 d[p++][1] = a[j].i;
		    }

		    j += 2;
	       } else if (c[i + 1].l == c[i].l) {
		    sum += a[j].c + a[j + 1].c;

		    d[p][0] = c[i].i;
		    d[p + 1][0] = c[i + 1].i;

		    if (a[j].c <= c[i + 1].d) {
			 d[p][1] = a[j + 1].i;
			 d[p + 1][1] = a[j].i;
		    } else {
			 d[p][1] = a[j].i;
			 d[p + 1][1] = a[j + 1].i;
		    }

		    p += 2;
		    j += 2;
	       } else {
		    int k = 1, l;

		    while (i + k < m && j + k < n - 1 && a[j + k].s == c[i + k].l && a[j + k + 1].s == c[i + k].l + 1 && a[j + k].c <= c[i + k].d && a[j + k + 1].c <= c[i + k].d) k++;

		    k--;

		    if (i + k < m - 1 && c[i + k].l == c[i + k + 1].l) {
			 sum += a[j + k].c + a[j + k + 1].c;

			 d[p][0] = c[i + k].i;
			 d[p + 1][0] = c[i + k + 1].i;

			 if (a[j + k].c <= c[i + k + 1].d) {
			      d[p][1] = a[j + k + 1].i;
			      d[p + 1][1] = a[j + k].i;
			 } else {
			      d[p][1] = a[j + k].i;
			      d[p + 1][1] = a[j + k + 1].i;
			 }

			 p += 2;

			 for (l = 0; l < k; l++) {
			      sum += a[j + l].c;

			      d[p][0] = c[i + l].i;
			      d[p++][1] = a[j + l].i;
			 }

			 j += k + 2;
		    } else if (i + k < m - 1 && c[i + k].l + 1 == c[i + k + 1].l && a[j + k + 1].c <= c[i + k + 1].d) {
			 for (l = 0; l <= k + 1; l++) {
			      sum += a[j + l].c;

			      d[p][0] = c[i + l].i;
			      d[p++][1] = a[j + l].i;
			 }

			 j += k + 2;
		    } else {
			 int x = a[j + k + 1].c;
			 int y = k + 1;

			 for (l = 0; l <= k; l++) {
			      if (a[j + l].c < x) {
				   x = a[j + l].c;
				   y = l;
			      }
			 }

			 for (q = 0; q < y; q++) {
			      sum += a[j + q].c;

			      d[p][0] = c[i + q].i;
			      d[p++][1] = a[j + q].i;
			 }

			 for (; q <= k; q++) {
			      sum += a[j + q + 1].c;

			      d[p][0] = c[i + q].i;
			      d[p++][1] = a[j + q + 1].i;
			 }

			 j += k + 2;
		    }
	       }
	  }
     }

     printf("%I64d\n", sum);
     printf("%d\n", p);

     for (i = 0; i < p; i++) printf("%d %d\n", d[i][0], d[i][1]);

     return 0;
}