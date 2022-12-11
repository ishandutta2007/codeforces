#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(i, a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    if (a[0][0] == '1') {
        cout << "-1\n";
        return;
    }
    vector<ar<int, 4>> ans;
    for(int i = n - 1; i >= 1; --i) {
        rep(j, m) {
            if (a[i][j] == '1') {
                ans.push_back({i - 1, j, i, j});
            }
        }
    }
    for(int i = m - 1; i >= 1; --i) {
        if (a[0][i] == '1') {
            ans.push_back({0, i - 1, 0, i});
        }
    }
    cout << ans.size() << '\n';
    for(auto &[x, y, z, w] : ans) {
        cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << w + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}