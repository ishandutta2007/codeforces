#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array
#define vec vector

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
    int n, k;
    cin >> n >> k;
    k--;
    vvi g(n);
    vi a(n);
    rep(i, n) cin >> a[i];
    int x = 0;
    each(y, a) x ^= y;
    vi dp(n);
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (x == 0) {
        cout << "YES\n";
        return;
    }
    if (k == 1) {
        cout << "NO\n";
        return;
    }
    function<int(int, int)> dfs = [&](int v, int p) {
        int y = a[v];
        int r = 0;
        each(u, g[v]) {
            if (u == p) continue;
            y ^= dfs(u, v);
            r += dp[u];
        }
        if (y == 0 && r >= 1) r++;
        if (y == x) ckmax(r, 1);
        dp[v] = r;
        return y;
    };
    dfs(0, -1);
    if (dp[0] >= 2) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(20-7) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}