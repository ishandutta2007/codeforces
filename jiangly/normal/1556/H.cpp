#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    int d[k];
    for (int i = 0; i < k; i++) {
        std::cin >> d[i];
    }
    
    int adj[50][50];
    for (int i = 0; i < n; i++) {
        adj[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            std::cin >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }
    
    // find useful edges
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < k; i++) {
        for (int j = k; j < n; j++) {
            edges.emplace_back(i, j);
        }
    }
    {
        std::vector<std::pair<int, int>> p;
        for (int i = k; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                p.emplace_back(i, j);
            }
        }
        std::sort(p.begin(), p.end(), [&](auto i, auto j) {
            return adj[i.first][i.second] < adj[j.first][j.second];
        });
        
        DSU g(n);
        for (auto [u, v] : p) {
            if (g.merge(u, v)) {
                edges.emplace_back(u, v);
            }
        }
    }
    
    int res = 1E9;
    
    int deg[k];
    std::memset(deg, 0, sizeof(deg));
    
    int m = edges.size();
    int u[m], v[m], cost[m];
    for (int i = 0; i < m; i++) {
        std::tie(u[i], v[i]) = edges[i];
        cost[i] = adj[u[i]][v[i]];
    }
    
    std::function<void(int, int, DSU)> dfs = [&](int x, int c, DSU g) {
        if (x == k * k) {
            for (int i = 0; i < k; i++) {
                if (deg[i] > d[i]) {
                    return;
                }
            }
            
            bool used[m];
            std::memset(used, 0, sizeof(used));
            
            while (true) {
                std::pair<int, int> dis[m];
                int pre[m];
                int cur[k];
                for (int i = 0; i < k; i++) {
                    cur[i] = deg[i];
                }
                std::fill(dis, dis + m, std::make_pair(1E9, 1E9));
                std::memset(pre, -1, sizeof(pre));
                DSU g1 = g;
                for (int i = 0; i < m; i++) {
                    if (used[i]) {
                        if (u[i] < k) {
                            cur[u[i]]++;
                        }
                        g1.merge(u[i], v[i]);
                    }
                }
                
                std::vector<int> adj[m];
                
                std::queue<int> q;
                bool inq[m];
                std::memset(inq, 0, sizeof(inq));
                
                for (int i = 0; i < m; i++) {
                    if (!used[i]) {
                        if (!g1.same(u[i], v[i])) {
                            dis[i] = {cost[i], 0};
                            inq[i] = true;
                            q.push(i);
                        }
                    }
                }
                for (int i = 0; i < m; i++) {
                    if (!used[i]) {
                        continue;
                    }
                    g1 = g;
                    for (int j = 0; j < m; j++) {
                        if (used[j] && i != j) {
                            g1.merge(u[j], v[j]);
                        }
                    }
                    for (int j = 0; j < m; j++) {
                        if (!used[j]) {
                            if (!g1.same(u[j], v[j])) {
                                adj[i].push_back(j);
                            }
                            bool nice = true;
                            for (int x = 0; x < k; x++) {
                                if (cur[x] - (u[i] == x) + (u[j] == x) > d[x]) {
                                    nice = false;
                                }
                            }
                            if (nice) {
                                adj[j].push_back(i);
                            }
                        }
                    }
                }
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    inq[u] = false;
                    for (auto v : adj[u]) {
                        std::pair<int, int> nd = {dis[u].first + (used[v] ? -1 : 1) * cost[v], dis[u].second + 1};
                        if (dis[v] > nd) {
                            dis[v] = nd;
                            pre[v] = u;
                            if (!inq[v]) {
                                inq[v] = true;
                                q.push(v);
                            }
                        }
                    }
                }
                
                int t = -1;
                for (int i = 0; i < m; i++) {
                    if (used[i] || dis[i].first == 1E9) {
                        continue;
                    }
                    bool nice = true;
                    for (int x = 0; x < k; x++) {
                        if (cur[x] + (u[i] == x) > d[x]) {
                            nice = false;
                        }
                    }
                    if (nice && (t == -1 || dis[i] < dis[t])) {
                        t = i;
                    }
                }
                
                if (t == -1) {
                    break;
                }
                
                for (int i = t; i != -1; i = pre[i]) {
                    used[i] ^= 1;
                }
            }
            
            int val = c;
            for (int i = 0; i < m; i++) {
                if (used[i]) {
                    g.merge(u[i], v[i]);
                    val += cost[i];
                }
            }
            for (int i = 0; i < n; i++) {
                if (!g.same(0, i)) {
                    return;
                }
            }
            res = std::min(res, val);
            
            return;
        }
        dfs(x + 1, c, g);
        int u = x / k, v = x % k;
        if (u < v && g.merge(u, v)) {
            deg[u]++;
            deg[v]++;
            dfs(x + 1, c + adj[u][v], g);
            deg[u]--;
            deg[v]--;
        }
    };
    dfs(0, 0, DSU(n));
    
    std::cout << res << "\n";
    
    return 0;
}