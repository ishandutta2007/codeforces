#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), ai(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        ai[a[i]] = i;
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        --b[i];
        b[i] = ai[b[i]];
        ++c[(b[i] - i + n) % n];
    }
    std::cout << *std::max_element(c.begin(), c.end()) << "\n";
    return 0;
}