#include <cstdio>
#include <algorithm>

using namespace std;

char s[1000][1001];
int sum[1001][1001];
int a[1001][1001];
int b[1001][1001];

int main()
{
    int n, m, x = -1, y = -1, p, q, ans = 1e9, i, j;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
            
            if (s[i][j] == 'X') sum[i + 1][j + 1]++;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                x = i;
                y = j;
                
                break;
            }
        }
        
        if (j < m) break;
    }
    
    for (i = 0; x + i < n; i++) {
        if (s[x + i][y] == '.') break;
    }
    
    p = i;
    
    for (i = 0; y + i < m; i++) {
        if (s[x][y + i] == '.') break;
    }
    
    q = i;
    
    if (sum[x + p][y + q] - sum[x + p][y] - sum[x][y + q] + sum[x][y] != p * q) {
        puts("-1");
        
        return 0;
    }
    
    if (sum[n][m] == p * q) {
        printf("%d\n", min(p, q));
        
        return 0;
    }
    
    if (x + p < n) {
        int c = -1;
        
        for (i = y; i < y + q; i++) {
            if (s[x + p][i] == 'X') {
                c = y + q - i;
                
                break;
            }
        }
        
        if (c != -1) {
            int x1 = x, y1 = y, f = 0;
            
            while (1) {
                a[x1][y1]++;
                a[x1 + p][y1]--;
                a[x1][y1 + c]--;
                a[x1 + p][y1 + c]++;
                
                if (x1 + p < n && s[x1 + p][y1] == 'X') {
                    x1++;
                } else if (y1 + c < m && s[x1][y1 + c] == 'X') {
                    y1++;
                } else {
                    break;
                }
            }
            
            for (i = 0; i < n; i++) {
                for (j = 1; j < m; j++) {
                    a[i][j] += a[i][j - 1];
                }
            }
            
            for (i = 0; i < m; i++) {
                for (j = 1; j < n; j++) {
                    a[j][i] += a[j - 1][i];
                }
            }
            
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (a[i][j] <= 0 && s[i][j] == 'X') f = 1;
                    if (a[i][j] > 0 && s[i][j] == '.') f = 1;
                }
            }
            
            if (f == 0) ans = min(ans, p * c);
        }
    }
    
    if (y + q < m) {
        int c = -1;
        
        for (i = x; i < x + p; i++) {
            if (s[i][y + q] == 'X') {
                c = x + p - i;
                
                break;
            }
        }
        
        if (c != -1) {
            int x1 = x, y1 = y, f = 0;
            
            while (1) {
                b[x1][y1]++;
                b[x1 + c][y1]--;
                b[x1][y1 + q]--;
                b[x1 + c][y1 + q]++;
                
                if (x1 + c < n && s[x1 + c][y1] == 'X') {
                    x1++;
                } else if (y1 + q < m && s[x1][y1 + q] == 'X') {
                    y1++;
                } else {
                    break;
                }
            }
            
            for (i = 0; i < n; i++) {
                for (j = 1; j < m; j++) {
                    b[i][j] += b[i][j - 1];
                }
            }
            
            for (i = 0; i < m; i++) {
                for (j = 1; j < n; j++) {
                    b[j][i] += b[j - 1][i];
                }
            }
            
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (b[i][j] <= 0 && s[i][j] == 'X') f = 1;
                    if (b[i][j] > 0 && s[i][j] == '.') f = 1;
                }
            }
            
            if (f == 0) ans = min(ans, q * c);
        }
    }
    
    if (ans == 1e9) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}