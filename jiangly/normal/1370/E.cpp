#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    if (std::count(s.begin(), s.end(), '0') != std::count(t.begin(), t.end(), '0')) {
        std::cout << -1 << "\n";
        return 0;
    }
    int mn = 0, mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - t[i];
        mn = std::min(mn, sum);
        mx = std::max(mx, sum);
    }
    std::cout << mx - mn << "\n";
    return 0;
}