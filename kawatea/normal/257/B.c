#include <stdio.h>

int main()
{
    int n, m, x, y, z, w, ans = 0, i;
    
    scanf("%d %d", &n, &m);
    
    x = n - 1;
    y = m;
    z = 0;
    w = 0;
    
    for (i = 1; i < n + m; i++) {
        if (x == 0) {
            if (w == 1) z++;
            
            y--;
            
            w = 1;
        } else if (y == 0) {
            if (w == 0) z++;
            
            x--;
            
            w = 0;
        } else if (i % 2 == 0) {
            if (w == 0) {
                x--;
            } else {
                y--;
            }
            
            z++;
        } else {
            if (w == 0) {
                y--;
            } else {
                x--;
            }
            
            w = 1 - w;
        }
    }
    
    if (z > ans) ans = z;
    
    x = n;
    y = m - 1;
    z = 0;
    w = 1;
    
    for (i = 1; i < n + m; i++) {
        if (x == 0) {
            if (w == 1) z++;
            
            y--;
            
            w = 1;
        } else if (y == 0) {
            if (w == 0) z++;
            
            x--;
            
            w = 0;
        } else if (i % 2 == 0) {
            if (w == 0) {
                x--;
            } else {
                y--;
            }
            
            z++;
        } else {
            if (w == 0) {
                y--;
            } else {
                x--;
            }
            
            w = 1 - w;
        }
    }
    
    if (z > ans) ans = z;
    
    printf("%d %d\n", ans, n + m - ans - 1);
    
    return 0;
}