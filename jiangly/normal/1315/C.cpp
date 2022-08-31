#include <iostream>
#include <vector>
int t, n;
std::vector<int> a, b;
std::vector<bool> used;
void solve() {
    std::cin >> n;
    b.resize(n);
    used.assign(2 * n, false);
    a.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        --b[i];
        a[2 * i] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (used[b[i]]) {
            std::cout << -1 << "\n";
            return;
        }
        used[b[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = b[i]; j < 2 * n && used[j]; ++j)
            ;
        if (j == 2 * n) {
            std::cout << -1 << "\n";
            return;
        }
        used[j] = true;
        a[2 * i + 1] = j;
    }
    for (int i = 0; i < 2 * n; ++i)
        std::cout << a[i] + 1 << " \n"[i == 2 * n - 1];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}