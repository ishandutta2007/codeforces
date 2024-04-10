#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

long long dp[2][150000];

int main()
{
    int n, m, d, i, j;
    long long ans = -1e18;
    int a[300][3];
    
    scanf("%d %d %d", &n, &m, &d);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        
        a[i][0]--;
    }
    
    for (i = 0; i < n; i++) {
        dp[0][i] = a[0][1] - abs(a[0][0] - i);
        dp[1][i] = -1e18;
    }
    
    for (i = 1; i < m; i++) {
        long long x = -(long long)(a[i][2] - a[i - 1][2]) * d;
        long long y = -x;
        deque <pair<int, long long> > q;
        
        for (j = 0; j <= y && j < n; j++) {
            while (!q.empty() && q.back().second <= dp[(i - 1) & 1][j]) q.pop_back();
            
            q.push_back(make_pair(j, dp[(i - 1) & 1][j]));
        }
        
        dp[i & 1][0] = q.front().second + a[i][1] - a[i][0];
        
        for (j = 1; j < n; j++) {
            x++;
            y++;
            
            if (q.front().first == x - 1) q.pop_front();
            
            if (y < n) {
                while (!q.empty() && q.back().second <= dp[(i - 1) & 1][y]) q.pop_back();
                
                q.push_back(make_pair(y, dp[(i - 1) & 1][y]));
            }
            
            dp[i & 1][j] = q.front().second + a[i][1] - abs(a[i][0] - j);
        }
        
        for (j = 0; j < n; j++) dp[(i - 1) & 1][j] = -1e18;
    }
    
    for (i = 0; i < n; i++) ans = max(ans, dp[(m - 1) & 1][i]);
    
    printf("%I64d\n", ans);
    
    return 0;
}