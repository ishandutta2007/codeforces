#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int64_t ans = 0;
    std::set<int> f{0}, l, a;
    auto it = a.end();
    while (n--) {
        int tp, d;
        std::cin >> tp >> d;
        if (d > 0) {
            ans += d;
            a.insert(d);
            if (tp == 0) {
                f.insert(d);
                if (it != a.end() && d > *it) {
                    ans += d;
                    ans -= *it;
                    ++it;
                }
            } else {
                l.insert(d);
                if (it != a.end() && d > *it) {
                    ans += d;
                } else {
                    --it;
                    ans += *it;
                }
            }
        } else {
            d = -d;
            ans -= d;
            if (tp == 0) {
                f.erase(d);
                if (it != a.end() && d >= *it) {
                    ans -= d;
                    --it;
                    ans += *it;
                }
            } else {
                l.erase(d);
                if (it != a.end() && d >= *it) {
                    ans -= d;
                    if (*it == d)
                        ++it;
                } else {
                    ans -= *it;
                    ++it;
                }
            }
            a.erase(d);
        }
        std::cout << ans + (!l.empty() && *l.begin() > *f.rbegin() ? *f.rbegin() - *l.begin() : 0) << "\n";
    }
    return 0;
}