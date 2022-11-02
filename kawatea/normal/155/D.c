#include <stdio.h>
#include <stdlib.h>

#define S int
#define T int

typedef struct _map {
     S key;
     T value;
     int size;
     int height;
     struct _map *child[2];
} map;

map *rotate(map *m, int l, int r);

int cmp_map(S a, S b)
{
     return a - b;
}

int empty(map *m)
{
     if (m == NULL) {
	  return 1;
     } else {
	  return 0;
     }
}

int size(map *m)
{
     if (m == NULL) {
	  return 0;
     } else {
	  return m->size;
     }
}

int height(map *m)
{
     if (m == NULL) {
	  return 0;
     } else {
	  return m->height;
     }
}

map *balance(map *m)
{
     int i;

     for (i = 0; i < 2; i++) {
	  if (height(m->child[!i]) - height(m->child[i]) < -1) {
	       if (height(m->child[i]->child[!i]) - height(m->child[i]->child[i]) > 0) {
		    m->child[i] = rotate(m->child[i], i, !i);
	       }

	       return rotate(m, !i, i);
	  }
     }

     if (m != NULL) {
	  if (height(m->child[0]) > height(m->child[1])) {
	       m->height = height(m->child[0]) + 1;
	  } else {
	       m->height = height(m->child[1]) + 1;
	  }

	  m->size = size(m->child[0]) + size(m->child[1]) + 1;
     }

     return m;
}

map *rotate(map *m, int l, int r)
{
     map *t = m->child[r];

     m->child[r] = t->child[l];
     t->child[l] = balance(m);

     if (m != NULL) m->size = size(m->child[0]) + size(m->child[1]) + 1;
     if (t != NULL) t->size = size(t->child[0]) + size(t->child[1]) + 1;

     return balance(t);
}

map *insert(map *m, S key, T value)
{
     int x;

     if (m == NULL) {
	  map *tmp = malloc(sizeof(map));

	  tmp->key = key;
	  tmp->value = value;
	  tmp->size = 1;
	  tmp->height = 1;
	  tmp->child[0] = NULL;
	  tmp->child[1] = NULL;

	  return tmp;
     }

     x = cmp_map(m->key, key);

     if (x == 0) {
	  m->value = value;

	  return m;
     }

     if (x > 0) {
	  m->child[0] = insert(m->child[0], key, value);
     } else {
	  m->child[1] = insert(m->child[1], key, value);
     }

     m->size++;

     return balance(m);
}

map *move_down(map *m, map *t)
{
     if (m == NULL) return t;

     m->child[1] = move_down(m->child[1], t);

     return balance(m);
}

map *erase(map *m, S key)
{
     int x;

     if (m == NULL) return NULL;

     x = cmp_map(m->key, key);

     if (x == 0) {
	  map *tmp = move_down(m->child[0], m->child[1]);

	  free(m);

	  return tmp;
     }

     if (x > 0) {
	  m->child[0] = erase(m->child[0], key);
     } else {
	  m->child[1] = erase(m->child[1], key);
     }

     m->size--;

     return balance(m);
}

T find(map *m, S key)
{
     int x;

     if (m == NULL) return 0;

     x = cmp_map(m->key, key);

     if (x == 0) return m->value;

     if (x > 0) {
	  return find(m->child[0], key);
     } else {
	  return find(m->child[1], key);
     }
}

map *rank(map *m, int n)
{
     int t = size(m->child[0]);

     if (n < t) {
	  return rank(m->child[0], n);
     } else if (n == t) {
	  return m;
     } else {
	  return rank(m->child[1], n - t - 1);
     }
}

int a[100001];
int b[100001][10];
int p[100001];

int main()
{
     int n, m, i, j;
     map *mp = NULL;

     scanf("%d %d", &n, &m);

     for (i = 2; i <= n; i++) {
	  int x = i;

	  for (j = 2; j * j <= x; j++) {
	       if (x % j == 0) {
		    while (x % j == 0) x /= j;

		    b[i][p[i]++] = j;
	       }
	  }

	  if (x > 1) {
	       b[i][p[i]++] = x;
	  }
     }

     for (i = 0; i < m; i++) {
	  char s[2];
	  int x;

	  scanf("%s %d", s, &x);

	  if (s[0] == '+') {
	       if (a[x] == 1) {
		    puts("Already on");
	       } else {
		    for (j = 0; j < p[x]; j++) {
			 int y = find(mp, b[x][j]);

			 if (y > 0) {
			      printf("Conflict with %d\n", y);

			      break;
			 }
		    }

		    if (j == p[x]) {
			 puts("Success");

			 for (j = 0; j < p[x]; j++) {
			      mp = insert(mp, b[x][j], x);
			 }

			 a[x] = 1;
		    }
	       }
	  } else {
	       if (a[x] == 1) {
		    puts("Success");

		    for (j = 0; j < p[x]; j++) {
			 mp = erase(mp, b[x][j]);
		    }

		    a[x] = 0;
	       } else {
		    puts("Already off");
	       }
	  }
     }

     return 0;
}