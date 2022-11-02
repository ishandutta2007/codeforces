#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, ans = 1e9, i, j;
    int a[100][100];
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    if (m <= 20) {
        int b[100][2];
        
        for (i = 0; i < n; i++) {
            int x = 0, y = 0;
            
            for (j = 0; j < m; j++) {
                x *= 2;
                x += a[i][j];
                y *= 2;
                y += 1 - a[i][j];
            }
            
            b[i][0] = x;
            b[i][1] = y;
        }
        
        for (i = 0; i < (1 << m); i++) {
            int c = __builtin_popcount(i);
            int x = b[0][0];
            int sum = 0;
            
            if (c > k || c > ans) continue;
            
            for (j = 0; j < m; j++) {
                if ((i >> j) & 1) x ^= (1 << j);
            }
            
            sum += c;
            
            for (j = 1; j < n; j++) sum += min(__builtin_popcount(x ^ b[j][0]), __builtin_popcount(x ^ b[j][1]));
            
            if (sum <= k) ans = min(ans, sum);
        }
    } else {
        int sum = 0;
        
        for (i = 1; i < n; i++) {
            int x = 0;
            
            for (j = 0; j < m; j++) {
                if (a[i][j] == a[0][j]) x++;
            }
            
            if (x < m - x) {
                for (j = 0; j < m; j++) a[i][j] = 1 - a[i][j];
            }
        }
        
        for (i = 0; i < m; i++) {
            int x = 0;
            
            for (j = 0; j < n; j++) {
                if (a[j][i] == 0) x++;
            }
            
            sum += min(x, n - x);
        }
        
        if (sum <= k) ans = sum;
    }
    
    if (ans == 1e9) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}