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

int ask(int a, int b) {
    cout << "?" << ' ' << a << ' ' << b << endl;
    int x;
    cin >> x;
    if (x == 0) return 0;
    else if (x == 1) return 1;
    else return -1;
}

int solve(int n, const vector<int>& a) {
    if (n == 1) {
        if (ask(a[0], a[1]) > 0) {
            return {a[0]};
        } else {
            return {a[1]};
        }
    } else if (n == 2) {
        int sign = ask(a[0], a[2]);
        if (sign == 0) {
            return solve(1, {a[1], a[3]});
        } else if (sign > 0) {
            return solve(1, {a[0], a[3]});
        } else {
            return solve(1, {a[2], a[1]});
        }
    } else {
        vector<int> ans;
        for (int i = 0; i < sz(a); i += 4) {
            vector<int> subarray{a[i], a[i + 1], a[i + 2], a[i + 3]};
            ans.push_back(solve(2, subarray));
        }
        return solve(n - 2, ans);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        a[i] = i + 1;
    }
    int ans = solve(n, a);
    cout << "!" << ' ' << ans << endl;
}

signed main() {
#ifdef LOCAL
    //assert(freopen("input.txt", "r", stdin));
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