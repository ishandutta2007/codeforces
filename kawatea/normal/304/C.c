#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        puts("-1");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", i);
    }
    puts("");
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", i);
    }
    puts("");
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", (i + i) % n);
    }
    puts("");
    
    return 0;
}