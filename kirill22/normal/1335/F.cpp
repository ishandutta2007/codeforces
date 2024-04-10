#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0, f = 0;
vector<int> g;
vector<vector<int>> cycle;
vector<vector<int>> g2;
vector<int> used;
int get(int x, int y) {
    return y + x * m;
}

void FIND(int v) {
    vector<int> p = {v};
    int pr = g[v];
    while (pr != v) {
        p.push_back(pr);
        pr = g[pr];
    }
    cycle.push_back(p);
}

void dfs(int v) {
    used[v] = 1;
    int y = g[v];
    if (used[y] == 0) dfs(y);
    else if (used[y] == 1) {
        FIND(y);
    }
    used[v] = 2;
}

vector<pair<int, int>> z;

void dfs2(int v, int d) {
    if (!used[v]) {
        z.push_back({v, d});
    }
    used[v] = 1;
    for (auto el : g2[v]) {
        if (!used[el]) {
            dfs2(el, d + 1);
        }
    }
}

void solve() {
    cin >> n >> m;
    g.clear();
    cycle.clear();
    used.clear();
    int color[n * m];
    g2.clear();
    g.resize(n * m);
    g2.resize(n * m);
    ans = f = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            color[get(i, j)] = (c - '0');
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int x = get(i, j);
            if (c == 'U') {
                g[x] = (get(i - 1, j));
                g2[get(i - 1, j)].push_back(x);
            }
            if (c == 'D') {
                g[x] = (get(i + 1, j));
                g2[get(i + 1, j)].push_back(x);
            }
            if (c == 'R') {
                g[x] = (get(i, j + 1));
                g2[get(i, j + 1)].push_back(x);
            }
            if (c == 'L') {
                g[x] = (get(i, j - 1));
                g2[get(i, j - 1)].push_back(x);
            }
        }
    }
    used.resize(n * m, 0);
    for (int i = 0; i < n * m; i++) {
        if (used[i] == 0) dfs(i);
    }
    used.clear();
    used.resize(n * m, 0);
    for (int j = 0; j < cycle.size(); j++) {
        vector<pair<int, int>> res(cycle[j].size());
        int s = cycle[j].size();
        ans += s;
        for (int i = 0; i < s; i++) {
            res[i] = {color[cycle[j][i]], cycle[j][i]};
            used[cycle[j][i]] = 1;
        }
        int l = -1;
        for (auto el : cycle[j]) {
            z.clear();
            l++;
            dfs2(el, 0);
            for (auto el : z) {
                int x = ((l - el.second) % s + s) % s;
                if (res[x].first == 1 && color[el.first] == 0) {
                    res[x] = {color[el.first], el.first};
                }
            }
        }
        for (auto el : res) {if (el.first == 0) f++;}
    }
    cout << ans << " " << f << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}