#include <cstdio>

using namespace std;

int sum[41][41];
int dp[40][40][40][40];

int dfs(int x1, int y1, int x2, int y2)
{
    int l, r, m, x, y, ans = 0;
    
    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
    
    if (sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1] == 0) {
        x = x2 - x1 + 1;
        y = y2 - y1 + 1;
        
        return dp[x1][y1][x2][y2] = x * (x + 1) / 2 * y * (y + 1) / 2;
    }
    
    l = x1 - 1, r = x2 + 1, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (sum[m][y2 + 1] - sum[m][y1] - sum[x1][y2 + 1] + sum[x1][y1] > 0) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    x = r;
    
    l = y1 - 1; r = y2 + 1, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (sum[x][m] - sum[x][y1] - sum[x1][m] + sum[x1][y1] > 0) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    y = r;
    
    x--;
    y--;
    
    if (x1 <= x - 1) ans += dfs(x1, y1, x - 1, y2);
    if (x2 >= x + 1) ans += dfs(x + 1, y1, x2, y2);
    if (y1 <= y - 1) ans += dfs(x1, y1, x2, y - 1);
    if (y2 >= y + 1) ans += dfs(x1, y + 1, x2, y2);
    if (x1 <= x - 1 && y1 <= y - 1) ans -= dfs(x1, y1, x - 1, y - 1);
    if (x1 <= x - 1 && y2 >= y + 1) ans -= dfs(x1, y + 1, x - 1, y2);
    if (x2 >= x + 1 && y1 <= y - 1) ans -= dfs(x + 1, y1, x2, y - 1);
    if (x2 >= x + 1 && y2 >= y + 1) ans -= dfs(x + 1, y + 1, x2, y2);
    
    return dp[x1][y1][x2][y2] = ans;
}

int main()
{
    int n, m, q, i, j, k, l;
    int a[40][40];
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    
    for (i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        x1--;
        y1--;
        x2--;
        y2--;
        
        printf("%d\n", dfs(x1, y1, x2, y2));
    }
    
    return 0;
}