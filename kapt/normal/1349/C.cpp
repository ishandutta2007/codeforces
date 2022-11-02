#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5, INF = 1e9;
string arr[MAXN];
vector<int> g[MAXN * MAXN];
int col[MAXN * MAXN];
int sz[MAXN * MAXN];
vector<int> e[MAXN * MAXN];
int d[MAXN * MAXN];

int ssz;

void dfs(int v, int c) {
    ssz++;
    col[v] = c;
    for (auto u : g[v]) {
        if (col[u] == 0) {
            dfs(u, c);
        }
    }
}

main() {
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (arr[i][j] == arr[i][j - 1]) {
                g[i * m + j].push_back(i * m + j - 1);
                g[i * m + j - 1].push_back(i * m + j);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == arr[i - 1][j]) {
                g[i * m + j].push_back(i * m + j - m);
                g[i * m + j - m].push_back(i * m + j);
            }
        }
    }
    int c = 0;
    for (int i = 0; i < n * m; ++i) {
        if (col[i] == 0) {
            c++;
            ssz = 0;
            dfs(i, c);
            sz[c] = ssz;
        }
    }
    deque<int> q;
    fill(d, d + n * m + 1, INF);
    for (int i = 0; i < n * m + 1; ++i) {
        if (sz[i] > 1) {
            d[i] = 0;
            q.push_back(i);
        }
        if (i >= m) {
            if (col[i] != col[i - m]) {
                e[col[i]].push_back(col[i - m]);
                e[col[i - m]].push_back(col[i]);
            }
        }
        if (i % m >= 1) {
            if (col[i] != col[i - 1]) {
                e[col[i]].push_back(col[i - 1]);
                e[col[i - 1]].push_back(col[i]);
            }
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : e[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push_back(u);
            }
        }
    }
    while (t--) {
        int x, y;
        int64_t p;
        cin >> x >> y >> p;
        x--; y--;
        int v = col[x * m + y];
        /// cout << "d: " << d[v] << endl;
        if (d[v] == INF || d[v] >= p) {
            cout << arr[x][y] << '\n';
            continue;
        }
        p -= d[v];
        if (p % 2 == 0) {
            cout << arr[x][y] << '\n';
        } else {
            if (arr[x][y] == '1') {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        }
    }
    return 0;
}