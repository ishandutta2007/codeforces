#include <stdio.h>

int main()
{
    int n, i;
    long long sum = 0;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x = 1;
        
        while (1) {
            if (i + x * 2 >= n) break;
            
            x *= 2;
        }
        
        sum += a[i];
        
        a[i + x] += a[i];
        a[i] = 0;
        
        printf("%I64d\n", sum);
    }
    
    return 0;
}