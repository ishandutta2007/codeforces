#include <cstdio>
#include <vector>

using namespace std;

int m = 1000000007;
int a[100000];
int dp[100000][2];
vector <int> v[100000];

int dfs(int x, int y, int z)
{
    int i;
    
    if (dp[x][z] >= 0) return dp[x][z];
    
    if (z == 0 && a[x] == 1) return dp[x][z] = 0;
    
    if (z == 0 || a[x] == 1) {
        long long ans = 1;
        
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            ans = ans * ((dfs(v[x][i], x, 0) + dfs(v[x][i], x, 1)) % m) % m;
        }
        
        return dp[x][z] = ans;
    } else {
        long long dp2[2];
        
        dp2[0] = 1;
        dp2[1] = 0;
        
        for (i = 0; i < v[x].size(); i++) {
            int tmp, tmp2;
            
            if (v[x][i] == y) continue;
            
            tmp = dfs(v[x][i], x, 0);
            tmp2 = dfs(v[x][i], x, 1);
            
            dp2[1] = (dp2[0] * tmp2 % m + dp2[1] * ((tmp + tmp2) % m) % m) % m;
            dp2[0] = dp2[0] * ((tmp + tmp2) % m) % m;
        }
        
        return dp[x][z] = dp2[1];
    }
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[i + 1].push_back(x);
        v[x].push_back(i + 1);
    }
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
    
    printf("%d\n", dfs(0, -1, 1));
    
    return 0;
}