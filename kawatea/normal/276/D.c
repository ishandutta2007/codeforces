#include <stdio.h>

int main()
{
    int i;
    long long x, y;
    
    scanf("%I64d %I64d", &x, &y);
    
    for (i = 62; i >= 0; i--) {
        if (x < (1LL << i) && y >= (1LL << i)) {
            printf("%I64d\n", (1LL << (i + 1)) - 1);
            
            return 0;
        }
        
        if (x & (1LL << i)) {
            x ^= (1LL << i);
            y ^= (1LL << i);
        }
    }
    
    puts("0");
    
    return 0;
}