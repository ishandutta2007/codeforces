#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) cnt += a[i] < a[j];
    }
    std::vector<int> pos(n);
    std::iota(pos.begin(), pos.end(), 0);
    std::stable_sort(pos.begin(), pos.end(),
                     [&](int i, int j) { return a[i] < a[j]; });
    std::cout << cnt << "\n";
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < n - 1; ++i) {
            if (pos[i] > pos[i + 1]) {
                std::swap(pos[i], pos[i + 1]);
                std::cout << pos[i] + 1 << " " << pos[i + 1] + 1 << "\n";
            }
        }
    }
    return 0;
}