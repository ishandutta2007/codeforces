#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2), b(n + 1, -1), c{-1};
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    a[n + 1] = n + 1;
    for (int i = 0; i <= n; ++i) {
        if (a[i] < a[i + 1]) {
            b[i] = a[i];
            c.push_back(a[i]);
        }
    }
    c.push_back(n + 1);
    for (int i = 0, j = 0; i < int(c.size()) - 1; ++i) {
        for (int v = c[i + 1] - 1; v > c[i]; --v) {
            while (b[j] != -1)
                ++j;
            b[j++] = v;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << b[i] << " \n"[i == n - 1];
    return 0;
}