#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m;
int a[20][2];
int dp[20][1 << 20];
vector <int> v;

int dfs(int x, int y)
{
    int i;
    
    if (x == m) return 0;
    
    if (dp[x][y] != 1e9) return dp[x][y];
    
    if (a[x][1] == 0) {
        int ans = -1e9;
        
        if (a[x][0] == 1) {
            for (i = 0; i < m; i++) {
                if ((y >> i) & 1) continue;
                
                ans = max(ans, dfs(x + 1, y | (1 << i)) + v[i]);
            }
        } else {
            for (i = 0; i < m; i++) {
                if ((y >> i) & 1) continue;
                
                ans = max(ans, dfs(x + 1, y | (1 << i)));
            }
        }
        
        return dp[x][y] = ans;
    } else {
        int ans = 1e9;
        
        if (a[x][0] == 1) {
            for (i = 0; i < m; i++) {
                if ((y >> i) & 1) continue;
                
                ans = min(ans, dfs(x + 1, y | (1 << i)) - v[i]);
            }
        } else {
            for (i = 0; i < m; i++) {
                if ((y >> i) & 1) continue;
                
                ans = min(ans, dfs(x + 1, y | (1 << i)));
            }
        }
        
        return dp[x][y] = ans;
    }
}

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int x;
        char s[2];
        
        scanf("%s %d", s, &x);
        
        if (s[0] == 'p') {
            a[i][0] = 1;
        } else {
            a[i][0] = 2;
        }
        
        a[i][1] = x - 1;
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < (1 << 20); j++) {
            dp[i][j] = 1e9;
        }
    }
    
    printf("%d\n", dfs(0, 0));
    
    return 0;
}