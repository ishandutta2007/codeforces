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
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        std::sort(s.begin(), s.end());
        std::string t;
        int i = 0;
        while (i < n && s[0] == s[i])
            ++i;
        if (i < k) {
            t = s[k - 1];
        } else if (i == n) {
            t = std::string((n + k - 1) / k, s[0]);
        } else if (i > k) {
            t = s[0] + s.substr(k, n);
        } else if (s[i] == s.back()) {
            t = s[0] + std::string((n - 1) / k, s[i]);
        } else {
            t = s[0] + s.substr(k, n);
        }
        std::cout << t << "\n";
    }
    return 0;
}