#include <bits/stdc++.h>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), pos(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
            pos[a[i]] = i;
        }
        std::set<int> s{-1, n};
        for (int i = 0; i < n; ++i) s.insert(i);
        std::vector<bool> vis(n);
        int ans = 1;
        std::vector<int> b(k);
        for (int i = 0; i < k; ++i) {
            std::cin >> b[i];
            --b[i];
            b[i] = pos[b[i]];
            vis[b[i]] = true;
        }
        for (int i = 0; i < k; ++i) {
            auto it = s.find(b[i]);
            int l = *std::prev(it), r = *std::next(it);
            bool gl = l >= 0 && !vis[l];
            bool gr = r < n && !vis[r];
            if (!gl && !gr) {
                ans = 0;
                break;
            } else if (gl && gr) {
                ans = 2 * ans % P;
                s.erase(l);
            } else if (gl) s.erase(l);
            else s.erase(r);
            
            vis[b[i]] = false;
        }
        std::cout << ans << "\n";
    }
    
    return 0;
}