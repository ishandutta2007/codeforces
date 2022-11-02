#include <cstdio>
#include <algorithm>

using namespace std;

int sum[2001][2001];
char s[2000][2001];

int main()
{
    int n, m, x1 = 1e9, y1 = 1e9, x2 = 0, y2 = 0, c = 0, p, i, j, k;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'w') {
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
                c++;
                
                sum[i + 1][j + 1]++;
            }
            
            sum[i + 1][j + 1] = sum[i + 1][j + 1] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
        }
    }
    
    p = max(x2 - x1, y2 - y1);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i + p > n || j + p > m) break;
            
            if (sum[i + p + 1][j + p + 1] - sum[i + p + 1][j] - sum[i][j + p + 1] + sum[i][j] != c) continue;
            
            if (p >= 2 && sum[i + p][j + p] - sum[i + p][j + 1] - sum[i + 1][j + p] + sum[i + 1][j + 1] != 0) continue;
            
            for (k = 0; k <= p; k++) {
                if (s[i][j + k] == '.') s[i][j + k] = '+';
                if (s[i + p][j + k] == '.') s[i + p][j + k] = '+';
                if (s[i + k][j] == '.') s[i + k][j] = '+';
                if (s[i + k][j + p] == '.') s[i + k][j + p] = '+';
            }
            
            for (i = 0; i < n; i++) printf("%s\n", s[i]);
            
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}