#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, x1, y1, x2, y2, x, y;
    
    scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
    
    x = abs(x1 - x2);
    y = abs(y1 - y2);
    
    if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    if ((x <= 2 && y <= 4) || (x == 3 && y == 3)) {
        puts("First");
    } else {
        puts("Second");
    }
    
    return 0;
}