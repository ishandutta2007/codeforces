#include <bits/stdc++.h>

int calc(const std::vector<int> &a) {
    if (a.size() == 1) return 1;
    int k = 1 << std::__lg(a.front() ^ a.back());
    auto it = std::partition_point(a.begin(), a.end(), [&](int x) { return (x & k) == 0; });
    return 1 + std::max(calc(std::vector<int>(a.begin(), it)), calc(std::vector<int>(it, a.end())));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::cout << n - calc(a) << "\n";
    
    return 0;
}