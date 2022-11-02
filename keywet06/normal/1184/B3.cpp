#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

class flow {
   private:
    int n;
    vector<int> head, d, cur;
    vector<tuple<int, int64, int>> edge;
    bool bfs(int s, int t) {
        d.assign(n, -1);
        queue<int> que;
        que.push(s);
        d[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = head[u]; i != -1; i = get<2>(edge[i])) {
                int v = get<0>(edge[i]);
                if (get<1>(edge[i]) && d[v] == -1) {
                    d[v] = d[u] + 1;
                    if (v == t) return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int64 dfs(int u, int t, int64 f) {
        if (u == t) return f;
        int64 res = f;
        for (int &i = cur[u]; i != -1 && res; i = get<2>(edge[i])) {
            int v = get<0>(edge[i]);
            int64 &c = get<1>(edge[i]);
            if (d[v] == d[u] + 1 && c) {
                int64 aug = dfs(v, t, min(res, c));
                res -= aug;
                c -= aug;
                get<1>(edge[i ^ 1]) += aug;
            }
        }
        return f - res;
    }

   public:
    flow(int _n) {
        n = _n;
        head.assign(n, -1);
    }
    void insert_edge(int u, int v, int64 c) {
        edge.emplace_back(v, c, head[u]);
        head[u] = edge.size() - 1;
        edge.emplace_back(u, 0, head[v]);
        head[v] = edge.size() - 1;
    }
    int64 max_flow(int s, int t) {
        int64 flow = 0;
        while (bfs(s, t)) {
            cur = head;
            flow += dfs(s, t, 1e18);
        }
        return flow;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dis[u][v] = 1;
        dis[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int s, b, k;
    cin >> s >> b >> k;
    vector<tuple<int, int, int, int>> ship;
    vector<vector<pair<int, int>>> base(n);
    for (int i = 0; i < s; ++i) {
        int x, a, f, p;
        cin >> x >> a >> f >> p;
        --x;
        ship.emplace_back(x, a, f, p);
    }
    for (int i = 0; i < b; ++i) {
        int x, d, g;
        cin >> x >> d >> g;
        --x;
        base[x].emplace_back(d, g);
    }
    for (int i = 0; i < n; ++i) {
        sort(base[i].begin(), base[i].end());
        for (int j = 1; j < base[i].size(); ++j) {
            base[i][j].second = max(base[i][j].second, base[i][j - 1].second);
        }
    }
    vector<int64> gain(s);
    for (int i = 0; i < s; ++i) {
        int x = get<0>(ship[i]);
        int a = get<1>(ship[i]);
        int f = get<2>(ship[i]);
        int p = get<3>(ship[i]);
        gain[i] = -1e14;
        for (int j = 0; j < n; ++j) {
            if (dis[x][j] <= f && !base[j].empty() && a >= base[j][0].first) {
                gain[i] =
                    max(gain[i],
                        1ll * (--upper_bound(base[j].begin(), base[j].end(),
                                             make_pair(a, (int)1e9)))
                                    ->second -
                            p);
            }
        }
    }
    vector<bool> used(s);
    vector<pair<int, int>> rel;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        used[x] = true;
        used[y] = true;
        rel.emplace_back(x, y);
    }
    int cnt = 0;
    int64 ans = 0;
    vector<int> id(s, -1);
    for (int i = 0; i < s; ++i) {
        if (used[i]) {
            id[i] = cnt++;
        } else if (gain[i] > 0) {
            ans += gain[i];
        }
    }
    flow G(cnt + 2);
    int S = cnt;
    int T = cnt + 1;
    for (int i = 0; i < s; ++i) {
        if (used[i]) {
            if (gain[i] > 0) {
                G.insert_edge(S, id[i], gain[i]);
                ans += gain[i];
            } else if (gain[i] < 0) {
                G.insert_edge(id[i], T, -gain[i]);
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        G.insert_edge(id[rel[i].first], id[rel[i].second], 1e18);
    }
    ans -= G.max_flow(S, T);
    cout << ans << endl;
    return 0;
}