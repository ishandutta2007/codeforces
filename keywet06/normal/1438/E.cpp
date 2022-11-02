#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    
    int ans = 0;
    
    auto solve = [&]() {
        std::vector<int64_t> sum(n + 1);
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
        std::vector<int> lst(n), gr(n);
        int b[30] = {};
        std::fill(b, b + 30, -1);
        std::vector<int> s, t;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && a[i] >= a[s.back()]) s.pop_back();
            while (!t.empty() && std::__lg(a[i]) >= std::__lg(a[t.back()])) t.pop_back();
            lst[i] = b[std::__lg(a[i])];
            b[std::__lg(a[i])] = i;
            gr[i] = t.empty() ? -1 : t.back();
            int u = std::max(s.empty() ? -1 : s.back(), gr[i]);
            s.push_back(i);
            t.push_back(i);
            bool eq = false;
            while (u != -1) {
                ans += (a[i] ^ a[u]) == sum[i] - sum[u + 1];
                if (eq || gr[u] > lst[u]) {
                    eq = false;
                    u = gr[u];
                } else {
                    eq = true;
                    u = lst[u];
                }
            }
        }
    };
    
    solve();
    std::reverse(a.begin(), a.end());
    solve();
    
    std::cout << ans << "\n";
    
    return 0;
}