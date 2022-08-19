#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        
        std::vector<int> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; ++i) pre[i + 1] = std::max(pre[i], a[i]);
        for (int i = n - 1; i >= 0; --i) suf[i] = std::max(suf[i + 1], a[i]);
        
        int X = -1, Y = -1, Z = -1;
        std::vector<int> stk;
        for (int r = 1; r < n; ++r) {
            while (!stk.empty() && a[r - 1] <= a[stk.back()]) stk.pop_back();
            stk.push_back(r - 1);
            int x = suf[r];
            int L = std::lower_bound(pre.begin(), pre.end(), x) - pre.begin();
            int R = std::min<int>(r, std::upper_bound(pre.begin(), pre.end(), x) - pre.begin());
            auto it = std::lower_bound(stk.begin(), stk.end(), x, [&](int i, int x) { return a[i] < x; });
            if (it == stk.end() || a[*it] != x) continue;
            if (it != stk.begin()) L = std::max(L, *std::prev(it) + 1);
            R = std::min(R, *it + 1);
            if (L >= R) continue;
            X = L;
            Y = r - L;
            Z = n - r;
        }
        
        if (X == -1) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << X << " " << Y << " " << Z << "\n";
        }
    }
    
    return 0;
}