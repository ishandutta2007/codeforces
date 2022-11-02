#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t;
    int i;
} town;

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, i;
    town t[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i].t);
        
        t[i].i = i + 1;
    }
    
    qsort(t, n, sizeof(town), cmp);
    
    if (n == 1 || t[0].t < t[1].t) {
        printf("%d\n", t[0].i);
    } else {
        puts("Still Rozdil");
    }
    
    return 0;
}