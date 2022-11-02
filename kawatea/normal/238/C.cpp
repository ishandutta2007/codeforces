#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000];
int dp[3000][2];
vector <pair<int, int> > v[3000];

void dfs(int x, int y)
{
    int i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i].first != y) dfs(v[x][i].first, x);
    }
    
    if (y != -1) {
        dp[x][0] = 0;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i].first == y) continue;
            
            dp[x][0] += dp[v[x][i].first][0] + v[x][i].second;
        }
        
        dp[x][1] = dp[x][0];
        
        for (i = 0; i < v[x].size(); i++) {
            int z;
            
            if (v[x][i].first == y) continue;
            
            z = dp[x][0] - dp[v[x][i].first][0] - v[x][i].second;
            
            dp[x][1] = min(dp[x][1], dp[v[x][i].first][1] + z + 1 - v[x][i].second);
        }
    } else {
        int sum = 0, m1 = 1e9, m2 = 1e9;
        
        for (i = 0; i < v[x].size(); i++) {
            int p;
            
            dp[v[x][i].first][1 - v[x][i].second]++;
            
            sum += dp[v[x][i].first][0];
            
            p = dp[v[x][i].first][1] - dp[v[x][i].first][0];
            
            if (p < m1) {
                m2 = m1;
                m1 = p;
            } else if (p < m2) {
                m2 = p;
            }
        }
        
        sum += m1;
        
        if (m2 < 0) sum += m2;
        
        dp[x][1] = sum;
    }
}

int dfs2(int x, int y)
{
    int ans = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i].first == y) continue;
        
        ans += dfs2(v[x][i].first, x) + v[x][i].second;
    }
    
    return ans;
}

int main()
{
    int n, c = 0, ans = 1e9, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        a[y]++;
        v[x].push_back(make_pair(y, 0));
        v[y].push_back(make_pair(x, 1));
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0) c++;
    }
    
    if (c <= 2) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n; i++) {
        if (v[i].size() == 1) continue;
        
        dfs(i, -1);
        
        ans = min(ans, dp[i][1]);
    }
    
    for (i = 0; i < n; i++) ans = min(ans, dfs2(i, -1));
    
    printf("%d\n", ans);
    
    return 0;
}