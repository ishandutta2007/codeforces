#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int sum = 0, i, j;
    int a[4];
    
    for (i = 0; i < 4; i++) scanf("%d", &a[i]);
    
    qsort(a, 4, sizeof(int), cmp);
    
    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (a[i] != a[j]) break;
        }
        
        sum += j - i - 1;
        
        i = j - 1;
    }
    
    printf("%d\n", sum);
    
    return 0;
}