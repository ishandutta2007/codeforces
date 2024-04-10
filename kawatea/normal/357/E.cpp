#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, sum = 0, ans = 1e9, i, j;
    int a[5] = {0};
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x]++;
        
        sum += x;
    }
    
    for (i = 1; i <= n; i++) {
        int x, y, z = 0, w = 0;
        int b[5];
        
        if (i * 4 < sum) continue;
        
        if (i * 3 > sum) break;
        
        x = 4 * i - sum;
        y = i - x;
        
        for (j = 0; j < 5; j++) b[j] = a[j];
        
        for (j = 4; j > 0; j--) {
            if (y == 0) break;
            
            if (b[j] >= y) {
                w += (4 - j) * y;
                b[j] -= y;
                y = 0;
            } else {
                w += (4 - j) * b[j];
                y -= b[j];
                b[j] = 0;
            }
        }
        
        z += w;
        
        for (j = 1; j < 4; j++) {
            if (w == 0) break;
            
            if (b[j] * j >= w) {
                b[j] -= (w + j - 1) / j;
                b[w % j]++;
                w = 0;
            } else {
                w -= b[j] * j;
                b[j] = 0;
            }
        }
        
        for (j = 4; j > 0; j--) {
            if (x == 0) break;
            
            if (b[j] >= x) {
                if (j == 4) z += x;
                
                b[j] -= x;
                x = 0;
            } else {
                if (j == 4) z += b[j];
                
                x -= b[j];
                b[j] = 0;
            }
        }
        
        for (j = 1; j <= 4; j++) z += b[j] * j;
        
        ans = min(ans, z);
    }
    
    if (ans == 1e9) ans = -1;
    
    printf("%d\n", ans);
    
    return 0;
}