#include <cstdio>
#include <algorithm>

using namespace std;

int a[1 << 20][21];
int b[1000001];

int main()
{
    int n, m = 1000000007, i, j;
    long long ans;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x][0]++;
    }
    
    for (i = 1 << 20; i >= 0; i--) {
        for (j = 0; j < 20; j++) {
            if (a[i][j] == 0) continue;
            
            if (i & (1 << j)) a[i ^ (1 << j)][j] += a[i][j];
            
            a[i][j + 1] += a[i][j];
        }
    }
    
    b[0] = 1;
    
    for (i = 1; i <= 1000000; i++) b[i] = b[i - 1] * 2 % m;
    
    ans = b[n] - 1;
    
    for (i = 1; i < (1 << 20); i++) {
        int x = __builtin_popcount(i);
        int y = a[i][20];
        
        if (y == 0) continue;
        
        if (x & 1) {
            ans -= b[y] - 1;
            if (ans < 0) ans += m;
        } else {
            ans += b[y] - 1;
            if (ans >= m) ans -= m;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}