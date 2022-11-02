#include <stdio.h>

int main()
{
    int n = 302, x = 0, r = 1000000, i;
    
    printf("%d\n", n);
    
    printf("%d %d\n", 0, 1000000);
    
    for (i = 1; i < n - 1; i++) {
        int y = x;
        
        while (1) {
            if ((long long)(y - x) * (y - x) / 4 / r == n - i - 1) break;
            
            y++;
        }
        
        x = y;
        r = n - i - 1;
        
        printf("%d %d\n", x, n - i - 1);
    }
    
    printf("%d %d\n", 200000, 1000000);
    
    return 0;
}