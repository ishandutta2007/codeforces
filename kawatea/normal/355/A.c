#include <stdio.h>

int main()
{
    int k, d, i;
    
    scanf("%d %d", &k, &d);
    
    if (d == 0) {
        if (k == 1) {
            puts("0");
        } else {
            puts("No solution");
        }
    } else {
        printf("%d", d);
        
        for (i = 0; i < k - 1; i++) putchar('0');
        
        puts("");
    }
    
    return 0;
}