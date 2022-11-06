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

int n, m, k, d, p, q;
int INV;

ll solve(int x, int y) {
    if (x % (2 * d) != y % (2 * d)) return LINF;
    int add = x % (2 * d);
    x -= add, y -= add;
    x /= (2 * d), y /= (2 * d);
    ll t = ((y - x) % q + q) % q;
    //assert(t >= 0);
    t *= INV;
    t %= q;
    return (t * p + x) * (2 * d) + add;

}

ll min(ll a, ll b, ll c, ll e) {
    return min(min(a, b), min(c, e));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    d = __gcd(n, m);
    p = n / d, q = m / d;
    INV = -1;
    //cerr << p << ' ' << q << '\n';
    forn(i, 0, q) if (ll(i) * p % q == 1 % q) INV = i;
    assert(INV != -1);
    //cerr << INV << '\n';
    while (k--) {
        int x, y;
        cin >> x >> y;
        ll ans = min(solve(x, y), solve(x, 2 * m - y), solve(2 * n - x, y), solve(2 * n - x, 2 * m - y));
        if (ans == LINF) ans = -1;
        cout << ans << '\n';
    }

}