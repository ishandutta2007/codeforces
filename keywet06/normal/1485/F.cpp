#include <bits/stdc++.h>

using int64 = long long;

const int P = 1000000007;
const int N = 200010;

int64 k, T, n, ans, t;
int64 b[N];

std::map<int64, int64> map;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, map.clear();
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        map[k = 0] = ans = 1;
        for (int i = 1; i <= n; ++i) {
            t = map[k], map[k] = ans, k -= b[i], ans = (2 * ans - t + P) % P;
        }
        std::cout << ans << '\n';
    }
    return 0;
}