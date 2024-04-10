#include <stdio.h>

int main()
{
    int n, i;
    long long sum = 0;
    int a[32] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y = 0;
        
        scanf("%d", &x);
        
        while (x) {
            y += x & 1;
            x >>= 1;
        }
        
        a[y]++;
    }
    
    for (i = 0; i < 32; i++) sum += (long long)a[i] * (a[i] - 1) / 2;
    
    printf("%I64d\n", sum);
    
    return 0;
}