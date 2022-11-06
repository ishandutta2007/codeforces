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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int x, s;
    cin >> x >> s;
    vector<int> a(m), b(m);
    forn(i, 0, m) cin >> a[i];
    forn(i, 0, m) cin >> b[i];
    vector<int> c(k), d(k);
    forn(i, 0, k) cin >> c[i];
    forn(i, 0, k) cin >> d[i];
    ll ans = 1ll * n * x;
    for (int i = 0; i < m; ++i) {
        int rest = s - b[i];
        if (rest < 0) continue;
        auto it = upper_bound(d.begin(), d.end(), rest);
        if (it == d.begin()) {
            ans = min(ans, 1ll * n * a[i]);
            continue;
        }
        --it;
        int j = it - d.begin();
        if (c[j] >= n) ans = 0;
        else {
            ans = min(ans, 1ll * (n - c[j]) * a[i]);
        }
    }
    auto it = upper_bound(d.begin(), d.end(), s);
    if (it == d.begin()) {
        ans = min(ans, 1ll * n * x);
    } else {
        --it;
        int j = it - d.begin();
        if (c[j] >= n) ans = 0;
        else {
            ans = min(ans, 1ll * (n - c[j]) * x);
        }
    }
    cout << ans << '\n';
}