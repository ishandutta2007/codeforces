#include <stdio.h>

int n;
int a[101];
int dp[9][9][101][1 << 9];

void dfs(int x, int y, int z, int w)
{
    if (x == n) {
        if (z <= 100 && n * 2 - 1 < a[z]) a[z] = n * 2 - 1;
        
        return;
    }
    
    if (y == n) {
        dfs(x + 1, 0, z, w);
        
        return;
    }
    
    if (z > 100) return;
    
    if (dp[x][y][z][w] == 1) return;
    
    dp[x][y][z][w] = 1;
    
    if (x == 0) {
        if (y == 0) {
            dfs(x, y + 1, 0, 0);
            dfs(x, y + 1, 1, 1);
        } else {
            dfs(x, y + 1, z, w);
            
            if (((w >> (y - 1)) & 1) == 0) dfs(x, y + 1, z + 2, w | (1 << y));
        }
    } else {
        if (y == 0) {
            if ((w & 1) == 0) dfs(x, y + 1, z + 2, w | 1);
        } else {
            if ((w & (1 << y)) == 0 && ((w >> (y - 1)) & 1) == 0) dfs(x, y + 1, z + 4, w | (1 << y));
        }
        
        dfs(x, y + 1, z, w & (((1 << n) - 1) ^ (1 << y)));
    }
}

int main()
{
    int x, i, j, k, l, m;
    
    for (i = 0; i <= 100; i++) a[i] = 100;
    
    for (i = 1; i < 9; i++) {
        n = i;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l <= 100; l++) {
                    for (m = 0; m < (1 << n); m++) {
                        dp[j][k][l][m] = 0;
                    }
                }
            }
        }
        
        dfs(0, 0, 0, 0);
    }
    
    scanf("%d", &x);
    
    printf("%d\n", a[x]);
    
    return 0;
}