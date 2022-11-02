#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    long long p;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    
    p = (long long)(x2 - x1) * (y3 - y1) - (long long)(y2 - y1) * (x3 - x1);
    
    if (p < 0) {
        puts("RIGHT");
    } else if (p == 0) {
        puts("TOWARDS");
    } else {
        puts("LEFT");
    }
    
    return 0;
}