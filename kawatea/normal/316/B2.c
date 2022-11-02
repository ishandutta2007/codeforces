#include <stdio.h>

int x, p;
int a[1000];
int b[1000];
int d[1000];
int dp[1000];

int dfs(int y)
{
    if (y == x) return -1e9;
    
    if (a[y] == 0) return 1;
    
    return dfs(a[y] - 1) + 1;
}

int dfs2(int y)
{
    if (y == x) {
        if (a[y] == 0) {
            p = 1;
        } else {
            p = dfs2(a[y] - 1) + 1;
        }
        
        return p;
    }
    
    if (a[y] == 0) return 1;
    
    return dfs2(a[y] - 1) + 1;
}

int main()
{
    int n, c = 0, i, j;
    
    scanf("%d %d", &n, &x);
    
    x--;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        if (a[i] != 0) d[a[i] - 1] = 1;
    }
    
    for (i = 0; i < n; i++) {
        if (d[i] == 0) {
            int y = dfs(i);
            
            if (y >= 0) {
                b[c++] = y;
            } else {
                dfs2(i);
            }
        }
    }
    
    dp[0] = 1;
    
    for (i = 0; i < c; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (dp[j] == 0) continue;
            
            dp[j + b[i]] = 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (dp[i] == 1) printf("%d\n", i + p);
    }
    
    return 0;
}