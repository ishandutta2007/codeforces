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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sum = 0;
    bool wasZero = false;
    int ans = 0;
    map<ll, int> cnt;
    int maxcnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || a[i] == 0) {
            if (!wasZero) {
                ans += cnt[0];
                wasZero = true;
            } else {
                ans += maxcnt;
            }
            cnt.clear();
            cnt[sum] = 1;
            maxcnt = 1;
        } else {
            sum += a[i];
            ++cnt[sum];
            maxcnt = max(maxcnt, cnt[sum]);
        }
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
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}