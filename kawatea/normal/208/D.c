#include <stdio.h>

int main()
{
    int n, i, j;
    long long sum = 0;
    int a[50], b[5];
    long long c[5] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < 5; i++) scanf("%d", &b[i]);
    
    for (i = 0; i < n; i++) {
        sum += a[i];
        
        for (j = 4; j >= 0; j--) {
            c[j] += sum / b[j];
            
            sum %= b[j];
        }
    }
    
    for (i = 0; i < 5; i++) {
        if (i > 0) putchar(' ');
        
        printf("%I64d", c[i]);
    }
    
    puts("");
    
    printf("%I64d\n", sum);
    
    return 0;
}