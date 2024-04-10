#include <iostream>
#include <vector>
int t, n;
std::string s;
auto solve(std::string s) {
    s += '>';
    std::vector<int> a;
    for (int i = 0, last = -1; i < n; ++i) {
        if (s[i] == '>') {
            for (int j = n - i; j <= n - last - 1; ++j)
                a.push_back(j);
            last = i;
        }
    }
    return a;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> s;
        auto ans = solve(s);
        for (int i : ans)
            std::cout << i << " \n"[i == ans.back()];
        for (char &c : s)
            c ^= '<' ^ '>';
        ans = solve(s);
        for (int i : ans)
            std::cout << n - i + 1 << " \n"[i == ans.back()];
    }
    return 0;
}