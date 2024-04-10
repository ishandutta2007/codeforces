#include <stdio.h>

int main()
{
    int a, b, c, i;
    
    scanf("%d %d %d", &a, &b, &c);
    
    for (i = 0; i <= a; i++) {
        int x = b - i;
        int y = c - x;
        
        if (x < 0 || y < 0 || a - y != i) continue;
        
        printf("%d %d %d\n", i, x, y);
        
        return 0;
    }
    
    puts("Impossible");
    
    return 0;
}