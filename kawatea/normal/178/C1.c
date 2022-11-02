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

int main()
{
    int h, m, n, i, j;
    long long sum = 0;
    int a[200000] = {0};
    map *mp = NULL;
    
    scanf("%d %d %d", &h, &m, &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        char s[2];
        
        scanf("%s %d", s, &x);
        
        if (s[0] == '+') {
            scanf("%d", &y);
            
            for (j = y; ; j = (j + m) % h) {
                if (a[j] == 0) {
                    a[j] = 1;
                    
                    mp = insert(mp, x, j);
                    
                    break;
                } else {
                    sum++;
                }
            }
        } else {
            y = find(mp, x);
            
            a[y] = 0;
            
            mp = erase(mp, x);
        }
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}