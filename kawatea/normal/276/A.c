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
    int n, k, ans = -2e9, i;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        if (y > k) {
            ans = max(ans, x - (y - k));
        } else {
            ans = max(ans, x);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}