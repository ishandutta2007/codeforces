#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    if (n == 0) {
        puts("O-|-OOOO");
        
        return 0;
    }
    
    while (n) {
        int x = n % 10;
        
        if (x < 5) {
            printf("O-|");
        } else {
            printf("-O|");
            
            x -= 5;
        }
        
        for (i = 0; i < x; i++) printf("O");
        
        printf("-");
        
        for (i = 0; i < 4 - x; i++) printf("O");
        
        puts("");
        
        n /= 10;
    }
    
    return 0;
}