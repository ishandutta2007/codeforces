#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

ll fact[400001], invfact[400001];

ll modpow(ll n, ll e = MOD - 2) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x;
    x %= MOD;
    if(e%2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= 400000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = modpow(fact[i]);
    }
    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i <= n; i++) {
        ll x;
        cin >> x;
        int a = i + 1, b = x - 1;
        ll binom = invfact[a] * invfact[b];
        binom %= MOD;
        binom *= fact[a+b];
        binom %= MOD;
        ans += binom;
        ans %= MOD;
    }
    cout << ans << '\n';
}