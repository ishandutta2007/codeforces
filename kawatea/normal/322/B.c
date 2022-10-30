#include <stdio.h>

int main()
{
    int r, g, b, ans;
    
    scanf("%d %d %d", &r, &g, &b);
    
    ans = r / 3 + g / 3 + b / 3;
    
    if (r > 0 && g > 0 && b > 0) {
        int sum = 1 + (r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3;
        
        if (sum > ans) ans = sum;
    }
    
    if (r > 1 && g > 1 && b > 1) {
        int sum = 2 + (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3;
        
        if (sum > ans) ans = sum;
    }
    
    printf("%d\n", ans);
    
    return 0;
}