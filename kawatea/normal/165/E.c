#include <stdio.h>

int a[1000000];
int dp[1 << 22];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < (1 << 22); i++) dp[i] = -1;
    
    for (i = 0; i < n; i++) dp[a[i]] = a[i];
    
    for (i = 0; i < (1 << 22); i++) {
        if (dp[i] == -1) continue;
        
        for (j = 0; j < 22; j++) dp[i | (1 << j)] = dp[i];
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", dp[((1 << 22) - 1) ^ a[i]]);
    }
    
    puts("");
    
    return 0;
}