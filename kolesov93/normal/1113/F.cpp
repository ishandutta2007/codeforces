#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const ll MOD = 1000000007;
const int N = 1000111;

ll fact[N];

ll pow(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return ans;
}

ll moddiv(ll x, ll y) {
    return (x * pow(y, MOD - 2)) % MOD;
}

ll C(ll n, ll k) {
    return moddiv(fact[n], (fact[k] * fact[n - k]) % MOD);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    for (ll length = 1; length < n; ++length) {
        if (length > m) break;
        ll path_decomposition = C(m - 1, length - 1);
        ll other_edges = pow(m, n - 1 - length);
        ll roots = length + 1;
        ll cayley = 1;
        if (n != roots) {
            cayley = (roots * pow(n, n - roots - 1)) % MOD;
        }

        ll other_roots = roots - 2;
        ll choose_roots = moddiv(fact[n - 2], fact[n - 2 - other_roots]);

        ll add = (path_decomposition * other_edges) % MOD;
        add = (add * cayley) % MOD;
        add = (add * choose_roots) % MOD;

        ans += add;
        //cerr << add << endl;
    }
    cout << ans % MOD << endl;

    return 0;
}