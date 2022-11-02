#include <cstdio>
#include <algorithm>

using namespace std;

int dp[20][10];
int dp2[20][10][4];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int c, j, k, p, q, r;
        long long n;
        int a[20];
        
        scanf("%I64d", &n);
        
        for (j = 0; n > 0; j++) {
            a[j] = n % 10;
            n /= 10;
        }
        
        c = j;
        
        for (j = 0; j <= c; j++) {
            for (k = 0; k < 10; k++) {
                dp[j][k] = 0;
            }
        }
        
        dp[0][0] = 1;
        
        for (j = 0; j < c; j++) {
            for (k = 0; k < 10; k++) {
                if (dp[j][k] == 0) continue;
                
                for (p = 0; p <= 6; p++) {
                    for (q = 0; p + q <= 6; q++) {
                        int x, y;
                        
                        r = 6 - p - q;
                        
                        x = (q * 4 + r * 7 + k) / 10;
                        y = (q * 4 + r * 7 + k) % 10;
                        
                        if (y != a[j]) continue;
                        
                        dp[j + 1][x] = 1;
                        dp2[j + 1][x][0] = k;
                        dp2[j + 1][x][1] = p;
                        dp2[j + 1][x][2] = q;
                        dp2[j + 1][x][3] = r;
                    }
                }
            }
        }
        
        if (dp[c][0] == 0) {
            puts("-1");
        } else {
            int x = c, y = 0;
            long long ans[6] = {0};
            
            while (x) {
                for (j = 0; j < dp2[x][y][1]; j++) {
                    ans[j] *= 10;
                }
                
                for (; j < dp2[x][y][1] + dp2[x][y][2]; j++) {
                    ans[j] *= 10;
                    ans[j] += 4;
                }
                
                for (; j < dp2[x][y][1] + dp2[x][y][2] + dp2[x][y][3]; j++) {
                    ans[j] *= 10;
                    ans[j] += 7;
                }
                
                y = dp2[x][y][0];
                x--;
            }
            
            for (j = 0; j < 6; j++) {
                if (j > 0) putchar(' ');
                
                printf("%I64d", ans[j]);
            }
            
            puts("");
        }
    }
    
    return 0;
}