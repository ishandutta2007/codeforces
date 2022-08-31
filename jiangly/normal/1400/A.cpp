#include <bits/stdc++.h>
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
        std::string t;
        for (int i = 0; i < n; ++i)
            t += s[2 * i];
        std::cout << t << "\n";
    }
    return 0;
}