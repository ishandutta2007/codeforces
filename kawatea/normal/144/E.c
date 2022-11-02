#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
     int i;
} men;

typedef struct _priority_queue {
    men value;
    int size;
    struct _priority_queue *left;
    struct _priority_queue *right;
} priority_queue;

priority_queue *meld(priority_queue *a, priority_queue *b)
{
    priority_queue *tmp;

    if (a == NULL) return b;

    if (b == NULL) return a;

    if (a->value.y > b->value.y) {
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

priority_queue *push(priority_queue *a, men value)
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

men top(priority_queue *a)
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
     if (((men *)a)->x != ((men *)b)->x) {
	  return ((men *)a)->x - ((men *)b)->x;
     } else {
	  return ((men *)a)->y - ((men *)b)->y;
     }
}

int main()
{
     int n, m, p = 0, x = 0, i, j;
     men a[100000];
     int b[100000];
     priority_queue *q = NULL;

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  int r, c;

	  scanf("%d %d", &r, &c);

	  a[i].x = n - c;
	  a[i].y = r - 1;
	  a[i].i = i + 1;
     }

     qsort(a, m, sizeof(men), cmp);

     for (i = 0; i < n; i++) {
	  for (j = x; j < m; j++) {
	       if (a[j].x == i) {
		    q = push(q, a[j]);
	       } else {
		    break;
	       }
	  }

	  x = j;

	  while (empty(q) == 0) {
	       men c = top(q);

	       q = pop(q);

	       if (c.y >= i) {
		    b[p++] = c.i;

		    break;
	       }
	  }
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", b[i]);
     }

     return 0;
}