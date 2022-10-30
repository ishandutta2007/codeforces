#include <stdio.h>
#include <string.h>

int n;
char s[1000001];
int a[1000001];
int dp[1000000][2];

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int dfs(int x, int y)
{
    if (x == n) {
        if (y == 0) {
            return 0;
        } else {
            return 1e9;
        }
    }
    
    if (dp[x][y] >= 0) return dp[x][y];
    
    if (y == 0) {
        if (s[x] == '0') {
            return dp[x][y] = min(dfs(x + 1, 0), dfs(x + 1, 1) + 1);
        } else {
            return dp[x][y] = dfs(x + 1, 0) + 1;
        }
    } else {
        if (s[x] == '0') {
            return dp[x][y] = dfs(x + 1, 1) + 1;
        } else {
            return dp[x][y] = min(dfs(x + 1, 1), dfs(x + 1, 0) + 1);
        }
    }
}

int main()
{
    int i;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i + 1] = a[i] + 1;
        } else {
            a[i + 1] = a[i];
        }
    }
    
    for (i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
    
    printf("%d\n", min(dfs(0, 0), dfs(0, 1) + 1));
    
    return 0;
}