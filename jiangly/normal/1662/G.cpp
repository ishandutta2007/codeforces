#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> p(n, -1);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }
    
    std::vector<int> siz(n);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        siz[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(dfs, v, u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs, 0, -1);
    
    auto find = [&](auto find, int u, int p) -> int {
        for (auto v : adj[u]) {
            if (v == p || 2 * siz[v] <= n) {
                continue;
            }
            return find(find, v, u);
        }
        return u;
    };
    int r = find(find, 0, -1);
    
    dfs(dfs, r, -1);
    
    std::vector<int> cnt(n);
    for (auto v : adj[r]) {
        cnt[siz[v]]++;
    }
    
    std::bitset<1000000> b;
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) {
            int k = 1;
            while (k <= cnt[i]) {
                b |= b << (i * k);
                cnt[i] -= k;
                k *= 2;
            }
            if (cnt[i] > 0) {
                b |= b << cnt[i];
            }
        }
    }
    
    i64 ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            ans = std::max(ans, 1LL * i * (n - i - 1));
        }
    }

    ans += std::accumulate(siz.begin(), siz.end(), 0LL);
    std::cout << ans << "\n";
    
    return 0;
}