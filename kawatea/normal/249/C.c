#include <stdio.h>

double dp[100000][101];

double comb(int x, int y)
{
    int i;
    double sum = 1;
    
    if (x < y) return 0;
    
    for (i = 0; i < y; i++) sum *= x - i;
    
    for (i = 1; i <= y; i++) sum /= i;
    
    return sum;
}

int main()
{
    int n, q, i, j, k;
    double sum = 0;
    int a[100000];
    int b[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        b[i] = a[i];
        dp[i][a[i]] = 1;
        
        if (a[i] == 0) sum++;
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        x--;
        y--;
        
        sum -= dp[x][0];
        
        for (j = 0; j <= a[x]; j++) {
            if (dp[x][j] == 0) continue;
            
            for (k = 1; k <= j && k <= z; k++) {
                dp[x][j - k] += dp[x][j] * comb(j, k) * comb(b[x] - j, z - k) / comb(b[x], z);
            }
            
            dp[x][j] *= comb(b[x] - j, z) / comb(b[x], z);
        }
        
        b[x] -= z;
        b[y] += z;
        
        sum += dp[x][0];
        
        printf("%.12lf\n", sum);
    }
    
    return 0;
}