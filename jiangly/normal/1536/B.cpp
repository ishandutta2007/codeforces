#include <bits/stdc++.h>
constexpr int P[] = {1, 26, 26 * 26, 26 * 26 * 26};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::string> v;
    for (int len = 1; len <= 3; len++) {
        for (int s = 0; s < P[len]; s++) {
            std::string t;
            for (int i = 0; i < len; i++) {
                t += 'a' + s / P[len - i - 1] % 26;
            }
            v.push_back(t);
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::vector<std::pair<int, std::string>> a;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 3 && i + j <= n; j++) {
                a.emplace_back(j, s.substr(i, j));
            }
        }
        std::sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());
        int ans = 0;
        while (ans < int(a.size()) && a[ans].second == v[ans]) {
            ans++;
        }
        std::cout << v[ans] << "\n";
    }
    return 0;
}