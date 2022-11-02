#include <cstdio>
#include <algorithm>

using namespace std;

int mod = 777777777;
int a[4][4];
long long d[(1 << 18) - 1][4][4];

void update(int k, int x)
{
    int i, j, l, r;
    
    k += (1 << 17) - 1;
    
    for (i = 0; i < 4; i++) d[k][i][i] = 0;
    
    if (x >= 0) {
        d[k][x][x] = 1;
    } else {
        for (i = 0; i < 3; i++) d[k][i][i] = 1;
    }
    
    while (k > 0) {
        k = (k - 1) / 2;
        
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                d[k][i][j] = 0;
            }
        }
        
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (a[i][j] == 0) continue;
                
                for (l = 0; l < 4; l++) {
                    if (d[k * 2 + 1][l][i] == 0) continue;
                    
                    for (r = 0; r < 4; r++) {
                        if (d[k * 2 + 2][j][r] == 0) continue;
                        
                        d[k][l][r] += d[k * 2 + 1][l][i] * d[k * 2 + 2][j][r] % mod;
                        
                        if (d[k][l][r] >= mod) d[k][l][r] -= mod;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, i, j, k, l, r;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < 4; i++) a[i][3] = 1;
    
    for (i = (1 << 17) - 1; i < (1 << 17) - 1 + n; i++) {
        for (j = 0; j < 3; j++) d[i][j][j] = 1;
    }
    
    for (; i < (1 << 18) - 1; i++) d[i][3][3] = 1;
    
    for (i = (1 << 17) - 2; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (a[j][k] == 0) continue;
                
                for (l = 0; l < 4; l++) {
                    if (d[i * 2 + 1][l][j] == 0) continue;
                    
                    for (r = 0; r < 4; r++) {
                        if (d[i * 2 + 2][k][r] == 0) continue;
                        
                        d[i][l][r] += d[i * 2 + 1][l][j] * d[i * 2 + 2][k][r] % mod;
                        
                        if (d[i][l][r] >= mod) d[i][l][r] -= mod;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        int x, y;
        long long sum = 0;
        
        scanf("%d %d", &x, &y);
        
        update(x - 1, y - 1);
        
        for (j = 0; j < 3; j++) {
            sum += d[0][j][3];
            
            if (sum >= mod) sum -= mod;
        }
        
        printf("%d\n", (int)sum);
    }
    
    return 0;
}