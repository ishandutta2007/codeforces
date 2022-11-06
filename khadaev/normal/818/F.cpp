#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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
    int q;
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        /*int k;
        for (k = 1; ; ++k) {
            if (k * (k - 1) / 2 >= n - k) break;
        }*/
        ll l = 0, r = 1e9;
        while (l + 1 < r) {
            ll m = (l + r) / 2;
            if (m * (m - 1) / 2 >= n - m)
                r = m;
            else
                l = m;
        }
        ll ans = 2 * (n - r);
        --r;
        ans = max(ans, r * (r - 1) / 2 + (n - r));
        cout << ans << '\n';
    }
}