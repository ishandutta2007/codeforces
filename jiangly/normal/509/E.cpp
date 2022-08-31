#include <bits/stdc++.h>
using i64 = long long;
const std::string vovels = "IEAOUY";
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<double> h(n + 1);
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] + 1.0 / i;
    }
    double v = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        v += h[n - i] - h[i];
        if (vovels.find(s[i]) != std::string::npos) {
            ans += v;
        }
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
    return 0;
}