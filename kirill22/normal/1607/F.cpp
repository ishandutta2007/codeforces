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

const int N = 2000;
char a[N][N];
int cycle[N][N], usd[N][N];
int used[N][N];
int n, m;
pii d[N * N];

void dfs(int x, int y) {
    used[x][y] = 1;
    if (cycle[x][y]) {
        return;
    }
    int i = x, j = y;
    if (a[i][j] == 'R') {
        j++;
    } else if (a[i][j] == 'L') {
        j--;
    } else if (a[i][j] == 'D') {
        i++;
    } else {
        i--;
    }
    if (i < 0 || j < 0 || i >= n || j >= m) {
        cycle[x][y] = 1;
        return;
    }
    if (!used[i][j]) {
        dfs(i, j);
    }
    cycle[x][y] = cycle[i][j] + 1;
}

mt19937 gen(time(0));

void solve() {
    cin >> n >> m;
    forn (i, n) forn (j, m) {
        cin >> a[i][j];
        cycle[i][j] = used[i][j] = usd[i][j] = 0;
    }
    int t = 0;
    forn (x, n) forn (y, m) {
        int i = x, j = y;
        t++;
        if (used[i][j]) continue;
        int D = 0;
        while (1) {
            used[i][j] = 1;
            d[D++] = {i, j};
            assert(D <= n * m);
            usd[i][j] = t;
            if (a[i][j] == 'R') {
                j++;
            } else if (a[i][j] == 'L') {
                j--;
            } else if (a[i][j] == 'D') {
                i++;
            } else {
                i--;
            }
            if (i < 0 || j < 0 || i >= n || j >= m) break;
            if (usd[i][j] == t) {
                int v = D - 1;
                while (v >= 0 && d[v] != make_pair(i, j)) v--;
                assert((d[v] == make_pair(i, j)));
                int cnt = D - v;
                for (int u = v; u < D; u++) {
                    cycle[d[u].fi][d[u].se] = cnt;
                }
                break;
            }
            if (used[i][j]) break;
        }
    }
    forn (i, n) forn (j, m) {
        used[i][j] = 0;
    }
    forn (x, n) forn (y, m) {
        int i = x, j = y;
        if (!cycle[i][j]) {
            int D = 0;
            int p = 0;
            while (1) {
                d[D++] = {i, j};
                if (a[i][j] == 'R') {
                    j++;
                } else if (a[i][j] == 'L') {
                    j--;
                } else if (a[i][j] == 'D') {
                    i++;
                } else {
                    i--;
                }
                if (i < 0 || j < 0 || i >= n || j >= m) {
                    break;
                }
                if (cycle[i][j]) {
                    p = cycle[i][j];
                    break;
                }
            }
            while (D > 0) {
                D--;
                cycle[d[D].fi][d[D].se] = p + 1;
                p++;
            }
        }
    }
    int x = 0, y = 0;
    forn (i, n) forn (j, m) {
        if (cycle[i][j] > cycle[x][y]) x = i, y = j;
    }
    cout << x + 1 << " " << y + 1 << " " << cycle[x][y] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}