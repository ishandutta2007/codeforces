#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int a[30001];
int dp[30001][1100];
map <pair<int, int>, int> mp;

int main()
{
    int n, d, ans = 0, i, j;
    map <pair<int, int>, int>::iterator it;
    
    scanf("%d %d", &n, &d);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x]++;
    }
    
    if (d <= 1000) {
        for (i = 0; i <= 30000; i++) {
            for (j = 0; j < 1100; j++) {
                dp[i][j] = -1;
            }
        }
        
        dp[d][d] = a[d];
        
        for (i = 0; i <= 30000; i++) {
            for (j = 1; j < 1100; j++) {
                if (dp[i][j] < 0) continue;
                
                ans = max(ans, dp[i][j]);
                
                if (i + j - 1 <= 30000 && j > 1) dp[i + j - 1][j - 1] = max(dp[i + j - 1][j - 1], dp[i][j] + a[i + j - 1]);
                if (i + j <= 30000) dp[i + j][j] = max(dp[i + j][j], dp[i][j] + a[i + j]);
                if (i + j + 1 <= 30000) dp[i + j + 1][j + 1] = max(dp[i + j + 1][j + 1], dp[i][j] + a[i + j + 1]);
            }
        }
    } else {
        mp[make_pair(d, d)] = a[d];
        
        for (it = mp.begin(); it != mp.end(); it++) {
            int x = it->first.first;
            int y = it->first.second;
            
            ans = max(ans, it->second);
            
            if (x + y - 1 <= 30000 && y > 1) mp[make_pair(x + y - 1, y - 1)] = max(mp[make_pair(x + y - 1, y - 1)], it->second + a[x + y - 1]);
            if (x + y <= 30000) mp[make_pair(x + y, y)] = max(mp[make_pair(x + y, y)], it->second + a[x + y]);
            if (x + y + 1 <= 30000) mp[make_pair(x + y + 1, y + 1)] = max(mp[make_pair(x + y + 1, y + 1)], it->second + a[x + y + 1]);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}