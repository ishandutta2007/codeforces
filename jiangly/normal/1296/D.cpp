#include <iostream>
#include <vector>
#include <algorithm>
int n, a, b, k;
std::vector<int> h;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> a >> b >> k;
    h.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];
    for (int i = 0; i < n; ++i) {
        int y = (h[i] - 1) / (a + b);
        h[i] -= y * (a + b);
        h[i] = (h[i] - 1) / a;
    }
    std::sort(h.begin(), h.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (k >= h[i]) {
            k -= h[i];
            ++ans;
        }
    }
    std::cout << ans << "\n";
    return 0;
}