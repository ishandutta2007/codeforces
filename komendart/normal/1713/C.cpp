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

void solve(int n) {
    vector<int> ans;
    for (int cur = n - 1; cur >= 0;) {
        int s = 0;
        while (s * s < cur) {
            ++s;
        }
        int x = s * s - cur;
        assert(x <= cur);
        for (int i = x; i <= cur; ++i) {
            ans.push_back(i);
        }
        cur = x - 1;
    }
    reverse(ans.begin(), ans.end());
    for (auto i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
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
        int n;
        cin >> n;
        solve(n);
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}