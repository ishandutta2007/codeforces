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

void fail() {
    cout << "-1\n";
    exit(0);
}

ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    forn(i, 0, n) cin >> p[i];
    forn(i, 0, n) --p[i];
    vector<int> u(n);
    forn(i, 0, n) {
        if (u[p[i]]) fail();
        u[p[i]] = 1;
    }
    ll ans = 1;
    forn(i, 0, n) u[i] = 0;
    forn(i, 0, n) {
        if (u[i]) continue;
        int j = i, sz = 0;
        do {
            u[j] = 1;
            j = p[j];
            ++sz;
        } while (j != i);
        if (sz % 2 == 0) sz /= 2;
        ans = lcm(ans, sz);
    }
    cout << ans << '\n';
}