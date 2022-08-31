#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> cover(n);
    
    std::vector<std::tuple<int, int, int>> endpoints;
    
    std::set<int> s{-1, n};
    
    for (int i = 0; i < m; i++) {
        int x, l, r;
        std::cin >> x >> l >> r;
        x--;
        l--;
        
        endpoints.emplace_back(l, x, -1);
        endpoints.emplace_back(r, x, 1);
    }
    
    std::sort(endpoints.begin(), endpoints.end());
    
    std::vector<std::pair<int, int>> edges;
    
    std::vector<int> add, del;
    
    for (int l = 0, r; l < 2 * m; l = r) {
        r = l;
        while (r < 2 * m && std::get<0>(endpoints[l]) == std::get<0>(endpoints[r])) {
            r++;
        }
        
        add.clear();
        del.clear();
        
        for (int i = l; i < r; i++) {
            auto [v, x, t] = endpoints[i];
            
            if (t == -1) {
                if (cover[x] == 0) {
                    add.push_back(x);
                }
                cover[x]++;
            } else {
                cover[x]--;
                if (cover[x] == 0) {
                    del.push_back(x);
                }
            }
        }
        
        for (auto x : del) {
            s.erase(x);
        }
        
        for (auto x : add) {
            auto it = s.insert(x).first;
            
            edges.emplace_back(*std::prev(it), x);
            edges.emplace_back(x, *std::next(it));
        }
    }
    
    std::sort(edges.begin(), edges.end());
    
    std::vector<int> dp(n + 2), g(n + 2);
    
    for (auto [u, v] : edges) {
        if (dp[u + 1] + 1 > dp[v + 1]) {
            dp[v + 1] = dp[u + 1] + 1;
            g[v + 1] = u + 1;
        }
    }
    
    int res = n + 1 - dp[n + 1];
    
    std::cout << res << "\n";
    
    std::vector<int> list;
    
    for (int i = n + 1; i > 0; i = g[i]) {
        for (int j = g[i] + 1; j < i; j++) {
            list.push_back(j);
        }
    }
    
    for (int i = 0; i < res; i++) {
        std::cout << list[i] << " \n"[i == res - 1];
    }
    
    return 0;
}