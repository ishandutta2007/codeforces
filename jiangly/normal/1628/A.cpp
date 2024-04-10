#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    
    std::vector<int> ans;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        
        int x = 0;
        
        while (true) {
            auto it = std::lower_bound(pos[x].begin(), pos[x].end(), i);
            
            if (it == pos[x].end()) {
                break;
            }
            
            j = std::max(j, *it + 1);
            
            x++;
        }
        
        i = j;
        
        ans.push_back(x);
    }
    
    std::cout << ans.size() << "\n";
    for (int i = 0; i < int(ans.size()); i++) {
        std::cout << ans[i] << " \n"[i == int(ans.size()) - 1];
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