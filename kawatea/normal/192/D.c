#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int i;
} square;

int cmp(const void *a, const void *b)
{
    return ((square *)b)->a - ((square *)a)->a;
}

int main()
{
    int n, k, i;
    long long b, sum = 0;
    int a[100000];
    square s[100000];
    int f[100000];
    
    scanf("%d %d", &n, &k);
    scanf("%I64d", &b);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        s[i].a = a[i];
        s[i].i = i;
        f[i] = 0;
    }
    
    qsort(s, n - 1, sizeof(square), cmp);
    
    for (i = 0; i < k; i++) {
        sum += s[i].a;
        
        f[s[i].i] = 1;
    }
    
    if (sum <= b) {
        printf("%d\n", n);
        
        return 0;
    }
    
    for (i = 0; i < n - 1; i++) {
        if (f[i] == 1) {
            printf("%d\n", i + 1);
            
            return 0;
        }
        
        if (sum - s[k - 1].a + a[i] > b) {
            printf("%d\n", i + 1);
            
            return 0;
        }
    }
    
    return 0;
}