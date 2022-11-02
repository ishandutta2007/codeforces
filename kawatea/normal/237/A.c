#include <stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, m = 0, i;
    int a[24][60] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        a[x][y]++;
        
        m = max(m, a[x][y]);
    }
    
    printf("%d\n", m);
    
    return 0;
}