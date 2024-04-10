#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
signed main(){
    int n, p, k;
    cin >> n >> p >> k;
    int dp[n+1][(1 << p)], s[n][p], pos[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pos[i] = i;
    }
    sort(pos, pos + n, [](const int& x, const int& y) -> bool { return a[x] > a[y]; });
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> s[i][j];
    
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < (1 << p); j++){
            dp[i][j] = -1;
        }
    }
    
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << p); j++){
            if (!~dp[i][j]) continue;
            int x = pos[i];
            int used = i - __builtin_popcount(j);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (used < k ? a[x] : 0));
            for (int k = 0; k < p; k++){
                if ((j >> k) & 1) continue;
                dp[i+1][j | (1 << k)] = max(dp[i+1][j | (1 << k)], dp[i][j] + s[x][k]);
            }
        }
    }
    cout << dp[n][(1 << p) - 1];
}