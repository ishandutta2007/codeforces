#include <iostream>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int k = std::find(s.begin(), s.end(), '1') - s.begin();
        for (int i = 0; i < k; ++i)
            s[i] -= s[i] == '2';
        if (k == n) {
            std::cout << s << "\n";
            std::cout << s << "\n";
        } else {
            std::cout << s.substr(0, k + 1) + std::string(n - k - 1, '0') << "\n";
            std::cout << s.substr(0, k) + '0' + s.substr(k + 1) << "\n";
        }
    }
    return 0;
}