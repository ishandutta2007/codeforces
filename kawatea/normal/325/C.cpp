#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > v[100000];
vector <int> w[100000];
int dp[100000];
int dp2[100000][2];

int dfs(int x, int y)
{
    int i, j;
    
    if (y == 1 && dp[x] != 0) return dp[x];
    
    dp[x] = 2;
    
    for (i = 0; i < v[x].size(); i++) {
        for (j = 0; j < v[x][i].size(); j++) {
            if (dfs(v[x][i][j], 1) == 2) break;
        }
        
        if (j == v[x][i].size()) return dp[x] = 1;
    }
    
    return dp[x] = 2;
}

int dfs2(int x, int y)
{
    int ans = 1e9, i, j;
    
    if (y == 1 && dp2[x][0] != -1) return dp2[x][0];
    
    dp2[x][0] = 1e9;
    
    for (i = 0; i < v[x].size(); i++) {
        int p = w[x][i];
        
        for (j = 0; j < v[x][i].size(); j++) {
            if (dp[v[x][i][j]] == 2) break;
            
            p += dfs2(v[x][i][j], 1);
            
            if (p >= 1e9) {
                p = 1e9;
            } else if (p >= 314000000) {
                p = 314000000;
            }
        }
        
        if (j == v[x][i].size()) ans = min(ans, p);
    }
    
    return dp2[x][0] = ans;
}

int dfs3(int x, int y)
{
    int ans = 0, i, j;
    
    if (y == 1 && dp2[x][1] != -1) return dp2[x][1];
    
    dp2[x][1] = 1e9;
    
    for (i = 0; i < v[x].size(); i++) {
        int p = w[x][i];
        
        for (j = 0; j < v[x][i].size(); j++) {
            if (dp[v[x][i][j]] == 2) break;
            
            p += dfs3(v[x][i][j], 1);
            
            if (p >= 1e9) {
                p = 1e9;
            } else if (p >= 314000000) {
                p = 314000000;
            }
        }
        
        if (j == v[x][i].size()) ans = max(ans, p);
    }
    
    return dp2[x][1] = ans;
}

int main()
{
    int m, n, i, j;
    
    scanf("%d %d", &m, &n);
    
    for (i = 0; i < m; i++) {
        int x, y, c = 0;
        vector <int> z;
        
        scanf("%d %d", &x, &y);
        
        for (j = 0; j < y; j++) {
            int p;
            
            scanf("%d", &p);
            
            if (p == -1) {
                c++;
            } else {
                z.push_back(p - 1);
            }
        }
        
        v[x - 1].push_back(z);
        w[x - 1].push_back(c);
    }
    
    for (i = 0; i < n; i++) dfs(i, 0);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            dp2[i][j] = -1;
        }
    }
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        if (dp[i] == 2) {
            puts("-1 -1");
            
            continue;
        }
        
        dfs2(i, 0);
        dfs3(i, 0);
        
        x = dp2[i][0];
        
        if (dp2[i][1] == 1e9) {
            y = -2;
        } else {
            y = dp2[i][1];
        }
        
        printf("%d %d\n", x, y);
    }
    
    return 0;
}