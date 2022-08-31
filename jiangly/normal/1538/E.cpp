#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = std::sqrt(1e9);
int count(std::string s) {
    int ans = 0;
    for (int i = 0; i + 4 <= int(s.size()); i++) {
        ans += "haha" == s.substr(i, 4);
    }
    return ans;
}
auto merge(std::pair<i64, std::string> a, std::pair<i64, std::string> b) {
    i64 cnt = a.first + b.first;
    std::string s = a.second + b.second;
    for (int i = std::max(0, int(a.second.size()) - 3); i + 4 <= int(s.size()) && i < int(a.second.size()); i++) {
        cnt += "haha" == s.substr(i, 4);
    }
    if (s.size() >= 6) {
        s.erase(s.begin() + 3, s.end() - 3);
    }
    return std::make_pair(cnt, s);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::map<std::string, std::pair<i64, std::string>> f;
        std::string last;
        int n;
        std::cin >> n;
        while (n--) {
            std::string a, op, b, c;
            std::cin >> a >> op;
            if (op == ":=") {
                std::cin >> b;
                f[a] = {count(b), b};
            } else {
                std::cin >> b >> op >> c;
                f[a] = merge(f[b], f[c]);
            }
            last = a;
        }
        std::cout << f[last].first << "\n";
    }
    return 0;
}