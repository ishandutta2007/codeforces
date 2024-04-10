#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
     int t;
     int i;
} ramp;

typedef struct {
     int a;
     int b;
     int c;
     int d;
} tuple;

typedef struct _priority_queue {
     tuple value;
     int size;
     struct _priority_queue *left;
     struct _priority_queue *right;
} priority_queue;

ramp a[100002];
int f[100002];
int b[100002][2];
int p;

tuple make_tuple(int a, int b, int c, int d)
{
     tuple t;

     t.a = a;
     t.b = b;
     t.c = c;
     t.d = d;

     return t;
}

int cmp(const void *a, const void *b)
{
     if (((ramp *)a)->x != ((ramp *)b)->x) {
	  return ((ramp *)a)->x - ((ramp *)b)->x;
     } else {
	  return ((ramp *)a)->i - ((ramp *)b)->i;
     }
}

priority_queue *meld(priority_queue *a, priority_queue *b)
{
     priority_queue *tmp;

     if (a == NULL) return b;

     if (b == NULL) return a;

     if (a->value.a > b->value.a) {
	  tmp = a;
	  a = b;
	  b = tmp;
     }

     a->right = meld(a->right, b);

     tmp = a->left;
     a->left = a->right;
     a->right = tmp;

     return a;
}

priority_queue *push(priority_queue *a, tuple value)
{
     priority_queue *tmp = malloc(sizeof(priority_queue));
     int x;

     if (a == NULL) {
	  x = 1;
     } else {
	  x = a->size + 1;
     }

     tmp->value = value;
     tmp->left = NULL;
     tmp->right = NULL;

     tmp = meld(tmp, a);

     tmp->size = x;

     return tmp;
}

priority_queue *pop(priority_queue *a)
{
     priority_queue *tmp;
     int x = a->size - 1;

     tmp = meld(a->left, a->right);

     if (tmp != NULL) tmp->size = x;

     return tmp;
}

tuple top(priority_queue *a)
{
     return a->value;
}

int empty(priority_queue *a)
{
     if (a == NULL) {
	  return 1;
     } else {
	  return 0;
     }
}

int lower_bound(int x)
{
     int l = -1, r = p, m = (l + r) / 2;

     while (r - l > 1) {
	  if (a[m].x >= x) {
	       r = m;
	       m = (l + r) / 2;
	  } else {
	       l = m;
	       m = (l + r) / 2;
	  }
     }

     return r;
}

int main()
{
     int n, l, i;
     priority_queue *q = NULL;

     scanf("%d %d", &n, &l);

     for (i = 0; i < n; i++) {
	  int x, y, z, w;

	  scanf("%d %d %d %d", &x, &y, &z, &w);

	  if (x >= w && y > z) {
	       a[p].x = x - w;
	       a[p].y = x + y;
	       a[p].t = z + w;
	       a[p++].i = i + 1;
	  }
     }

     a[p].x = 0;
     a[p++].i = 0;
     a[p++].x = l;

     qsort(a, p, sizeof(ramp), cmp);

     q = push(q, make_tuple(a[1].x, 1, 0, 0));

     f[0] = 1;
     b[0][0] = -1;

     while (1) {
	  int m;
	  tuple t = top(q);

	  q = pop(q);

	  if (t.b == p - 1) {
	       int c = 0, x = t.c;
	       int v[100000];

	       printf("%d\n", t.a);

	       if (t.d == 1) v[c++] = a[t.c].i;

	       while (b[x][0] != -1) {
		    if (b[x][1] == 1) v[c++] = a[b[x][0]].i;

		    x = b[x][0];
	       }

	       printf("%d\n", c);

	       for (i = c - 1; i >= 0; i--) {
		    if (i < c - 1) putchar(' ');

		    printf("%d", v[i]);
	       }

	       puts("");

	       break;
	  }

	  if (f[t.b] == 1) continue;

	  f[t.b] = 1;
	  b[t.b][0] = t.c;
	  b[t.b][1] = t.d;

	  if (f[t.b - 1] == 0) q = push(q, make_tuple(t.a + a[t.b].x - a[t.b - 1].x, t.b - 1, t.b, 0));

	  if (f[t.b + 1] == 0) q = push(q, make_tuple(t.a + a[t.b + 1].x - a[t.b].x, t.b + 1, t.b, 0));

	  m = lower_bound(a[t.b].y);

	  if (f[m] == 0) q = push(q, make_tuple(t.a + a[t.b].t + a[m].x - a[t.b].y, m, t.b, 1));

	  if (f[m - 1] == 0) q = push(q, make_tuple(t.a + a[t.b].t + a[t.b].y - a[m - 1].x, m - 1, t.b, 1));
     }

     return 0;
}