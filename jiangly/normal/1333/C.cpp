#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::set<long long> s;
    long long ans = 0;
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + a[i];
    for (int i = 0, j = 0; i <= n; ++i) {
        while (s.count(sum[i])) {
            s.erase(sum[j]);
            ++j;
        }
        s.insert(sum[i]);
        ans += i - j;
    }
    std::cout << ans << "\n";
    return 0;
}