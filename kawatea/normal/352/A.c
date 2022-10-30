#include <stdio.h>

int main()
{
    int n, c1 = 0, c2 = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 5) {
            c1++;
        } else {
            c2++;
        }
    }
    
    if (c2 == 0) {
        puts("-1");
    } else if (c1 < 9) {
        puts("0");
    } else {
        c1 -= c1 % 9;
        
        for (i = 0; i < c1; i++) putchar('5');
        for (i = 0; i < c2; i++) putchar('0');
        
        puts("");
    }
    
    return 0;
}