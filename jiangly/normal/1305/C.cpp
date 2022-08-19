#include <iostream>
#include <vector>
int n, m;
std::vector<int> v;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    v.assign(m + 1, -1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (v[a % m] != -1) {
            std::cout << 0 << "\n";
            return 0;
        }
        v[a % m] = a;
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < i; ++j)
            if (v[i] != -1 && v[j] != -1)
                ans = 1ll * ans * std::abs(v[i] - v[j]) % m;
    std::cout << ans << "\n";
    return 0;
}