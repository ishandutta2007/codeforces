#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int m = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        m = std::max(m, a[i]);
    }
    
    std::vector<int> f(m + 1);
    for (auto x : a) {
        f[x]++;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            f[i] += f[j];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        bool nice = f[i] > 0;
        for (int j = 2 * i; j <= m; j += i) {
            if (f[i] == f[j]) {
                nice = false;
            }
        }
        ans += nice;
    }
    
    std::cout << ans - n << "\n";
    
    return 0;
}