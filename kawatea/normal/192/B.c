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
    int n, i;
    int a[1000];
    int dp[1000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) dp[i] = 0;
    
    dp[n - 1] = a[n - 1];
    
    for (i = n - 1; i > 0; i--) {
        if (dp[i] > a[i]) dp[i] = a[i];
        
        dp[i - 1] = max(dp[i - 1], dp[i]);
        
        if (i > 1) dp[i - 2] = max(dp[i - 2], dp[i]);
    }
    
    if (dp[0] > a[0]) dp[0] = a[0];
    
    printf("%d\n", dp[0]);
    
    return 0;
}