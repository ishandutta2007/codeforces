#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 210;

int res[nmax][nmax];
vector<pii> g[nmax][nmax];
int deg[nmax][nmax];

int dx[2 * nmax], dy[2 * nmax];

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int init_x, init_y;
    int r;
    cin >> init_x >> init_y >> r;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        dx[i] = x - i - 1;
        dy[i] = y;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        dx[i + n] = x;
        dy[i + n] = y - i - 1;
    }
    //int q = n + m;

    queue<pii> qu;
    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            bool stuck = true;

            for (int k = 0; k < n; ++k) {
                if (k + 1 > i) {
                    break;
                }
                if (i + dx[k] + j + dy[k] > r) {
                    continue;
                }
                stuck = false;
                break;
            }

            for (int k = 0; k < m; ++k) {
                if (k + 1 > j) {
                    break;
                }
                if (i + dx[k + n] + j + dy[k + n] > r) {
                    continue;
                }
                stuck = false;
                break;
            }

            if (stuck) {
                res[i][j] = -1;
                qu.push({i, j});
            }
        }
    }

    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k + 1 > i) {
                    break;
                }
                if (i + dx[k] + j + dy[k] <= r) {
                    g[i + dx[k]][j + dy[k]].pb({i, j});
                    ++deg[i][j];
                }
            }

            for (int k = 0; k < m; ++k) {
                if (k + 1 > j) {
                    break;
                }
                if (i + dx[k + n] + j + dy[k + n] <= r) {
                    g[i + dx[k + n]][j + dy[k + n]].pb({i, j});
                    ++deg[i][j];
                }
            }
        }
    }

    while (!qu.empty()) {
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (pii p : g[x][y]) {
            --deg[p.first][p.second];
            if (deg[p.first][p.second] == 0) {
                res[p.first][p.second] = res[x][y] - 1;
                qu.push(p);
            }
        }
    }

    res[0][0] = 0;
    qu.push({0, 0});
    while (!qu.empty()) {
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (pii p : g[x][y]) {
            if (res[p.first][p.second] == 0) {
                res[p.first][p.second] = res[x][y] + 1;
                qu.push(p);
            }
        }
    }

    int x = init_x, y = init_y;

    if (res[x][y] == 0) {
        cout << "Draw\n";
    } else if (res[x][y] > 0) {
        cout << "Ivan\n";
        cout << res[x][y] << "\n";
    } else {
        cout << "Zmey\n";
        cout << -res[x][y] << "\n";
    }
    // 1 1 10 1 0 0 1 0 0

}