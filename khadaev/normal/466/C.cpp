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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    ll s = 0;
    forn(i, 0, n) s += a[i];
    if (s % 3) {
        cout << "0\n";
        return 0;
    }
    vector<int> pref(n), suff(n);
    ll t = 0;
    forn(i, 0, n) {
        t += a[i];
        if (s / 3 == t) pref[i] = 1;
    }
    pref[n - 1] = 0;
    t = 0;
    ford(i, 0, n) {
        t += a[i];
        if (s / 3 == t) suff[i] = 1;
    }
    suff[0] = 0;
    forn(i, 1, n) pref[i] += pref[i - 1];
    ll ans = 0;
    forn(i, 2, n) if (suff[i]) ans += pref[i - 2];
    cout << ans << '\n';
}