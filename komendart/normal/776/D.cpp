#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int r[maxn];
vector<int> e[maxn];
vector< pair<int, int> > graph[maxn];

bool fail = false;
char used[maxn];
int color[maxn];

void dfs(int v, int c) {
    //cerr <<v << ' ' << c << endl;
    if (used[v]) {
        if (color[v] != c) fail = true;
        return;
    }
    used[v] = true;
    color[v] = c;
    for (auto e: graph[v]) {
        dfs(e.first, c ^ e.second);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        for (int j = 0; j < len; ++j) {
            int t; cin >> t; --t;
            e[t].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        int a = e[i][0];
        int b = e[i][1];
        graph[a].push_back({b, r[i] ^ 1});
        graph[b].push_back({a, r[i] ^ 1});
        //cerr << ' ' << a << ' ' << b << ' ' << r[i] << endl;
    }

    for (int i = 0; i < m; ++i) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }

    if (fail) cout << "NO\n";
    else cout << "YES\n";
}