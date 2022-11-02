#include <stdio.h>

int main()
{
    long long n, k;
    
    scanf("%I64d %I64d", &n, &k);
    
    if (k <= (n + 1) / 2) {
        printf("%I64d\n", k * 2 - 1);
    } else {
        k -= (n + 1) / 2;
        
        printf("%I64d\n", k * 2);
    }
    
    return 0;
}