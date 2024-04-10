#include <cstdio>

using namespace std;

int dp[2][200001];

int main()
{
    int r, g, h, sum = 0, ans = 0, m = 1000000007, i, j;
    
    scanf("%d %d", &r, &g);
    
    for (i = 1; ; i++) {
        if (i * (i + 1) / 2 > r + g) break;
    }
    
    h = i - 1;
    
    dp[0][0] = 1;
    
    for (i = 0; i < h; i++) {
        for (j = 0; j <= r; j++) {
            if (dp[i & 1][j] == 0) continue;
            
            if (r - j >= h - i) {
                dp[(i + 1) & 1][j + h - i] += dp[i & 1][j];
                if (dp[(i + 1) & 1][j + h - i] >= m) dp[(i + 1) & 1][j + h - i] -= m;
            }
            
            if (g - sum + j >= h - i) {
                dp[(i + 1) & 1][j] += dp[i & 1][j];
                if (dp[(i + 1) & 1][j] >= m) dp[(i + 1) & 1][j] -= m;
            }
            
            dp[i & 1][j] = 0;
        }
        
        sum += h - i;
    }
    
    for (i = 0; i <= r; i++) {
        ans += dp[h & 1][i];
        if (ans >= m) ans -= m;
    }
    
    printf("%d\n", ans);
    
    return 0;
}