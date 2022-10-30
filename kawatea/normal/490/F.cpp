#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[6000];
vector <int> dp;
vector <int> v[6000];

int dfs(int x, int y)
{
    int ans, z, p, i;
    
    z = lower_bound(dp.begin(), dp.end(), a[x]) - dp.begin();
    
    p = dp[z];
    dp[z] = a[x];
    ans = z + 1;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        ans = max(ans, dfs(v[x][i], x));
    }
    
    dp[z] = p;
    
    return ans;
}

int main()
{
    int n, ans = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i <= 6000; i++) dp.push_back(1e9);
    
    for (i = 0; i < n; i++) ans = max(ans, dfs(i, -1));
    
    printf("%d\n", ans);
    
    return 0;
}