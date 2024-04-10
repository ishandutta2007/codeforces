#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> p, e;
        
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                p.push_back(i);
                e.push_back(0);
                while (n % i == 0) {
                    n /= i;
                    ++e.back();
                }
            }
        }
        
        if (n > 1) {
            p.push_back(n);
            e.push_back(1);
        }
        
        int k = p.size();
        
        std::vector<std::vector<int>> d(k);
        
        if (k >= 2)
            d.back().push_back(p[0] * p.back());
        
        std::function<void(int, int, int)> dfs = [&](int cur, int x, int mp) {
            if (cur == k) {
                if (mp == -1)
                    return;
                if (k >= 2 && x == p[0] * p.back())
                    return;
                d[mp].push_back(x);
                return;
            }
            
            dfs(cur + 1, x, mp);
            for (int i = 1; i <= e[cur]; ++i) {
                x *= p[cur];
                dfs(cur + 1, x, mp == -1 ? cur : mp);
            }
        };
        
        dfs(0, 1, -1);
        
        int ans = k == 2 && e[0] == 1 && e[1] == 1;
        
        for (int i = 0; i < k; ++i) {
            for (auto &x : d[i])
                if (x % p[(i + 1) % k] == 0)
                    std::swap(x, d[i].back());
            for (auto x : d[i])
                std::cout << x << " ";
        }
        std::cout << "\n";
        
        std::cout << ans << "\n";
    }
    
    return 0;
}