#include <stdio.h>

int a[200000];

int main()
{
    int n, t, c, x = 0, ans = 0, i;
    
    scanf("%d %d %d", &n, &t, &c);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < c; i++) {
        if (a[i] > t) x++;
    }
    
    if (x == 0) ans++;
    
    for (i = c; i < n; i++) {
        if (a[i] > t) x++;
        if (a[i - c] > t) x--;
        
        if (x == 0) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}