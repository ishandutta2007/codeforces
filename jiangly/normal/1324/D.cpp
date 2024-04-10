#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        a[i] -= b;
    }
    std::sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0, j = n; i < n; ++i) {
        while (j > 0 && a[i] + a[j - 1] > 0)
            --j;
        ans += n - std::max(i + 1, j);
    }
    std::cout << ans << "\n";
    return 0;
}