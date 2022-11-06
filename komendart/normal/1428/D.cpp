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

void out(vector<pair<int, int>> ans, int n) {
    cout << sz(ans) << '\n';
    for (auto [r, c]: ans) {
        cout << n - r << ' ' << c + 1 << '\n';
    }
    exit(0);
}

void fail() {
    cout << -1 << '\n';
    exit(0);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    
    vector<char> used(n);
    vector<int> ones;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            continue;
        } else if (a[i] == 1) {
            ans.emplace_back(n - 1 - i, i);
            ones.push_back(i);
        } else if (a[i] == 2) {
            if (ones.empty()) {
                fail();
            }
            int pos = ones.back();
            ans.emplace_back(n - 1 - pos, i);
            used[pos] = true;
            ones.pop_back();
        }
    }
    vector<int> positive;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 3) {
            if (positive.empty()) {
                fail();
            }
            int pos = positive.back();
            ans.emplace_back(n - 1 - i, i);
            ans.emplace_back(n - 1 - i, pos);
            positive.pop_back();
        }
        if (a[i] > 0 && !used[i]) {
            positive.push_back(i);
        }
    }
    out(ans, n);
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
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}