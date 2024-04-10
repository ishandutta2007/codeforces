#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int i;
} array;

int c[200000][2];
int p;

int cmp(const void *a, const void *b)
{
     return ((array *)a)->x - ((array *)b)->x;
}

int lucky(int n)
{
     while (n) {
	  if (n % 10 != 4 && n % 10 != 7) return 0;

	  n /= 10;
     }

     return 1;
}

int main()
{
     int n, num = -1, tmp, i;
     int a[100000], d[100000], e[100000];
     array b[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  b[i].x = a[i];

	  b[i].i = i;

	  if (lucky(a[i]) == 1) num = i;
     }

     qsort(b, n, sizeof(array), cmp);

     for (i = 0; i < n; i++) {
	  d[b[i].i] = i;
	  e[i] = b[i].i;
     }

     for (i = 0; i < n; i++) {
	  if (a[i] != b[i].x) break;
     }

     if (i == n) {
	  puts("0");

	  return 0;
     }

     if (num == -1) {
	  puts("-1");
	  
	  return 0;
     }

     for (i = 0; i < n; i++) {
	  int x = e[i], y = num;

	  if (x == i) continue;

	  if (a[i] != a[num]) {
	       tmp = a[i];
	       a[i] = a[num];
	       a[num] = tmp;

	       c[p][0] = i + 1;
	       c[p++][1] = num + 1;

	       e[d[i]] = num;
	       e[d[num]] = i;

	       tmp = d[i];
	       d[i] = d[num];
	       d[num] = tmp;

	       y = i;
	  }

	  if (x != num && a[i] != a[x]) {
	       tmp = a[i];
	       a[i] = a[x];
	       a[x] = tmp;

	       c[p][0] = i + 1;
	       c[p++][1] = x + 1;

	       e[d[i]] = x;
	       e[d[x]] = i;

	       tmp = d[i];
	       d[i] = d[x];
	       d[x] = tmp;

	       y = x;
	  }

	  num = y;
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) printf("%d %d\n", c[i][0], c[i][1]);

     return 0;
}