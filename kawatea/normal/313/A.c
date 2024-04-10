#include <stdio.h>

int main()
{
    int x;
    
    scanf("%d", &x);
    
    if (x < 0) {
        x = -x;
        
        if (x % 10 >= x % 100 / 10) {
            x /= 10;
        } else {
            x = x / 100 * 10 + x % 10;
        }
        
        x = -x;
    }
    
    printf("%d\n", x);
    
    return 0;
}