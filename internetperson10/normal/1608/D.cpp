#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*
 * BB
 * BW
 * WB
 * WW
 * left B = right W, left W = right B
 * sum B = sum W = n (actually implied by above)
 */

const ll MOD = 998244353;

ll fact[100001];
ll invf[100001];

ll modpow(ll n, ll e = MOD-2) {
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
    fact[0] = invf[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        fact[i] = (fact[i-1] * i)%MOD;
        invf[i] = modpow(fact[i]);
    }
    int n;
    cin >> n;
    int xb, xw, yb, yw, sa, sx, sy;
    xb = xw = yb = yw = sa = sx = sy = 0;
    bool ch = true;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s.at(0) == 'B') xb++;
        if(s.at(0) == 'W') xw++;
        if(s.at(1) == 'B') yb++;
        if(s.at(1) == 'W') yw++;
        if(s.at(0) == s.at(1)) {
            if(s.at(0) == '?') sa++;
            else ch = false;
        }
        else {
            if(s.at(0) == 'B' || s.at(1) == 'W') sx++;
            else sy++;
        }
    }
    xw = n - xb - xw;
    yb = n - yb - yw;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        ll x = i - xb;
        ll y = i - yw;
        if(x < 0) continue;
        if(y < 0) continue;
        if(x > xw) continue;
        if(y > yb) continue;
        ll g = (fact[xw] * ((invf[x] * invf[xw - x]) % MOD)) % MOD;
        ll h = (fact[yb] * ((invf[y] * invf[yb - y]) % MOD)) % MOD;
        g *= h;
        g %= MOD;
        ans += g;
        ans %= MOD;
    }
    if(ch) {
        ll g = 1;
        while(sa) {
            g *= 2;
            g %= MOD;
            sa--;
        }
        ans -= g;
        if(!sx) ans++;
        if(!sy) ans++;
        ans += MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}