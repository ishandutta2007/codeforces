#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(m);
    std::vector<long long> suf(m + 1);
    for (int i = 0; i < m; ++i) {
        std::cin >> l[i];
        if (i + l[i] > n) {
            std::cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = m; i--; )
        suf[i] = suf[i + 1] + l[i];
    if (suf[0] < n) {
        std::cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int r = i + suf[i] >= n ? i : n - suf[i];
        std::cout << r + 1 << " \n"[i == m - 1];
    }
    return 0;
}