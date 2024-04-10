#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 1; i < n; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        e[--u].emplace_back(--v, l);
        e[v].emplace_back(u, l);
    }
    auto bfs = [&](int s) {
        queue<int> que;
        vector<int> dis(n, -1);
        que.push(s);
        dis[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto _e : e[u]) {
                int v, l;
                tie(v, l) = _e;
                if (dis[v] == -1) {
                    dis[v] = dis[u] + l;
                    que.push(v);
                }
            }
        }
        return max_element(dis.begin(), dis.end()) - dis.begin();
    };
    int rt = bfs(0);
    vector<array<int, 17>> parent(n);
    for (int i = 0; i < n; ++i)
        fill(parent[i].begin(), parent[i].end(), -1);
    vector<int> max_dis(n), dep(n), clc(n, -1), con(n), dis(n);
    function<int(int)> dfs = [&](int u) {
        for (int i = 1; (1 << i) <= dep[u]; ++i)
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
        int x = u;
        max_dis[u] = dis[u];
        for (auto _e : e[u]) {
            int v, l;
            tie(v, l) = _e;
            if (v == parent[u][0])
                continue;
            parent[v][0] = u;
            dep[v] = dep[u] + 1;
            dis[v] = dis[u] + l;
            v = dfs(v);
            con[v] += l;
            if (con[v] > con[x])
                x = v;
            max_dis[u] = max(max_dis[u], max_dis[v]);
        }
        return x;
    };
    dfs(rt);
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int u, int v) {return con[u] > con[v];});
    vector<int> ans(n + 1);
    for (int i = 0, s = 0; i < n; ++i) {
        ans[i + 1] = ans[i] + con[p[i]];
        for (int u = p[i]; u != -1 && clc[u] == -1; u = parent[u][0])
            clc[u] = i;
    }
    auto query = [&](int u, int k) {
        if (clc[u] < k)
            return ans[k];
        int v = u;
        for (int i = 16; i >= 0; --i)
            if (parent[v][i] != -1 && clc[parent[v][i]] >= k)
                v = parent[v][i];
        v = parent[v][0];
        return ans[k] + max_dis[u] - dis[v] - min(dis[v], min(ans[k] - ans[k - 1], max_dis[v] - dis[v]));
    };
    int lastans = 0;
    for (int i = 0; i < q; ++i) {
        int u, k;
        cin >> u >> k;
        u = (--u + lastans) % n;
        k = (--k + lastans) % n + 1;
        cout << (lastans = query(u, min(n, 2 * k - 1))) << "\n";
    }
    return 0;
}