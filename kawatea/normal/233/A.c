#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    if (n % 2 == 1) {
        puts("-1");
    } else {
        for (i = 0; i < n; i++) {
            if (i > 0) putchar(' ');
            
            if (i % 2 == 0) {
                printf("%d", i + 2);
            } else {
                printf("%d", i);
            }
        }
        
        puts("");
    }
    
    return 0;
}