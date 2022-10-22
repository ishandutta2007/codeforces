#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
int dp[202][202][1010];
int a[202], n, t;

signed main(){
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j <= i; j++) 
            for (int k = 0; k <= t; k++) 
    if (dp[i][j][k]){
        ll s = j * a[i] + k, kek = dp[i][j][k];
        
        if (j && s - a[i] - (j - 1) * a[i + 1] <= t)
            (dp[i + 1][j - 1][s - a[i] - (j - 1) * a[i + 1]] += (ll) kek * j % mod) %= mod;
            
        if (s + a[i] - (j + 1) * a[i + 1] <= t)
            (dp[i + 1][j + 1][s + a[i] - (j + 1) * a[i + 1]] += kek) %= mod;
        
        if (s - j * a[i + 1] <= t)
            (dp[i + 1][j][s - j * a[i + 1]] += (ll) kek * (j + 1) % mod) %= mod;
    }
    ll ans = 0;
    for (int i = 0; i <= t; i++){
        (ans += dp[n][0][i]) %= mod;
    }
    cout << ans % mod;
}