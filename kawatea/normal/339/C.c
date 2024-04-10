#include <stdio.h>

int dp[1001][11][11];
int dp2[1001][11][11][2];

int main()
{
    int m, i, j, k, l;
    int a[11] = {0};
    
    for (i = 0; i < 10; i++) scanf("%1d", &a[i]);
    
    scanf("%d", &m);
    
    dp[0][10][0] = 1;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j <= 10; j++) {
            for (k = 0; k <= 10; k++) {
                if (dp[i][j][k] == 0) continue;
                
                for (l = 0; l < 10; l++) {
                    if (a[l] == 0) continue;
                    
                    if (l == j) continue;
                    
                    if (l + 1 <= k) continue;
                    
                    dp[i + 1][l][l + 1 - k] = 1;
                    dp2[i + 1][l][l + 1 - k][0] = j;
                    dp2[i + 1][l][l + 1 - k][1] = k;
                }
            }
        }
    }
    
    for (i = 0; i < 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (dp[m][i][j] == 1) {
                int x = i, y = j;
                int b[1000];
                
                for (i = m; i > 0; i--) {
                    int nx, ny;
                    
                    b[i - 1] = x + 1;
                    
                    nx = dp2[i][x][y][0];
                    ny = dp2[i][x][y][1];
                    
                    x = nx;
                    y = ny;
                }
                
                puts("YES");
                
                for (i = 0; i < m; i++) {
                    if (i > 0) putchar(' ');
                    
                    printf("%d", b[i]);
                }
                
                puts("");
                
                return 0;
            }
        }
    }
    
    puts("NO");
    
    return 0;
}