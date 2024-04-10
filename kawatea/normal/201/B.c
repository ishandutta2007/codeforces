#include <stdio.h>

int c[1000][1000];
long long s[2][1001][1001];
long long s2[4][1001][1001];

int main()
{
    int n, m, x = 0, y = 0, i, j;
    long long ans, sum = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
            
            s[0][i + 1][j + 1] = s[0][i + 1][j] + s[0][i][j + 1] - s[0][i][j] + c[i][j];
            
            sum += (long long)c[i][j] * ((i * 4 + 2) * (i * 4 + 2) + (j * 4 + 2) * (j * 4 + 2));
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            s[1][i][j] = s[1][i + 1][j] + s[1][i][j + 1] - s[1][i + 1][j + 1] + c[i][j];
        }
    }
    
    for (i = 1; i <= n; i++) s2[0][i][m] = s2[0][i - 1][m] + s[0][i][m];
    for (i = n - 1; i >= 0; i--) s2[1][i][m] = s2[1][i + 1][m] + s[1][i][0];
    for (i = 1; i <= m; i++) s2[2][n][i] = s2[2][n][i - 1] + s[0][n][i];
    for (i = m - 1; i >= 0; i--) s2[3][n][i] = s2[3][n][i + 1] + s[1][0][i];
    
    ans = sum;
    
    for (i = 0; i <= n; i++) {
        long long tmp;
        
        if (i > 0) sum += 32 * (s2[0][i - 1][m] - s2[1][i][m]);
        
        tmp = sum;
        
        for (j = 0; j <= m; j++) {
            if (j > 0) sum += 32 * (s2[2][n][j - 1] - s2[3][n][j]);
            
            if (sum < ans) {
                x = i;
                y = j;
                ans = sum;
            }
        }
        
        sum = tmp;
    }
    
    printf("%I64d\n", ans);
    printf("%d %d\n", x, y);
    
    return 0;
}