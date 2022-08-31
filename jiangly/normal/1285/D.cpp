#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a;
int solve(int l, int r, int d) {
    if (d == 0)
        return 0;
    if ((a[l] >> (d - 1) & 1) == (a[r - 1] >> (d - 1) & 1))
        return solve(l, r, d - 1);
    int m = std::lower_bound(a.begin() + l, a.begin() + r, a[l] & ~((1 << d) - 1) | 1 << (d - 1)) - a.begin();
    int lx = solve(l, m, d - 1);
    int rx = solve(m, r, d - 1);
    return (1 << (d - 1)) + std::min(lx, rx);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::cout << solve(0, n, 30) << "\n";
    return 0;
}