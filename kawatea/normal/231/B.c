#include <stdio.h>

int main()
{
    int n, d, l, x, y, i;
    int a[100];
    
    scanf("%d %d %d", &n, &d, &l);
    
    x = 1;
    y = l;
    
    a[0] = 1;
    
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            x++;
            y += l;
            
            a[i] = 1;
        } else {
            x -= l;
            y--;
            
            a[i] = l;
        }
    }
    
    if (d < x || d > y) {
        puts("-1");
        
        return 0;
    }
    
    d -= x;
    
    for (i = 0; i < n && d > 0; i++) {
        if (i % 2 == 0) {
            if (l - 1 <= d) {
                a[i] = l;
                d -= l - 1;
            } else {
                a[i] += d;
                d = 0;
            }
        } else {
            if (l - 1 <= d) {
                a[i] = 1;
                d -= l - 1;
            } else {
                a[i] -= d;
                d = 0;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}