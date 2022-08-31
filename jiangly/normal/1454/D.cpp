#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t n;
        std::cin >> n;
        std::vector<int64_t> p, c;
        for (int64_t i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    ++cnt;
                }
                p.push_back(i);
                c.push_back(cnt);
            }
        }
        if (n > 1) {
            p.push_back(n);
            c.push_back(1);
        }
        int k = *std::max_element(c.begin(), c.end());
        std::cout << k << "\n";
        for (int i = 1; i <= k; ++i) {
            int64_t x = 1;
            for (int j = 0; j < int(p.size()); ++j)
                if (i >= k - c[j] + 1) x *= p[j];
            std::cout << x << " \n"[i == k];
        }
    }
    
    return 0;
}