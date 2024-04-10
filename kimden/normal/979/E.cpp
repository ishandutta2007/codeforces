#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


ll dp[51][51][51];
const ll mod = 1000000007;

ll binpow(ll x, ll p){
    ll ans = 1;
    while(p){
        if(p & 1LL){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        p >>= 1LL;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    if(c[0] != 0) {
        dp[1][0][1] = 1;
    }
    if(c[0] != 1) {
        dp[1][1][0] = 1;
    }
    for(int i = 1; i < n; ++i){
        for (int k = 0; k < i + 1; ++k) {
            for (int l = 0; l < i + 1; ++l) {
                if (dp[i][k][l]) {
                    if(c[i] != 0){
                        dp[i + 1][k][l + 1] = (dp[i + 1][k][l + 1] + (dp[i][k][l] * ll(k == 0 ? binpow(2, i) : binpow(2, i - 1)))) % mod;
                        dp[i + 1][k][l] = (dp[i + 1][k][l] + (dp[i][k][l] * ll(k == 0 ? 0 : binpow(2, i - 1)))) % mod;
                    }
                    if(c[i] != 1){
                        dp[i + 1][k + 1][l] = (dp[i + 1][k + 1][l] + (dp[i][k][l] * ll(l == 0 ? binpow(2, i) : binpow(2, i - 1)))) % mod;
                        dp[i + 1][k][l] = (dp[i + 1][k][l] + (dp[i][k][l] * ll(l == 0 ? 0 : binpow(2, i - 1)))) % mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= n; ++k) {
        for (int l = 0; l <= n; ++l) {
            if((k % 2) ^ (l % 2) == p)
                ans = (ans + dp[n][k][l]) % mod;
        }
    }
    cout << ans << endl;
}