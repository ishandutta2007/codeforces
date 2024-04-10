#include <bits/stdc++.h>

using int64 = long long;
using pi6 = std::pair<int64, int64>;

inline pi6 operator+(pi6 x, pi6 y) { return pi6(x.first + y.first, x.second + y.second); }
inline pi6 operator-(pi6 x, pi6 y) { return pi6(x.first - y.first, x.second - y.second); }
inline pi6 operator*(int64 x, pi6 y) { return pi6(x * y.first, x * y.second); }

const int N = 100005;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int> > To(n + 1);
        for (int i = 1, u, v; i < n; ++i) std::cin >> u >> v, To[u].push_back(v), To[v].push_back(u);
        int r;
        for (int i = 1; i <= n; ++i) {
            if (To[i].size() == 1) {
                r = i;
                break;
            }
        }
        std::vector<pi6> c(n + 1);
        r = To[r].front();
        c[r] = pi6(1, 0);
        for (int v : To[r]) {
            if (To[v].size() == 1) c[v] = pi6(0, 1);
        }
        int Num = To[r].size() - 1;
        std::function<void(int, int, pi6, pi6)> Dfs = [&](int u, int Fa, pi6 s, pi6 a) -> void {
            int t = To[u].size() - 1;
            c[u] = a - t * s;
            for (int v : To[u]) {
                if (v != Fa) Dfs(v, u, a, s);
            }
        };
        for (int v : To[r]) {
            if (To[v].size() > 1) Dfs(v, r, pi6(1, Num), pi6(0, 1));
        }
        for (int i = 1; i <= n; ++i) std::cout << (-Num - 1) * c[i].first + c[i].second << " \n"[i == n];
    }
    return 0;
}