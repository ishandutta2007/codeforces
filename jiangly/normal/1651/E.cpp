#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    std::vector<bool> vis(2 * n);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        
        std::vector<int> a;
        auto dfs = [&](auto self, int u) -> void {
            a.push_back(u);
            vis[u] = true;
            for (auto v : adj[u]) {
                if (vis[v]) {
                    continue;
                }
                self(self, v);
            }
        };
        dfs(dfs, i);
        
        int N = a.size();
        int ml = n, Ml = -1, mr = n, Mr = -1;
        for (int i = 0; i < N; i++) {
            if (a[i] < n) {
                ml = std::min(ml, a[i]);
                Ml = std::max(Ml, a[i]);
            } else {
                mr = std::min(mr, a[i] - n);
                Mr = std::max(Mr, a[i] - n);
            }
        }
        ans += 1LL * N / 2 * (ml + 1) * (n - Ml) * (mr + 1) * (n - Mr);
        
        for (int i = 0; i < N; i++) {
            int ml = n, Ml = -1, mr = n, Mr = -1;
            for (int j = 0; j < N; j++) {
                int x = a[(i + j) % N];
                if (x < n) {
                    ml = std::min(ml, x);
                    Ml = std::max(Ml, x);
                } else {
                    mr = std::min(mr, x - n);
                    Mr = std::max(Mr, x - n);
                }
                
                if (j % 2 == 1) {
                    int ex = a[(i - 1 + N) % N];
                    int l1 = ml, r1 = Ml, l2 = mr, r2 = Mr;
                    if (i % 2 == 1) {
                        std::swap(l1, l2);
                        std::swap(r1, r2);
                    } else {
                        ex -= n;
                    }
                    
                    if (ex < l2) {
                        ans += 1LL * (l1 + 1) * (n - r1) * (l2 - ex) * (n - r2);
                    }
                    if (ex > r2) {
                        ans += 1LL * (l1 + 1) * (n - r1) * (l2 + 1) * (ex - r2);
                    }
                }
            }
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}