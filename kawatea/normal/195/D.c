#include <stdio.h>
#include <stdlib.h>

#define A int
#define B int

typedef struct {
    A first;
    B second;
} pair;

int cmp_first(A a, A b)
{
    return a - b;
}

int cmp_second(B a, B b)
{
    return a - b;
}

int cmp_pair(pair a, pair b)
{
    int x = cmp_first(a.first, b.first);
    
    if (x != 0) return x;
    
    return cmp_second(a.second, b.second);
}

pair make_pair(A first, B second)
{
    pair p;
    
    p.first = first;
    p.second = second;
    
    return p;
}

#define S pair

typedef struct _set {
    S key;
    int size;
    int height;
    struct _set *child[2];
} set;

set *rotate(set *s, int l, int r);

int cmp_set(S a, S b)
{
    return cmp_pair(a, b);
}

int empty(set *s)
{
    if (s == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int size(set *s)
{
    if (s == NULL) {
        return 0;
    } else {
        return s->size;
    }
}

int height(set *s)
{
    if (s == NULL) {
        return 0;
    } else {
        return s->height;
    }
}

set *balance(set *s)
{
    int i;
    
    for (i = 0; i < 2; i++) {
        if (height(s->child[!i]) - height(s->child[i]) < -1) {
            if (height(s->child[i]->child[!i]) - height(s->child[i]->child[i]) > 0) {
                s->child[i] = rotate(s->child[i], i, !i);
            }
            
            return rotate(s, !i, i);
        }
    }
    
    if (s != NULL) {
        if (height(s->child[0]) > height(s->child[1])) {
            s->height = height(s->child[0]) + 1;
        } else {
            s->height = height(s->child[1]) + 1;
        }
        
        s->size = size(s->child[0]) + size(s->child[1]) + 1;
    }
    
    return s;
}

set *rotate(set *s, int l, int r)
{
    set *t = s->child[r];
    
    s->child[r] = t->child[l];
    t->child[l] = balance(s);
    
    if (s != NULL) s->size = size(s->child[0]) + size(s->child[1]) + 1;
    if (t != NULL) t->size = size(t->child[0]) + size(t->child[1]) + 1;
    
    return balance(t);
}

set *insert(set *s, S key)
{
    int x;
    
    if (s == NULL) {
        set *tmp = malloc(sizeof(set));
        
        tmp->key = key;
        tmp->size = 1;
        tmp->height = 1;
        tmp->child[0] = NULL;
        tmp->child[1] = NULL;
        
        return tmp;
    }
    
    x = cmp_set(s->key, key);
    
    if (x == 0) return s;
    
    if (x > 0) {
        s->child[0] = insert(s->child[0], key);
    } else {
        s->child[1] = insert(s->child[1], key);
    }
    
    s->size++;
    
    return balance(s);
}

set *move_down(set *s, set *t)
{
    if (s == NULL) return t;
    
    s->child[1] = move_down(s->child[1], t);
    
    return balance(s);
}

set *erase(set *s, S key)
{
    int x;
    
    if (s == NULL) return NULL;
    
    x = cmp_set(s->key, key);
    
    if (x == 0) {
        set *tmp = move_down(s->child[0], s->child[1]);
        
        free(s);
        
        return tmp;
    }
    
    if (x > 0) {
        s->child[0] = erase(s->child[0], key);
    } else {
        s->child[1] = erase(s->child[1], key);
    }
    
    s->size--;
    
    return balance(s);
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, i;
    set *s = NULL;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y, g;
        
        scanf("%d %d", &x, &y);
        
        if (x == 0) continue;
        
        g = gcd(x, y);
        
        x /= g;
        y /= g;
        
        if (x < 0) {
            x *= -1;
            y *= -1;
        }
        
        s = insert(s, make_pair(x, y));
    }
    
    printf("%d\n", size(s));
    
    return 0;
}