#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
     int i;
} node;

typedef struct {
     int l;
     int r;
     long long s;
     int n;
} range;

int a[100000][2][2], f[100000];
range b[100000], v[100000];
int p, q, r;
int s[200000], t[100000];
long long rmq[200000][2];

int cmp(const void *a, const void *b)
{
     if (((node *)a)->x != ((node *)b)->x) {
	  return ((node *)a)->x - ((node *)b)->x;
     } else {
	  return ((node *)a)->y - ((node *)b)->y;
     }
}

int cmp2(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int binary_search(int x)
{
     int l = -1, r = q, m = (l + r) / 2;

     while (r - l > 1) {
	  if (v[m].l <= x) {
	       l = m;
	       m = (l + r) / 2;
	  } else {
	       r = m;
	       m = (l + r) / 2;
	  }
     }

     return l;
}

int binary_search2(int x)
{
     int l = -1, r = q, m = (l + r) / 2;

     while (r - l > 1) {
	  if (v[m].r >= x) {
	       r = m;
	       m = (l + r) / 2;
	  } else {
	       l = m;
	       m = (l + r) / 2;
	  }
     }

     return r;
}

int minimum(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int maximum(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

void make(int x, int l1, int r1, int l2, int r2, int key)
{
     if (f[a[x][0][1]] == 0) {
	  b[p].l = key;
	  b[p].r = r1;
	  b[p++].s = a[x][0][0];

	  s[r++] = key;
	  s[r++] = r1;;

	  if (l1 > minimum(key, l2)) {
	       b[p].l = minimum(key, l2);
	       b[p].r = l1;
	       b[p++].s = a[x][0][0];

	       s[r++] = minimum(key, l2);
	       s[r++] = l1;
	  }
     } else {
	  make(a[x][0][1], l1, key, minimum(key, l2), r1, a[x][0][0]);
     }

     if (f[a[x][1][1]] == 0) {
	  b[p].l = l1;
	  b[p].r = key;
	  b[p++].s = a[x][1][0];

	  s[r++] = l1;
	  s[r++] = key;

	  if (r1 < maximum(key, r2)) {
	       b[p].l = r1;
	       b[p].r = maximum(key, r2);
	       b[p++].s = a[x][1][0];

	       s[r++] = r1;
	       s[r++] = maximum(key, r2);
	  }
     } else {
	  make(a[x][1][1], key, r1, l1, maximum(key, r2), a[x][1][0]);
     }
}

void add(int a, int b, int k, int x, int l, int r)
{
     if (r <= a || b <= l) return;

     if (a <= l && b >= r) {
	  rmq[k][0] += x;
	  rmq[k][1]++;
     } else {
	  add(a, b, k * 2 + 1, x, l, (l + r) / 2);
	  add(a, b, k * 2 + 2, x, (l + r) / 2, r);
     }
}

int main()
{
     int n, k, i, j;
     node c[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &c[i].x, &c[i].y);

	  c[i].i = i + 1;
     }

     qsort(c, n, sizeof(node), cmp);

     for (i = 1; i < n; i += 2) {
	  f[c[i].x] = 1;

	  a[c[i].x][0][0] = c[i].y;
	  a[c[i].x][0][1] = c[i].i;
	  a[c[i].x][1][0] = c[i + 1].y;
	  a[c[i].x][1][1] = c[i + 1].i;
     }

     make(c[0].i, 0, 1e9, 1e9, 0, c[0].y);

     s[r++] = 0;
     s[r++] = 1e9;

     qsort(s, r, sizeof(int), cmp2);

     for (i = 0; i < r; i++) {
	  t[q++] = s[i];

	  for (j = i + 1; j < r; j++) {
	       if (s[i] != s[j]) break;
	  }

	  i = j - 1;
     }

     for (i = 0; i < q - 1; i++) {
	  v[i].l = t[i];
	  v[i].r = t[i + 1];
	  v[i].s = v[i].n = 0;
     }

     q--;

     n = 1;

     while (n < q) n *= 2;

     for (i = 0; i < p; i++) {
	  int l = binary_search(b[i].l);
	  int r = binary_search2(b[i].r);

	  add(l, r + 1, 0, b[i].s, 0, n);
     }

     for (i = 0; i < q; i++) {
	  j = i + n - 1;

	  while (j > 0) {
	       v[i].s += rmq[j][0];
	       v[i].n += rmq[j][1];

	       j = (j - 1) / 2;
	  }
     }

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  int x, y;

	  scanf("%d", &x);

	  y = binary_search2(x);

	  printf("%.9lf\n", (double)v[y].s / v[y].n);
     }

     return 0;
}