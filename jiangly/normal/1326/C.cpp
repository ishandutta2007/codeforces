#include <iostream>
#include <vector>
#include <algorithm>
constexpr int P = 998244353;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        pos[p[i] - 1] = i;
    }
    long long ans = 0;
    int cnt = 1;
    std::vector<int> v;
    for (int i = n - k; i < n; ++i) {
        ans += i + 1;
        v.push_back(pos[i]);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < k - 1; ++i)
        cnt = 1ll * cnt * (v[i + 1] - v[i]) % P;
    std::cout << ans << " " << cnt << "\n";
    return 0;
}