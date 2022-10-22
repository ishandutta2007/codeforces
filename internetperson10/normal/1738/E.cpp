#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll fact[100001];
ll invfact[100001];

ll modpow(ll n, ll e) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x;
    x %= MOD;
    if(e % 2 == 1) {
        x *= n;
        x %= MOD;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> nums(n+1, 0);
    map<ll, int> m;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i] += nums[i-1];
        if(i != n) m[nums[i]]++;
    }
    ll ans = 1;
    for(auto p : m) {
        if(p.first * 2 > nums[n]) continue;
        if(p.first * 2 == nums[n]) {
            ans *= modpow(2, p.second);
        }
        else {
            // Calculate sum (XC0)(YC0) + (XC1)(YC1) + (XC2)(YC2) + ...
            ll tot = 0;
            ll x = p.second;
            ll y = m[nums[n] - p.first];
            for(int i = 0; i <= min(x, y); i++) {
                ll binom = fact[x] * fact[y];
                binom %= MOD;
                binom *= ((invfact[i] * invfact[i]) % MOD);
                binom %= MOD;
                binom *= ((invfact[x-i] * invfact[y-i]) % MOD);
                binom %= MOD;
                tot += binom;
                tot %= MOD;
            }
            ans *= tot;
        }
        ans %= MOD;
    }
    cout << ans << '\n';
    m.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = modpow(fact[i], MOD - 2);
    }
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}