#include <stdio.h>

char s[500][501];
int a[500][500];
int sum[501][501];
int b[500][500][10];

int get(int a, int b, int c, int d)
{
    return sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b];
}

int main()
{
    int n, m, ans = 0, p, i, j, k, l;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
            
            if (s[i][j] == '*') sum[i + 1][j + 1]++;
            
            if (s[i][j] == '*') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    
    for (i = 0; i < 16; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                for (l = 0; l < 10; l++) {
                    b[j][k][l] = 0;
                }
            }
        }
        
        for (j = 0; j < n - 1; j++) {
            for (k = 0; k < m - 1; k++) {
                if (a[j][k] == ((i >> 0) & 1) && a[j + 1][k] == ((i >> 1) & 1) && a[j][k + 1] == ((i >> 2) & 1) && a[j + 1][k + 1] == ((i >> 3) & 1)) b[j][k][0] = 1;
            }
        }
        
        for (j = 0, p = 2; j < 10; j++, p *= 2) {
            for (k = 0; k + p * 2 <= n; k++) {
                for (l = 0; l + p * 2 <= m; l++) {
                    if ((i >> 0) & 1) {
                        if (get(k, l, k + p, l + p) != p * p) continue;
                    } else {
                        if (b[k][l][j] == 0) continue;
                    }
                    
                    if ((i >> 1) & 1) {
                        if (get(k + p, l, k + p * 2, l + p) != p * p) continue;
                    } else {
                        if (b[k + p][l][j] == 0) continue;
                    }
                    
                    if ((i >> 2) & 1) {
                        if (get(k, l + p, k + p, l + p * 2) != p * p) continue;
                    } else {
                        if (b[k][l + p][j] == 0) continue;
                    }
                    
                    if ((i >> 3) & 1) {
                        if (get(k + p, l + p, k + p * 2, l + p * 2) != p * p) continue;
                    } else {
                        if (b[k + p][l + p][j] == 0) continue;
                    }
                    
                    b[k][l][j + 1] = 1;
                    
                    ans++;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}