#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, p = 0, q = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        p += x;
        q += y;
    }
    
    printf("%d\n", min(p, n - p) + min(q, n - q));
    
    return 0;
}