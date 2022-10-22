#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

ve<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
int n, m;
ve<ve<int>> g, dp;
ve<int> L, R, used, need;
ve<ve<char>> a;

int dfs(int v, int c) {
    used[v] = c;
    if (c == 1) L.pb(v);
    else R.pb(v);
    for (auto x : g[v]) {
        if (!used[x]) {
            int res = dfs(x, 3 - c);
            if (!res) return 0;
        }
        else if (used[x] == c) {
            return 0;
        }
    }
    return 1;
}

int id(int x, int y) {
    return x + y * n;
}

int check() {
    L.clear();
    R.clear();
    fill(all(used), 0);
    forn (i, n * m) {
        if (!used[i]) {
            if (!dfs(i, 1)) return 0;
        }
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.resize(n, vector<char> (m));
    forn (i, n) forn (j, m) cin >> a[i][j];
    g.resize(n * m);
    used.resize(n * m);
    dp.resize(n * m);
    forn (i, n) {
        forn (j, m) {
            if (a[i][j] == '.') continue;
            forn (v, 4) {
                int x = i + dx[v], y = j + dy[v];
                if (a[x][y] == '.') dp[id(i, j)].pb(id(x, y));
            }
            if (sz(dp[id(i, j)]) % 2 != 0) {
                cout << "NO";
                return 0;
            }
            if (sz(dp[id(i, j)]) == 2) {
                g[dp[id(i, j)][0]].pb(dp[id(i, j)][1]);
                g[dp[id(i, j)][1]].pb(dp[id(i, j)][0]);
            }
            if (sz(dp[id(i, j)]) == 4) {
                g[dp[id(i, j)][0]].pb(dp[id(i, j)][2]);
                g[dp[id(i, j)][2]].pb(dp[id(i, j)][0]);
                g[dp[id(i, j)][1]].pb(dp[id(i, j)][3]);
                g[dp[id(i, j)][3]].pb(dp[id(i, j)][1]);
            }
        }
    }
    if (!check()) {
        cout << "NO";
        return 0;
    }
    ve<ve<int>> ans(n, ve<int> (m));
    for (auto id : L) {
        ans[id % n][id / n] = 1;
    }
    for (auto id : R) {
        ans[id % n][id / n] = 4;
    }
    forn (i, n) forn (j, m) {
        if (a[i][j] == '.' && ans[i][j] == 0) {
            ans[i][j] = 1;
        }
    }
    forn (i, n) {
        forn (j, m) {
            if (a[i][j] == 'X') {
                ans[i][j] = 0;
                for (auto id : dp[id(i, j)]) {
                    ans[i][j] += ans[id % n][id / n];
                }
            }
        }
    }
    cout << "YES\n";
    forn (i, n) {
        forn (j, m) cout << ans[i][j] << " ";
        cout << '\n';
    }
}