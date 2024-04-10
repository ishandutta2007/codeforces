#include <stdio.h>

int main()
{
    int n, c = 0, i;
    double a, d, x = 0, y = 0;
    
    scanf("%lf %lf", &a, &d);
    scanf("%d", &n);
    
    while (d >= a * 4) d -= a * 4;
    
    for (i = 0; i < n; i++) {
        double z = d;
        
        while (z > 0) {
            if (c == 0) {
                if (x + z <= a) {
                    x += z;
                    z = 0;
                    
                    break;
                } else {
                    z -= a - x;
                    x = a;
                }
            } else if (c == 1) {
                if (y + z <= a) {
                    y += z;
                    z = 0;
                    
                    break;
                } else {
                    z -= a - y;
                    y = a;
                }
            } else if (c == 2) {
                if (x - z >= 0) {
                    x -= z;
                    z = 0;
                    
                    break;
                } else {
                    z -= x;
                    x = 0;
                }
            } else {
                if (y - z >= 0) {
                    y -= z;
                    z = 0;
                    
                    break;
                } else {
                    z -= y;
                    y = 0;
                }
            }
            
            c = (c + 1) % 4;
        }
        
        printf("%lf %lf\n", x, y);
    }
    
    return 0;
}