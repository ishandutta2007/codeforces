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

#define Q pair

typedef struct _queue {
    Q value;
    int size;
    struct _queue *next;
    struct _queue *last;
} queue;

queue *push(queue *q, Q value)
{
    queue *tmp = malloc(sizeof(queue));
    
    tmp->value = value;
    tmp->next = NULL;
    tmp->last = tmp;
    
    if (q == NULL) {
        tmp->size = 1;
        
        return tmp;
    } else {
        q->size++;
        
        q->last->next = tmp;
        q->last = tmp;
        
        return q;
    }
}

queue *pop(queue *q)
{
    if (q->size == 1) {
        free(q);
        
        return NULL;
    } else {
        queue *tmp = q->next;
        
        tmp->size = q->size - 1;
        tmp->last = q->last;
        
        free(q);
        
        return tmp;
    }
}

Q front(queue *q)
{
    return q->value;
}

Q back(queue *q)
{
    return q->last->value;
}

int empty(queue *q)
{
    if (q == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int size(queue *q)
{
    if (empty(q)) {
        return 0;
    } else {
        return q->size;
    }
}

void clear(queue *q)
{
    if (q->next != NULL) clear(q->next);
    
    free(q);
}

int f[2][100000];

int main()
{
    int n, k, i;
    char s[2][100001];
    queue *q = NULL;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < 2; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        f[0][i] = f[1][i] = -1;
    }
    
    q = push(q, make_pair(0, 0));
    
    f[0][0] = 0;
    
    while (!empty(q)) {
        int x, y;
        pair p = front(q);
        
        q = pop(q);
        
        x = p.first;
        y = p.second;
        
        if (y + k >= n) {
            puts("YES");
            
            return 0;
        }
        
        if (f[x][y + 1] == -1 && s[x][y + 1] == '-') {
            q = push(q, make_pair(x, y + 1));
            
            f[x][y + 1] = f[x][y] + 1;
        }
        
        if (y - 1 >= 0 && f[x][y - 1] == -1 && f[x][y] <= y - 2 && s[x][y - 1] == '-') {
            q = push(q, make_pair(x, y - 1));
            
            f[x][y - 1] = f[x][y] + 1;
        }
        
        if (f[(x + 1) % 2][y + k] == -1 && s[(x + 1) % 2][y + k] == '-') {
            q = push(q, make_pair((x + 1) % 2, y + k));
            
            f[(x + 1) % 2][y + k] = f[x][y] + 1;
        }
    }
    
    puts("NO");
    
    return 0;
}