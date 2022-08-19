#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
int n;
std::vector<int> a, t, p;
std::set<std::pair<int, int>> s;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    t.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cin >> t[i];
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    long long ans = 0;
    for (int i = 0, j = 0, x = 0; i < n; ++x, ++i) {
        if (i == j)
            x = a[p[i]];
        while (j < n && a[p[j]] == x) {
            s.emplace(-t[p[j]], p[j]);
            ++j;
        }
        int k = s.begin() -> second;
        s.erase(s.begin());
        ans += 1ll * (x - a[k]) * t[k];
    }
    std::cout << ans << "\n";
    return 0;
}