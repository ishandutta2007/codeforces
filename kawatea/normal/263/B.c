#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, k, i;
    int a[50];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    qsort(a, n, sizeof(int), cmp);
    
    if (k > n) {
        puts("-1");
    } else {
        printf("%d %d\n", a[n - k], a[n - k]);
    }
    
    return 0;
}