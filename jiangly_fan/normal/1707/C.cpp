#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    vector<vector<pair<int, int>>> G(n + 1);
    function<int(int)> fp = [&](int u) {
        return p[u] == u ? u : p[u] = fp(p[u]);
    };
    vector<pair<int, int>> e(m);
    vector<int> w(m);
    for (int i = 1; i <= n; i += 1) p[i] = i;
    vector<map<int, int>> mp(n + 1);
    for (int i = 0; i < m; i += 1) {
        auto& [x, y] = e[i];
        cin >> x >> y;
        int px = fp(x), py = fp(y);
        if (px != py) {
            w[i] = 1;
            p[px] = py;
            G[x].push_back({y, i});
            G[y].push_back({x, i});
            mp[x][y] = i;
            mp[y][x] = i;
        }
    }
    vector<int> dfn(n + 1), size(n + 1), pp(n + 1);
    vector<vector<pair<int, int>>> vp(n + 1);
    function<void(int)> DFS = [&](int u) {
        static int time = 0;
        dfn[u] = time += 1;
        for (auto [v, w] : G[u]) if (not dfn[v]) {
            DFS(v); 
            pp[v] = u;
            size[u] += size[v];
            vp[u].push_back({dfn[u] + size[u], v});
        }
        size[u] += 1;
    };
    vector<LL> ss(n + 1);
    DFS(1);
    for (int i = 0; i < m; i += 1)
        if (not w[i]) {
            auto [x, y] = e[i];
            if (dfn[x] > dfn[y]) swap(x, y);
            if (dfn[y] < dfn[x] + size[x]) {
                int s = lower_bound(vp[x].begin(), vp[x].end(), make_pair(dfn[y], 0))->second;
                if (mp[y][pp[y]] < i)
                    ss[y] += 1;
                if (mp[x][s] < i) {
                    ss[1] += 1;
                    ss[s] -= 1;
                }
            }
            else {
                if (mp[x][pp[x]] < i)
                    ss[x] += 1;
                if (mp[y][pp[y]] < i)
                    ss[y] += 1;
            }
        }
    function<void(int)> DFS2 = [&](int u) {
        for (auto [v, w] : G[u]) if (dfn[v] > dfn[u]) {
            ss[v] += ss[u];
            DFS2(v); 
        }
    };
    DFS2(1);
    for (int i = 1; i <= n; i += 1)
        cout << (ss[i] + n - 1 == m);
    return 0;
}