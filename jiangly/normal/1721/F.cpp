#include <bits/stdc++.h>

using i64 = long long;
template<class T>
struct Flow {
    const int n;
    struct Edge {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int nx, ny, m, q;
    std::cin >> nx >> ny >> m >> q;
    const int N = nx + ny;
    
    Flow<int> flow(nx + ny + 2);
    const int S = nx + ny, T = S + 1;
    std::vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        flow.addEdge(x[i], nx + y[i], 2);
    }
    for (int i = 0; i < nx; i++) {
        flow.addEdge(S, i, 1);
    }
    for (int i = 0; i < ny; i++) {
        flow.addEdge(nx + i, T, 1);
    }
    
    int M = flow.maxFlow(S, T);
    i64 sum = 0;
    std::vector<int> e(N, -1);
    for (int i = 0; i < m; i++) {
        if (flow.e[2 * i].cap == 1) {
            e[x[i]] = e[y[i] + nx] = i;
            sum += i + 1;
        }
    }
    
    std::vector<int> cut(N);
    std::vector<int> seq;
    for (int i = 0; i < N; i++) {
        cut[i] = (flow.h[i] == -1);
        if ((i < nx && cut[i]) || (i >= nx && !cut[i])) {
            seq.push_back(i);
        }
    }
    
    while (q--) {
        int o;
        std::cin >> o;
        
        if (o == 1) {
            int u = seq.back();
            seq.pop_back();
            
            std::cout << 1 << "\n";
            if (u < nx) {
                std::cout << u + 1 << "\n";
            } else {
                std::cout << -(u - nx + 1) << "\n";
            }
            int j = e[u];
            sum -= j + 1;
            e[x[j]] = e[y[j] + nx] = -1;
            std::cout << sum << std::endl;
            M--;
        } else {
            std::cout << M << "\n";
            for (int i = 0; i < nx; i++) {
                if (e[i] != -1) {
                    std::cout << e[i] + 1 << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}