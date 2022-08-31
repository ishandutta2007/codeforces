#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::set<int> s;
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            s.insert((a % n + n + i) % n);
        }
        if (int(s.size()) == n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}