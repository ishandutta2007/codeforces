#include <cstdio>

using namespace std;

int n;
int a[200000];
long long dp[200000][2];

long long dfs(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = -2;
    
    if (y == 0) {
        if (x + a[x] >= n) {
            return dp[x][y] = a[x];
        } else {
            long long z = dfs(x + a[x], 1);
            
            if (z == -2) {
                return dp[x][y] = -2;
            } else {
                return dp[x][y] = z + a[x];
            }
        }
    } else {
        if (x - a[x] < 0) {
            return dp[x][y] = a[x];
        } else {
            long long z = dfs(x - a[x], 0);
            
            if (z == -2) {
                return dp[x][y] = -2;
            } else {
                return dp[x][y] = z + a[x];
            }
        }
    }
}

int main()
{
    int i, j;
    
    scanf("%d", &n);
    
    for (i = 1; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < 2; j++) {
            dfs(i, j);
        }
    }
    
    for (i = 1; i < n; i++) {
        if (dp[i][1] == -2) {
            puts("-1");
        } else {
            printf("%I64d\n", dp[i][1] + i);
        }
    }
    
    return 0;
}