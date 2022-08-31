#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> fib{1, 1};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> c(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    auto check = [&](int v) {
        int cnt = 0;
        std::vector<bool> vis(fib.size());
        int max = 0;
        for (int i = 0; i < n; i++) {
            int x = c[i];
            for (int j = fib.size() - 1; j >= 0; j--) {
                if (x >= fib[j]) {
                    x -= fib[j];
                    if (vis[j]) {
                        return false;
                    }
                    vis[j] = true;
                    cnt++;
                    max = std::max(max, j);
                    if (i == v && j == 1) {
                        return false;
                    }
                }
            }
        }
        return max == cnt;
    };
    
    for (int i = 0; i < n; i++) {
        c[i]--;
        if (check(i)) {
            std::cout << "YES\n";
            return;
        }
        c[i]++;
    }
    std::cout << "NO\n";
}

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while (fib[fib.size() - 2] + fib.back() <= inf) {
        fib.push_back(fib[fib.size() - 2] + fib.back());
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}