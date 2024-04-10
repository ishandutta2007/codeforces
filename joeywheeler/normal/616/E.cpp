#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

ll n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    ll res = ((n % MOD) * (m % MOD)) % MOD;
    for (ll k = 1; k <= min(m,n); ) {
        // [k,n/(n/k))
        ll l = k, r = n / (n / k);
        r = min(r, m);
        ll g = (n / l) % MOD; ll t = (l+r) % MOD; ll u = (r-l+1) % MOD; ll v = (MOD+1)/2;
        res += MOD - g * t % MOD * u % MOD * v % MOD; res %= MOD;
        k = r+1;
    }
    printf("%lld\n", res);
}