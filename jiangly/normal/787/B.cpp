#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    bool yes = false;
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        std::set<int> s;
        bool bad = true;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;
            if (s.count(-x)) {
                bad = false;
            }
            s.insert(x);
        }
        if (bad) {
            yes = true;
        }
    }
    
    if (yes) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}