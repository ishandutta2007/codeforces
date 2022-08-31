#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> f(n + 1);
    f[0] = n;
    while (f[1] + 1 < n && s[f[1]] == s[f[1] + 1]) {
        f[1]++;
    }
    for (int i = 2, j = 1, mx = 1 + f[1]; i < n; i++) {
        f[i] = std::max(0, std::min(mx - i, f[i - j]));
        while (f[i] + i < n && s[f[i]] == s[f[i] + i]) {
            f[i]++;
        }
    }
    int x = 1;
    // a^inf < b^inf <=> a+b < b+a
    for (int i = 2; i <= n; i++) {
        if (x + f[x] < i) {
            if (s[x + f[x]] < s[f[x]]) {
                x = i;
            }
        } else if (f[i - x] < x) {
            if (s[f[i - x]] < s[i - x + f[i - x]]) {
                x = i;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        std::cout << s[i % x];
    }
    std::cout << "\n";
    return 0;
}