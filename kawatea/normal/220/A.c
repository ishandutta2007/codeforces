#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int n, c = 0, i;
    int a[100000], b[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        b[i] = a[i];
    }
    
    qsort(b, n, sizeof(int), cmp);
    
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) c++;
    }
    
    if (c <= 2) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}