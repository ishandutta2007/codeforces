#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int b;
} ball;

typedef struct _priority_queue {
     ball value;
     int size;
     struct _priority_queue *left;
     struct _priority_queue *right;
} priority_queue;

priority_queue *meld(priority_queue *a, priority_queue *b)
{
    priority_queue *tmp;

    if (a == NULL) return b;

    if (b == NULL) return a;

    if (a->value.a < b->value.a) {
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

priority_queue *push(priority_queue *a, ball v)
{
    priority_queue *tmp = malloc(sizeof(priority_queue));
    int x;

    if (a == NULL) {
	x = 0;
    } else {
	x = a->size;
    }

    tmp->value = v;
    tmp->left = NULL;
    tmp->right = NULL;

    tmp = meld(tmp, a);

    tmp->size = x + 1;

    return tmp;
}

priority_queue *pop(priority_queue *a)
{
    priority_queue *tmp;
    int x = a->size;

    tmp = meld(a->left, a->right);

    if (x > 1) tmp->size = x - 1;

    return tmp;
}

ball top(priority_queue *a)
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

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, num = 0, i, j;
     int r[100000];
     int s[50000][3];
     priority_queue *p = NULL;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &r[i]);

     qsort(r, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  ball b;

	  for (j = i; j < n; j++) {
	       if (r[i] != r[j]) break;
	  }

	  b.a = j - i;
	  b.b = r[i];

	  p = push(p, b);

	  i = j - 1;
     }

     while (empty(p) == 0 && p->size >= 3) {
	  ball a, b, c;
	  int x[3];

	  a = top(p);
	  p = pop(p);
	  b = top(p);
	  p = pop(p);
	  c = top(p);
	  p = pop(p);

	  x[0] = a.b;
	  x[1] = b.b;
	  x[2] = c.b;

	  qsort(x, 3, sizeof(int), cmp);

	  s[num][0] = x[2];
	  s[num][1] = x[1];
	  s[num++][2] = x[0];

	  a.a--;
	  b.a--;
	  c.a--;

	  if (a.a > 0) p = push(p, a);
	  if (b.a > 0) p = push(p, b);
	  if (c.a > 0) p = push(p, c);
     }

     printf("%d\n", num);

     for (i = 0; i < num; i++) {
	  printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
     }

     return 0;
}