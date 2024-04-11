#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 4444;
int t[N], d[N];
long long f[N][N], ans;
int n, k;

int main() {
    //freopen("in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d%d", t + i, d + i);
    
    if (n == k) {
        cout << 86400 << endl;
        return 0;
    }
    
    memset(f, 63, sizeof(f));
    
    ans = max(0, t[k] - 1);
    f[0][0] = t[0] + d[0];  
    f[0][1] = 1; 
    
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= k; ++j) {
            f[i][j] = max(f[i - 1][j], (long long) t[i]) + d[i];
            if (j > 0) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            
            int lost = k - j;
            if (i + lost + 1 >= n) ans = max(ans, 86401 - f[i][j]);
            else ans = max(ans, t[i + lost + 1] - f[i][j]);
        }
    
    cout << ans << endl;
    
    return 0;
}