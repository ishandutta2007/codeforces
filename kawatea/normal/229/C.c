#include <stdio.h>

int a[1000000];

int main()
{
    int n, m, i;
    long long ans;
    
    scanf("%d %d", &n, &m);
    
    if (n <= 2) {
        puts("0");
        
        return 0;
    }
    
    ans = (long long)n * (n - 1) * (n - 2) / 6;
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        ans -= n - 2 - a[x] - a[y];
        
        a[x]++;
        a[y]++;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}