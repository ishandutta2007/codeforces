#include <stdio.h>

int main()
{
    int n, t = 0, c = 0, p = 0, i, j;
    int a[1000][2];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < n; i++) {
        if (a[i][0] - t >= p) {
            p = a[i][1];
        } else {
            p -= a[i][0] - t;
            p += a[i][1];
        }
        
        t = a[i][0];
        
        if (p > c) c = p;
    }
    
    t += p;
    
    printf("%d %d\n", t, c);
    
    return 0;
}