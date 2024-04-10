#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int steps = 0;
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int l = 0, r = n;
        long long last = 0, x = 0, y = 0;
        while (l < r) {
            ++steps;
            long long res = 0;
            while (l < r && res <= last) {
                if (steps % 2) {
                    res += a[l++];
                } else {
                    res += a[--r];
                }
            }
            last = res;
            (steps % 2 ? x : y) += res;
        }
        std::cout << steps << " " << x << " " << y << "\n";
    }
    return 0;
}