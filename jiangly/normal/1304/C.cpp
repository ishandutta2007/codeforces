#include <iostream>
#include <vector>
int q, n, m;
std::vector<int> t, l, r;
void solve() {
    std::cin >> n >> m;
    t.resize(n);
    l.resize(n);
    r.resize(n);
    int last = 0;
    for (int i = 0; i < n; ++i)
        std::cin >> t[i] >> l[i] >> r[i];
    int x = m, y = m;
    for (int i = 0; i < n; ++i) {
        x -= t[i] - last;
        y += t[i] - last;
        x = std::max(x, l[i]);
        y = std::min(y, r[i]);
        if (x > y) {
            std::cout << "NO\n";
            return;
        }
        last = t[i];
    }
    std::cout << "YES\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> q;
    while (q--)
        solve();
    return 0;
}