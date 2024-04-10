#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<bool> vis(n);
    std::vector<int> dis(n), parent(n, -1);
    std::function<int(int)> dfs = [&](int u) {
        int h = dis[u];
        for (auto v : adj[u]) {
            if (vis[v] || v == parent[u]) {
                continue;
            }
            parent[v] = u;
            dis[v] = dis[u] + 1;
            h = std::max(dfs(v), h);
        }
        return h;
    };
    dfs(0);
    
    int v = std::max_element(dis.begin(), dis.end()) - dis.begin();
    
    for (int i = v; i != -1; i = parent[i]) {
        vis[i] = true;
    }
    
    std::vector<int> a;
    for (int i = v; i != -1; i = parent[i]) {
        dis[i] = 0;
        a.push_back(dfs(i));
    }
    
    std::reverse(a.begin(), a.end());
    int m = a.size();
    
    std::vector<int> suf(m);
    for (int i = m - 1; i >= 0; i--) {
        suf[i] = a[i] + i;
        if (i < m - 1) {
            suf[i] = std::max(suf[i + 1], suf[i]);
        }
    }
    
    std::vector<int> pre(m);
    for (int i = 0; i < m; i++) {
        pre[i] = a[i] + i;
        if (i > 0) {
            pre[i] = std::max(pre[i - 1], pre[i]);
        }
    }
    
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        b[i] = a[i] - i;
    }
    
    std::deque<int> q;
    int l = std::max(a[0], a[1] + 1), r = suf[1] + 1;
    
    for (int x = 1, j = 1, k = 2; x <= n; x++) {
        auto judge = [&]() {
            while (k <= j && k < x + j - k) {
                assert(!q.empty());
                if (q.front() == k) {
                    q.pop_front();
                }
                k++;
            }
            
            l = std::max(pre[k - 1], q.empty() ? 0 : b[q.front()] + x + j);
            r = suf[j] + std::min(0, x - j);
        };
        
        judge();
        int ans = std::max(l, r);
        while (l < r && j < m - 1) {
            j++;
            while (!q.empty() && b[j] > b[q.back()]) {
                q.pop_back();
            }
            q.push_back(j);
            judge();
            ans = std::min(ans, std::max(l, r));
        }
        
        std::cout << ans << " \n"[x == n];
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