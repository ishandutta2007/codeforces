#include <iostream>
#include <set>
#include <algorithm>
int n, m;
std::string p, ans;
std::set<std::string> s;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::string t;
        std::cin >> t;
        s.insert(t);
        auto r = t;
        std::reverse(r.begin(), r.end());
        if (t == r) {
            p = t;
        } else if (s.count(r)) {
            ans += t;
        }
    }
    auto t = ans;
    std::reverse(t.begin(), t.end());
    ans += p + t;
    std::cout << ans.length() << "\n";
    std::cout<< ans << "\n";
    return 0;
}