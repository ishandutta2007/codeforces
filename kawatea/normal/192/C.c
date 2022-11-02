#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

char s[500000][11];
int dp[26][26];

int main()
{
    int n, ans = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        int x = strlen(s[i]);
        int p = s[i][0] - 'a';
        int q = s[i][x - 1] - 'a';
        
        for (j = 0; j < 26; j++) {
            if (dp[j][p] == 0) continue;
            
            dp[j][q] = max(dp[j][q], dp[j][p] + x);
        }
        
        dp[p][q] = max(dp[p][q], x);
    }
    
    for (i = 0; i < 26; i++) ans = max(ans, dp[i][i]);
    
    printf("%d\n", ans);
    
    return 0;
}