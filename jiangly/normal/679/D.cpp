#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> dis(n, std::vector<int>(n, 1e9));
    std::vector<int> deg(n);
    
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        dis[u][v] = dis[v][u] = 1;
        ++deg[u];
        ++deg[v];
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    double ans = 0;
    for (int s = 0; s < n; ++s) {
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](int u, int v) {
            return dis[s][u] < dis[s][v];
        });
        double sum = 0;
        std::vector<double> f(n);
        for (int l = 0, r; l < n; l = r) {
            r = l;
            while (r < n && dis[s][p[l]] == dis[s][p[r]]) {
                ++r;
            }
            double res = 1.0 / n;
            std::vector<int> q;
            for (int i = l; i < r; ++i) {
                int u = p[i];
                for (int v = 0; v < n; ++v) {
                    if (dis[u][v] == 1) {
                        if (f[v] == 0) {
                            q.push_back(v);
                        }
                        f[v] += 1.0 / n / deg[u];
                    }
                }
            }
            for (int t = 0; t < n; ++t) {
                std::sort(q.begin(), q.end(), [&](int u, int v) {
                    return dis[t][u] < dis[t][v];
                });
                double sum = 0;
                for (int l = 0, r; l < int(q.size()); l = r) {
                    r = l;
                    while (r < int(q.size()) && dis[t][q[l]] == dis[t][q[r]]) {
                        ++r;
                    }
                    double mx = 0;
                    for (int i = l; i < r; ++i) {
                        mx = std::max(mx, f[q[i]]);
                    }
                    sum += mx;
                }
                res = std::max(res, sum);
            }
            for (auto u : q) {
                f[u] = 0;
            }
            sum += res;
        }
        ans = std::max(ans, sum);
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    
    return 0;
}