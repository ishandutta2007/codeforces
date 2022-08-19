#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int deg[n] = {};
    std::vector<int> adj[n];
    
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        while (k--) {
            int x;
            std::cin >> x;
            x--;
            adj[x].push_back(i);
            deg[i]++;
        }
    }
    
    int cnt = 0, res = 0;
    std::set<int> a;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            a.insert(i);
        }
    }
    
    while (!a.empty()) {
        res++;
        int c = 0;
        while (true) {
            auto it = a.lower_bound(c);
            if (it == a.end()) {
                break;
            }
            c = *it;
            cnt++;
            for (auto v : adj[c]) {
                if (--deg[v] == 0) {
                    a.insert(v);
                }
            }
            a.erase(it);
        }
    }
    
    if (cnt == n) {
        std::cout << res << "\n";
    } else {
        std::cout << "-1\n";
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