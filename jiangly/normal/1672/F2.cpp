#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n), cnt(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    
    std::vector<std::vector<int>> adj(n);
    int x = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back(b[i]);
    }
    
    std::vector<int> s;
    auto dfs = [&](auto dfs, int u, int p) -> void {
        while (!adj[u].empty()) {
            int x = adj[u].back();
            adj[u].pop_back();
            dfs(dfs, x, u);
        }
        if (p != -1) {
            s.push_back(p);
        }
    };
    dfs(dfs, x, -1);
    
    if (int(s.size()) != n) {
        std::cout << "WA\n";
        return;
    }
    
    std::vector<std::vector<int>> e(n);
    std::vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != x) {
            e[s[i]].push_back(s[i - 1]);
            deg[s[i - 1]]++;
        }
    }
    
    std::vector<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push_back(i);
        }
    }
    for (int i = 0; i < int(q.size()); i++) {
        int u = q[i];
        for (auto v : e[u]) {
            if (!--deg[v]) {
                q.push_back(v);
            }
        }
    }
    
    if (int(q.size()) == n) {
        std::cout << "AC\n";
    } else {
        std::cout << "WA\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}