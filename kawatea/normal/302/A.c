#include <stdio.h>

int main()
{
    int n, m, p = 0, q = 0, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            p++;
        } else {
            q++;
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d", &x, &y);
        
        z = y - x + 1;
        
        if (z % 2 == 1 || p < z / 2 || q < z / 2) {
            puts("0");
        } else {
            puts("1");
        }
    }
    
    return 0;
}