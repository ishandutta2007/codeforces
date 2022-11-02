#include <stdio.h>

int main()
{
    int n, c, ans = 0, i;
    int a[100];
    
    scanf("%d %d", &n, &c);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        if (a[i] - a[i + 1] - c > ans) ans = a[i] - a[i + 1] - c;
    }
    
    printf("%d\n", ans);
    
    return 0;
}