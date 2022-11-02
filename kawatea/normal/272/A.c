#include <stdio.h>

int main()
{
    int n, sum = 0, ans = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        sum += x;
    }
    
    for (i = 1; i <= 5; i++) {
        if ((sum + i) % (n + 1) != 1) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}