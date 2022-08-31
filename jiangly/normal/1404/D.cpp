#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "First" << std::endl;
        for (int i = 1; i <= 2 * n; ++i)
            std::cout << (i <= n ? i : i - n) << " ";
        std::cout << std::endl;
    } else {
        std::cout << "Second" << std::endl;
        std::vector<int> p(2 * n + 1);
        std::vector<int> a(n + 1), c(n + 1);
        for (int i = 1; i <= 2 * n; ++i) {
            std::cin >> p[i];
            a[p[i]] ^= i;
        }
        int sum = 0;
        std::vector<std::vector<int>> cycles;
        std::vector<int> vis(n + 1);
        for (int i = 1; i <= 2 * n; ++i) {
            if (vis[p[i]])
                continue;
            int j = p[i], x = i;
            std::vector<int> v;
            while (!vis[j]) {
                sum = (sum + x) % (2 * n);
                c[j] = x;
                v.push_back(j);
                vis[j] = 1;
                x = ((a[j] ^ x) - 1 + n) % (2 * n) + 1;
                j = p[x];
            }
            cycles.push_back(v);
        }
        assert(sum % n == 0);
        if (sum == n) {
            for (auto v : cycles) {
                if (v.size() % 2 == 1) {
                    for (auto x : v)
                        c[x] ^= a[x];
                    break;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            std::cout << c[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}