#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> f(50), g(50);
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int k = std::__lg(a[i]) + 1;
        if ((a[i] & (a[i] - 1)) == 0) {
            f[k]++;
        } else {
            g[k]++;
        }
    }
    
    f[0] = 1e9;
    for (int i = 1; i < 50; i++) {
        while (f[i] > f[i - 1]) {
            f[i]--;
            g[i]++;
        }
    }
    
    for (int i = 48; i >= 0; i--) {
        g[i] += g[i + 1];
    }
    
    std::vector<int> ans;
    
    while (true) {
        bool ok = true;
        for (int i = 0; i < 50; i++) {
            if (f[i] < g[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
        
        if (g[0] >= f[1]) {
            ans.push_back(g[0]);
        }
            
        int v = -1;
        
        for (int i = 1; i < 49; i++) {
            if (f[i] == g[i]) {
                break;
            }
            if (f[i] > f[i + 1]) {
                v = i;
                break;
            }
        }
        
        if (v < 0) {
            break;
        }
        
        f[v]--;
        for (int i = 0; i < v; i++) {
            g[i]++;
        }
    }
    
    if (ans.empty()) {
        std::cout << "-1\n";
    } else {
        for (int i = 0; i < int(ans.size()); i++) {
            std::cout << ans[i] << " \n"[i == int(ans.size()) - 1];
        }
    }
    
    return 0;
}