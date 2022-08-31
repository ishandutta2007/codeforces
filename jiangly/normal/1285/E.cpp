#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
int t, n;
std::vector<int> l, r, a, p;
void solve() {
    std::cin >> n;
    l.resize(n);
    r.resize(n);
    p.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> l[i] >> r[i];
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return l[i] < l[j];
    });
    int max1 = -1, max2 = -1, cnt = 0;
    for (int i : p) {
        if (max1 == -1 || l[i] > r[max1]) {
            a[i] = -1;
            ++cnt;
        } else {
            a[i] = 0;
        }
        if (max1 != -1 && l[i] <= r[max1] && (max2 == -1 || l[i] > r[max2]))
            ++a[max1];
        int x = i;
        if (max1 == -1 || r[x] > r[max1])
            std::swap(x, max1);
        if (x != -1 && (max2 == -1 || r[x] >= r[max2]))
            max2 = x;
    }
    std::cout << cnt + *std::max_element(a.begin(), a.end()) << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}