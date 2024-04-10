#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        std::string t = "$#";
        for (int i = 0; i < n; ++i) {
            t += s[i];
            t += '#';
        }
        int m = t.length();
        t += '&';
        int maxRight = 0, mid = 0;
        std::vector<int> p(m);
        for (int i = 1; i < m; ++i) {
            p[i] = i < maxRight ? std::min(p[2 * mid - i], maxRight - i) : 1;
            while (t[i - p[i]] == t[i + p[i]])
                ++p[i];
            if (maxRight < i + p[i]) {
                mid = i;
                maxRight = i + p[i];
            }
        }
        int d = 0;
        while (d < n && s[d] == s[n - d - 1])
            ++d;
        int ans = 0, l0 = 0, r0 = 0, k0 = 0;
        for (int i = 1; i < m; ++i) {
            int l = (i - p[i]) / 2, r = (i + p[i]) / 2 - 1;
            int k = std::min(l, n - r);
            if (d >= k && r - l + 2 * k > ans) {
                ans = r - l + 2 * k;
                l0 = l;
                r0 = r;
                k0 = k;
            }
        }
        std::cout << s.substr(0, k0) + s.substr(l0, r0 - l0) + s.substr(n - k0) << "\n";
    }
    return 0;
}