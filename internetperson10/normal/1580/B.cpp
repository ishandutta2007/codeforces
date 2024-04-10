#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD;

ll dp[101][101][101];
ll binom[102][102];
ll fact[102];

ll calc(ll n, ll m, ll k) {
    if(dp[n][m][k] >= 0) return dp[n][m][k];
    if(n == 0) return dp[n][m][k] = 1;
    if(m == 0) {
        if(k == 0) return dp[n][m][k] = fact[n];
        else return dp[n][m][k] = 0;
    }
    if(m == 1) k--;
    if(k < 0) return dp[n][m][k+1] = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int j = n - i - 1;
        for(int x = 0; x <= min(i, (int)k); x++) {
            int y = k - x;
            if(y > j) continue;
            ll g = calc(i, m-1, x) * calc(j, m-1, y);
            g %= MOD;
            g *= binom[n-1][i];
            g %= MOD;
            ans += g; 
            ans %= MOD;
        }
    }
    if(m == 1) k++;
    return dp[n][m][k] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k >> MOD;
    if(MOD == 1) {
        cout << 0 << '\n';
        return 0;
    }
    binom[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) binom[i][j] = 1;
            else binom[i][j] = (binom[i-1][j-1] + binom[i-1][j])%MOD;
        }
    }
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = ((ll)(fact[i-1]) * (ll)i) % MOD;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int x = 0; x <= k; x++) {
                dp[i][j][x] = -1;
            }
        }
    }
    cout << calc(n, m, k) << '\n';
}