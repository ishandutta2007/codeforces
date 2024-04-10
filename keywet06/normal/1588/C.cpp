#include <bits/stdc++.h>

using int64 = long long;

int64 T, n, x, k, ans, b;

std::map<int64, int> map;

inline void reset(int64 l, int64 r) {
    if (l > r) std::swap(l, r);
    auto it = map.lower_bound(l);
    std::stack<int64> stack;
    while (it != map.begin()) stack.push((--it)->first);
    it = map.upper_bound(r);
    while (it != map.end()) stack.push((it++)->first);
    while (stack.size()) map.erase(stack.top()), stack.pop();
}

inline int64 tr(int64 x) { return k * x + b; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, ans = b = 0, k = 1;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x, ++map[tr(0)], ans += map[tr(x)];
            reset(tr(0), tr(x)), b = x * k + b, k = -k;
        }
        std::cout << ans << '\n';
        map.clear();
    }
    return 0;
}