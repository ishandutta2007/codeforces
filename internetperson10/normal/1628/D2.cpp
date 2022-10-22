#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

ll modpow(ll n, ll e = MOD - 2) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x; x%= MOD;
    if(e%2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

ll fact[1000001], invfact[1000001];

ll binom(ll n, ll k) {
    ll x = fact[n];
    ll y = invfact[k] * invfact[n-k];
    y %= MOD;
    return (x*y) % MOD;
}

// DO NOT SUBMIT

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[1000000] = modpow(fact[1000000]);
    for(int i = 999999; i > 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll ans = 0;
        for(int i = 0; i < m; i++) {
            ll ct = binom(n, i);
            ans += (ct * (2 * (m - i)));
            ans %= MOD;
        }
        ans *= modpow(modpow(2), n);
        ans %= MOD;
        ans *= k;
        ans %= MOD;
        cout << ans << '\n';
    }
}