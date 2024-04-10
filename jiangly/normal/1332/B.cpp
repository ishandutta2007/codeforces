#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::set<int> s;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            int x = 2;
            while (a[i] % x != 0)
                ++x;
            a[i] = x;
            s.insert(x);
        }
        std::vector<int> v(s.begin(), s.end());
        std::cout << v.size() << "\n";
        for (int i = 0; i < n; ++i)
            std::cout << std::lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1 << " \n"[i == n - 1];
    }
    return 0;
}