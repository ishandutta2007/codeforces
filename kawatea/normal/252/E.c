#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int dp[360361];

int main()
{
    long long a, b, sum = 0;
    int k, p = 1, i, j;
    
    scanf("%I64d %I64d %d", &a, &b, &k);
    
    if (k >= 8) {
        p *= 8;
    } else if (k >= 4) {
        p *= 4;
    } else {
        p *= 2;
    }
    
    if (k >= 9) {
        p *= 9;
    } else if (k >= 3) {
        p *= 3;
    }
    
    if (k >= 5) p *= 5;
    if (k >= 7) p *= 7;
    if (k >= 11) p *= 11;
    if (k >= 13) p *= 13;
    
    dp[0] = 0;
    
    for (i = 1; i <= p; i++) {
        dp[i] = dp[i - 1] + 1;
        
        for (j = 2; j <= k; j++) {
            int x = i % j;
            
            if (x > 0) dp[i] = min(dp[i - x] + 1, dp[i]);
        }
    }
    
    if (a / p > b / p) {
        sum += dp[a % p];
        a = a / p * p;
        
        sum += (a / p - b / p - 1) * dp[p];
        a = b / p * p + p;
    }
    
    for (i = 0; i <= p; i++) dp[i] = 1e9;
    
    if (a % p == 0) {
        if (a == b) {
            printf("%I64d\n", sum);
            
            return 0;
        }
        
        dp[p] = 0;
    } else {
        dp[a % p] = 0;
    }
    
    for (i = p; i >= 0; i--) {
        if (dp[i] == 1e9) continue;
        
        if (i == b % p) {
            printf("%I64d\n", sum + dp[i]);
            
            return 0;
        }
        
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        
        for (j = 2; j <= k; j++) {
            int x = i % j;
            
            if (x > 0) dp[i - x] = min(dp[i - x], dp[i] + 1);
        }
    }
    
    return 0;
}