#include <stdio.h>

int main()
{
    int n, m, x1 = 0, y1 = 100, x2 = 0, y2 = 100, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x > x1) x1 = x;
        if (x < y1) y1 = x;
    }
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x > x2) x2 = x;
        if (x < y2) y2 = x;
    }
    
    if (x1 >= y2 || y1 * 2 >= y2) {
        puts("-1");
    } else if (x1 > y1 * 2) {
        printf("%d\n", x1);
    } else {
        printf("%d\n", y1 * 2);
    }
    
    return 0;
}