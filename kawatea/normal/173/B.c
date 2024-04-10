#include <stdio.h>
#include <stdlib.h>

#define A int
#define B int
#define C int

typedef struct {
     A first;
     B second;
     C third;
} tuple;

int cmp_first(A a, A b)
{
     return a - b;
}

int cmp_second(B a, B b)
{
     return a - b;
}

int cmp_third(C a, C b)
{
     return a - b;
}

int cmp_tuple(tuple a, tuple b)
{
     int x = cmp_first(a.first, b.first);

     if (x != 0) return x;

     x = cmp_second(a.second, b.second);

     if (x != 0) return x;

     return cmp_third(a.third, b.third);
}

tuple make_tuple(A first, B second, C third)
{
     tuple t;

     t.first = first;
     t.second = second;
     t.third = third;

     return t;
}

#define P tuple

typedef struct _priority_queue {
    P value;
    int size;
    struct _priority_queue *left;
    struct _priority_queue *right;
} priority_queue;

int cmp_queue(P a, P b)
{
     return cmp_tuple(a, b);
}

priority_queue *meld(priority_queue *a, priority_queue *b)
{
    priority_queue *tmp;

    if (a == NULL) return b;

    if (b == NULL) return a;

    if (cmp_queue(a->value, b->value) > 0) {
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

priority_queue *push(priority_queue *a, P value)
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

    free(a);

    return tmp;
}

P top(priority_queue *a)
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

char s[1000][1001];
int a[1000][1000], b[1000][1000];
int c[1000], d[1000];
int e[1000], f[1000];

int main()
{
     int n, m, i, j;
     priority_queue *q = NULL;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       if (s[i][j] == '#') {
		    a[i][c[i]++] = j;
		    b[j][d[j]++] = i;
	       }
	  }
     }

     q = push(q, make_tuple(0, 0, -1));

     while (!empty(q)) {
	  tuple t = top(q);

	  q = pop(q);

	  if (t.second == -1) {
	       if (f[t.third] == 1) continue;

	       f[t.third] = 1;

	       for (i = 0; i < d[t.third]; i++) {
		    if (e[b[t.third][i]] == 0) {
			 q = push(q, make_tuple(t.first + 1, b[t.third][i], -1));		    }
	       }
	  } else if (t.third == -1) {
	       if (e[t.second] == 1) continue;

	       e[t.second] = 1;

	       if (t.second == n - 1) {
		    printf("%d\n", t.first);

		    return 0;
	       }

	       for (i = 0; i < c[t.second]; i++) {
		    if (f[a[t.second][i]] == 0) {
			 q = push(q, make_tuple(t.first + 1, -1, a[t.second][i]));
		    }
	       }
	  }
     }

     puts("-1");

     return 0;
}