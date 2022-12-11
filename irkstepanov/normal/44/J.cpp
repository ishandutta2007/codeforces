#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1010;

string a[nmax];
int id[nmax][nmax];

int ans[nmax][nmax];

vector<vector<int> > g, gr; // 1 -- hor, 0 -- ver

void add(int u, int v) {
    g[u].pb(v);
    g[v ^ 1].pb(u ^ 1);
    gr[v].pb(u);
    gr[u ^ 1].pb(v ^ 1);
}

vector<bool> used;
vector<int> order;
vector<int> compId;

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }
    order.pb(v);
}

void dfs2(int v, int x) {
    compId[v] = x;
    for (int to : gr[v]) {
        if (compId[to] == -1) {
            dfs2(to, x);
        }
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int cc = 0;

    memset(id, -1, sizeof(id));
    vector<pii> t;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'b') {
                id[i][j] = cc++;
                t.pb({i, j});
            }
        }
    }

    g.resize(2 * cc);
    gr.resize(2 * cc);

    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != 'b') {
                continue;
            }
            if (i - 1 < 0 || i + 1 >= n || a[i - 1][j] != 'w' || a[i + 1][j] != 'w') {
                add(2 * id[i][j], 2 * id[i][j] + 1);
            } else {
                
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'b') {
                        add(2 * id[i][j], 2 * id[x][y]);
                    }
                }

                if (i - 2 >= 0 && a[i - 2][j] == 'b') {
                    add(2 * id[i][j], 2 * id[i - 2][j] + 1);
                }
                if (i + 2 < n && a[i + 2][j] == 'b') {
                    add(2 * id[i][j], 2 * id[i + 2][j] + 1);
                }
            }

            if (j - 1 < 0 || j + 1 >= m || a[i][j - 1] != 'w' || a[i][j + 1] != 'w') {
                add(2 * id[i][j] + 1, 2 * id[i][j]);
            } else {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'b') {
                        add(2 * id[i][j] + 1, 2 * id[x][y] + 1);
                    }
                }

                if (j - 2 >= 0 && a[i][j - 2] == 'b') {
                    add(2 * id[i][j] + 1, 2 * id[i][j - 2]);
                }
                if (j + 2 < m && a[i][j + 2] == 'b') {
                    add(2 * id[i][j] + 1, 2 * id[i][j + 2]);
                }
            }
        }
    }

    used.assign(2 * cc, false);
    compId.assign(2 * cc, -1);
    for (int i = 0; i < 2 * cc; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(all(order));
    int x = 0;
    for (int v : order) {
        if (compId[v] == -1) {
            dfs2(v, x);
            ++x;
        }
    }

    for (int i = 0; i < cc; ++i) {
        if (compId[i * 2] == compId[i * 2 + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < cc; ++i) {
        int val;
        if (compId[2 * i] > compId[2 * i + 1]) {
            val = 0;
        } else {
            val = 1;
        }
        val ^= 1;
        int x = t[i].first, y = t[i].second;
        if (val == 0) {
            int d = x % 2;
            ans[x][y - 1] = ans[x][y] = ans[x][y + 1] = d;
        } else {
            int d = 2 + x % 2;
            ans[x - 1][y] = ans[x][y] = ans[x + 1][y] = d;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '.' && ans[i][j] == -1) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] == -1) {
                cout << '.';
            } else {
                cout << char(ans[i][j] + 'a');
            }
        }
        cout << '\n';
    }

}