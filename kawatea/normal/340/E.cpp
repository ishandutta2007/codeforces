#include <cstdio>

using namespace std;

int m = 1000000007;
long long c[2001][2001];
long long d[2001];
long long p[2001];
long long dp[2001][2001];

long long dfs(int x, int y)
{
    int i;
    long long ans = 0;
    
    if (x == 0) return p[y];
    
    if (y == 0) return d[x];
    
    if (dp[x][y] != -1) return dp[x][y];
    
    for (i = 0; i <= x && i <= y; i++) {
        ans = (ans + c[x][i] * c[y][i] % m * p[y] % m * dfs(x - i, i) % m) % m;
    }
    
    return dp[x][y] = ans;
}

int main()
{
    int n, x = 0, y = 0, i, j;
    int a[2000];
    int b[2000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) b[i] = -1;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        if (a[i] != -1) a[i]--;
        
        if (a[i] == i) {
            puts("0");
            
            return 0;
        }
        
        if (a[i] != -1) b[a[i]] = i;
    }
    
    for (i = 0; i <= 2000; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
    }
    
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    
    for (i = 3; i <= 2000; i++) d[i] = (long long)(d[i - 1] + d[i - 2]) % m * (i - 1) % m;
    
    p[0] = 1;
    
    for (i = 1; i <= 2000; i++) p[i] = p[i - 1] * i % m;
    
    for (i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (b[i] == -1) {
                x++;
            } else {
                y++;
            }
        }
    }
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n", (int)dfs(x, y));
    
    return 0;
}