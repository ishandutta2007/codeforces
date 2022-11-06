//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

void solve() {
    int n;
    cin >> n;
    int minx = 0, maxx = 0, miny = 0, maxy = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    minx = -minx;
    miny = -miny;
    cout << 2 * (minx + maxx + miny + maxy) << endl;
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}