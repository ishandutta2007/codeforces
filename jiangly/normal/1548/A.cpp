#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::set<int>> s(n);
    
    int ans = n;
    
    auto add = [&](int u, int v) {
        if (!s[u].empty() && *s[u].rbegin() > u) {
            ans++;
        }
        s[u].insert(v);
        if (!s[u].empty() && *s[u].rbegin() > u) {
            ans--;
        }
    };
    auto del = [&](int u, int v) {
        if (!s[u].empty() && *s[u].rbegin() > u) {
            ans++;
        }
        s[u].erase(v);
        if (!s[u].empty() && *s[u].rbegin() > u) {
            ans--;
        }
    };
    
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        add(u, v);
        add(v, u);
    }
    
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            add(u, v);
            add(v, u);
        } else if (op == 2) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            del(u, v);
            del(v, u);
        } else {
            std::cout << ans << "\n";
        }
    }
    
    return 0;
}