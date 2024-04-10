#include <stdio.h>

int dp[2][4][2][31][31][31];

int main()
{
    int n, h, m = 1000000009, sum = 0, i, j, k, l, p, q, r, s;
    int a[4], b[3];
    
    scanf("%d %d", &n, &h);
    
    dp[0][0][0][0][0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l <= h; l++) {
                    for (p = l; p <= h; p++) {
                        for (q = p; q <= h; q++) {
                            if (dp[i & 1][j][k][l][p][q] == 0) continue;
                            
                            for (r = 0; r < 4; r++) a[r] = -1;
                            
                            if (k == 0) {
                                a[j] = 0;
                            } else {
                                a[j] = h;
                            }
                            
                            r = 0;
                            
                            if (a[r] >= 0) r++;
                            a[r++] = l;
                            
                            if (a[r] >= 0) r++;
                            a[r++] = p;
                            
                            if (a[r] >= 0) r++;
                            a[r++] = q;
                            
                            for (r = 0; r < 4; r++) {
                                int c = 0;
                                
                                for (s = 0; s < 4; s++) {
                                    if (s == r) continue;
                                    
                                    b[c] = a[s] + 1;
                                    
                                    if (b[c] > h) b[c] = h;
                                    
                                    c++;
                                }
                                
                                if (b[0] > b[1]) {
                                    int tmp = b[0];
                                    b[0] = b[1];
                                    b[1] = tmp;
                                }
                                
                                if (b[0] > b[2]) {
                                    int tmp = b[0];
                                    b[0] = b[2];
                                    b[2] = tmp;
                                }
                                
                                if (b[1] > b[2]) {
                                    int tmp = b[1];
                                    b[1] = b[2];
                                    b[2] = tmp;
                                }
                                
                                if (a[r] == h) {
                                    dp[(i + 1) & 1][r][1][b[0]][b[1]][b[2]] += dp[i & 1][j][k][l][p][q];
                                    
                                    if (dp[(i + 1) & 1][r][1][b[0]][b[1]][b[2]] >= m) dp[(i + 1) & 1][r][1][b[0]][b[1]][b[2]] -= m;
                                } else {
                                    dp[(i + 1) & 1][r][0][b[0]][b[1]][b[2]] += dp[i & 1][j][k][l][p][q];
                                    
                                    if (dp[(i + 1) & 1][r][0][b[0]][b[1]][b[2]] >= m) dp[(i + 1) & 1][r][0][b[0]][b[1]][b[2]] -= m;
                                }
                            }
                            
                            dp[i & 1][j][k][l][p][q] = 0;
                        }
                    }
                }
            }
        }
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k <= h; k++) {
                for (l = 0; l <= h; l++) {
                    for (r = 0; r <= h; r++) {
                        if (j == 0 || (k > 0 && k < h) || (l > 0 && l < h) || (r > 0 && r < h)) {
                            sum += dp[n & 1][i][j][k][l][r];
                            
                            if (sum >= m) sum -= m;
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}