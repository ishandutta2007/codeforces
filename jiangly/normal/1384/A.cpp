#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::string s(51, 'b');
        std::cout << s << "\n";
        for (int i = 0; i < n; ++i) {
            s[a[i]] ^= 1;
            std::cout << s << "\n";
        }
    }
    return 0;
}