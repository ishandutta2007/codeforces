#include <stdio.h>
#include <stdlib.h>

#define P int

typedef struct _priority_queue {
    P value;
    int size;
    struct _priority_queue *left;
    struct _priority_queue *right;
} priority_queue;

int cmp_queue(P a, P b)
{
    return a - b;
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

void clear(priority_queue *a)
{
    if (a == NULL) return;
    
    if (a->left != NULL) clear(a->left);
    if (a->right != NULL) clear(a->right);
    
    free(a);
}

int main()
{
    int n, m, sum = 0, sum2 = 0, i;
    int a[1000];
    priority_queue *q = NULL;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) q = push(q, a[i]);
    
    for (i = 0; i < n; i++) {
        int x = top(q);
        
        q = pop(q);
        
        sum2 += x;
        
        if (x > 1) q = push(q, x - 1);
    }
    
    clear(q);
    q = NULL;
    
    for (i = 0; i < m; i++) q = push(q, -a[i]);
    
    for (i = 0; i < n; i++) {
        int x = top(q);
        
        q = pop(q);
        
        sum -= x;
        
        if (x < -1) q = push(q, x + 1);
    }
    
    printf("%d %d\n", sum, sum2);
    
    return 0;
}