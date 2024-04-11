//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

const int inf = 1e10;

void solve() {
    int n, d;
    cin >> n;
    d = 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    //sort(a.begin(), a.end());
    ll zero_cost = 0;
    ll start_negative_slope = 0;
    multiset<ll> f;
    for (int i = 0; i < n; ++i) {
        a[i] = i * d - inf - a[i];
        if (a[i] > 0) {
            zero_cost += a[i];
            a[i] = 0;
        }
        zero_cost -= a[i];
        ++start_negative_slope;
        f.insert(-a[i]);
        f.insert(-a[i]);
        while (sz(f) > start_negative_slope) {
            f.erase(f.find(*f.rbegin()));
        }
    }
    ll ans = zero_cost;
    ll slope = -start_negative_slope;
    ll prev = 0;
    for (auto x: f) {
        ans += slope * (x - prev);
        ++slope;
        prev = x;
    }
    cout << ans << '\n';
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
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}