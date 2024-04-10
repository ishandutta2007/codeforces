#include <stdio.h>

int a[100000];

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        z--;
        
        if (a[x] != 0) {
            a[y] = (a[x] + 1) % 3;
            a[z] = (a[x] + 2) % 3;
        } else if (a[y] != 0) {
            a[x] = (a[y] + 1) % 3;
            a[z] = (a[y] + 2) % 3;
        } else if (a[z] != 0) {
            a[x] = (a[z] + 1) % 3;
            a[y] = (a[z] + 2) % 3;
        } else {
            a[x] = 1;
            a[y] = 2;
            a[z] = 3;
        }
        
        if (a[x] == 0) a[x] = 3;
        if (a[y] == 0) a[y] = 3;
        if (a[z] == 0) a[z] = 3;
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}