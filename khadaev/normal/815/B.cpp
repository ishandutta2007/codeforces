#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

void get(int n, int I) {
    vector<int> a(n, 0);
    a[I] = 1;
    int sgn = 1;
    while (n > 1) {
        vector<int> b(n - 1);
        forn(i, 0, n - 1) {
            b[i] = a[i] + a[i + 1] * sgn;
            sgn *= -1;
        }
        a = b;
        --n;
    }
    cout << a[0] << ' ';
}

const int N = 2e5 + 10;
ll fact[N];

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % MOD;
        y = y * y % MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll x) {
    return Pow(x, MOD - 2);
}

ll C(int n, int k) {
    return fact[n] * Inv(fact[k]) % MOD * Inv(fact[n - k]) % MOD;
}

ll solve() {
    fact[0] = 1;
    forn(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i, 0, n) cin >> a[i];
    int sgn = 1;
    while (sgn == -1 || n % 4 == 3) {
        vector<ll> b(n - 1);
        forn(i, 0, n - 1) {
            b[i] = a[i] + a[i + 1] * sgn;
            sgn *= -1;
        }
        a = b;
        --n;
    }
    ll ans = 0;
    if (n % 4 == 0) {
        forn(i, 0, n) {
            ll x = C(n / 2 - 1, i / 2);
            x = x * a[i] % MOD;
            if (i % 2) {
                ans -= x;
            } else {
                ans += x;
            }
        }
    } else if (n % 4 == 1) {
        forn(i, 0, n) {
            if (i % 2) continue;
            ll x = C(n / 2, i / 2);
            x = x * a[i] % MOD;
            ans += x;
        }
    } else {
        forn(i, 0, n) {
            ll x = C(n / 2 - 1, i / 2);
            x = x * a[i] % MOD;
            ans += x;
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << solve() << '\n';
    return 0;
    int n;
    cin >> n;
    forn(i, 0, n) get(n, i);
}