#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    if (n <= 2) {
        puts("-1");
    } else {
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            printf("%d", n - i);
        }
        
        puts("");
    }
    
    return 0;
}