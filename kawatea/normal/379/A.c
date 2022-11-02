#include <stdio.h>

int main()
{
    int a, b, ans;
    
    scanf("%d %d", &a, &b);
    
    ans = a;
    
    while (1) {
        if (a / b == 0) break;
        
        ans += a / b;
        a = a / b + a % b;
    }
    
    printf("%d\n", ans);
    
    return 0;
}