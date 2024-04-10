#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    unsigned x = *((unsigned *)a);
    unsigned y = *((unsigned *)b);
    
    if (x < y) {
        return -1;
    } else if (x == y) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    int n, k, i, j;
    unsigned a[100000];
    unsigned b[100000];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x, y, z, w;
        
        scanf("%d.%d.%d.%d", &x, &y, &z, &w);
        
        a[i] = (x << 24) + (y << 16) + (z << 8) + w;
    }
    
    for (i = 1; i <= 32; i++) {
        int c = 1;
        unsigned x = 0;
        
        for (j = 0; j < i; j++) x |= (1 << (31 - j));
        
        for (j = 0; j < n; j++) b[j] = a[j] & x;
        
        qsort(b, n, sizeof(unsigned), cmp);
        
        for (j = 0; j < n - 1; j++) {
            if (b[j] != b[j + 1]) c++;
        }
        
        if (c == k) {
            int mask = (1 << 8) - 1;
            
            printf("%d.%d.%d.%d\n", (x >> 24) & mask, (x >> 16) & mask, (x >> 8) & mask, x & mask);
            
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}