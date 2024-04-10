#include <iostream>
#include <map>
int n;
std::map<int, long long> sum;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        sum[i - b] += b;
    }
    long long ans = 0;
    for (auto [x, s] : sum)
        ans = std::max(ans, s);
    std::cout << ans << "\n";
    return 0;
}