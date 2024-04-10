#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2, p, q, r;
    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if (x1 == x2 || y1 == y2) {
        p = 1;
    } else {
        p = 2;
    }
    
    if (x2 - x1 == y2 - y1 || x1 + y1 == x2 + y2) {
        q = 1;
    } else if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        q = 2;
    } else {
        q = 0;
    }
    
    if (abs(x1 - x2) < abs(y1 - y2)) {
        r = abs(y1 - y2);
    } else {
        r = abs(x1 - x2);
    }
    
    printf("%d %d %d\n", p, q, r);
    
    return 0;
}