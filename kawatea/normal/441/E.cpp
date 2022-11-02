#include <cstdio>
#include <algorithm>

using namespace std;

double dp[201][256][300][2];

int main()
{
    int x, k, p, i, j, l, r;
    double ans = 0;
    
    scanf("%d %d %d", &x, &k, &p);
    
    if (x & (1 << 8)) {
        int y = x >> 8, c = 0;
        
        while (y) {
            if (y % 2 == 0) break;
            
            y >>= 1;
            c++;
        }
        
        dp[0][x % 256][c][1] = 1;
    } else {
        int y = x >> 8, c = 0;
        
        while (y) {
            if (y % 2 == 1) break;
            
            y >>= 1;
            c++;
        }
        
        dp[0][x % 256][c][0] = 1;
    }
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < 256; j++) {
            for (l = 0; l < 300; l++) {
                for (r = 0; r < 2; r++) {
                    double p1, p2;
                    
                    if (dp[i][j][l][r] == 0) continue;
                    
                    p1 = dp[i][j][l][r] * p / 100;
                    p2 = dp[i][j][l][r] * (100 - p) / 100;
                    
                    if (j * 2 >= 256) {
                        if (r == 0) {
                            dp[i + 1][j * 2 % 256][1][1] += p1;
                        } else {
                            dp[i + 1][j * 2 % 256][l + 1][1] += p1;
                        }
                    } else {
                        if (r == 0) {
                            dp[i + 1][j * 2 % 256][l + 1][0] += p1;
                        } else {
                            dp[i + 1][j * 2 % 256][1][0] += p1;
                        }
                    }
                    
                    if (j + 1 == 256) {
                        if (r == 0) {
                            dp[i + 1][0][1][1] += p2;
                        } else {
                            dp[i + 1][0][l][0] += p2;
                        }
                    } else {
                        dp[i + 1][j + 1][l][r] += p2;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 300; j++) {
            for (l = 0; l < 2; l++) {
                if (i == 0) {
                    ans += dp[k][i][j][l] * (j * (1 - l) + 8);
                } else {
                    ans += dp[k][i][j][l] * __builtin_ctz(i);
                }
            }
        }
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}