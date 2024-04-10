#include <stdio.h>

int main()
{
    int n, p = 50, i;
    
    scanf("%d", &n);
    
    if (n <= 2) {
        puts("-1");
        
        return 0;
    } else if (n == 3) {
        puts("210");
        
        return 0;
    }
    
    for (i = 0; i < n - 4; i++) {
        p *= 10;
        p %= 210;
    }
    
    putchar('1');
    
    for (i = 0; i < n - 4; i++) putchar('0');
    
    printf("%03d\n", p);
    
    return 0;
}