#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l;
    int p;
} list;

int cmp(const void *a, const void *b)
{
    int x1 = ((list *)a)->l;
    int y1 = ((list *)a)->p;
    int x2 = ((list *)b)->l;
    int y2 = ((list *)b)->p;
    
    return x2 * y2 * (100 - y1) - x1 * y1 * (100 - y2);
}

list l[50000];

int main()
{
    int n, i;
    double sum = 0, ans = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &l[i].l, &l[i].p);
    
    qsort(l, n, sizeof(list), cmp);
    
    for (i = 0; i < n; i++) {
        ans += l[i].l;
        ans += sum * (100 - l[i].p) / 100;
        sum += l[i].l * l[i].p / 100.0;
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}