#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[5][1000];
int b[5][1000];
int dp[1000];
vector <int> v[1000];

int dfs(int x)
{
    int ans = 1, i;
    
    if (dp[x] != -1) return dp[x];
    
    for (i = 0; i < v[x].size(); i++) ans = max(ans, dfs(v[x][i]) + 1);
    
    return dp[x] = ans;
}

int main()
{
    int n, k, ans = 0, i, j, l;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            
            b[i][a[i][j] - 1] = j;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (l = 0; l < k; l++) {
                if (b[l][i] >= b[l][j]) break;
            }
            
            if (l == k) v[i].push_back(j);
        }
    }
    
    for (i = 0; i < n; i++) dp[i] = -1;
    
    for (i = 0; i < n; i++) ans = max(ans, dfs(i));
    
    printf("%d\n", ans);
    
    return 0;
}