#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int64 s[N];

std::vector<int> Son[N];

inline std::pair<int64, int64> Dfs(int u, int k) {
    int n = Son[u].size();
    if (n == 0) return std::make_pair(s[u] * k, s[u] * (k + 1));
    int c = k / n;
    int64 Ans = k * s[u];
    k -= c * n;
    std::priority_queue<int64> Que;
    for (auto v : Son[u]) {
        auto [a1, a2] = Dfs(v, c);
        Ans += a1, Que.push(a2 - a1);
    }
    while (k--) Ans += Que.top(), Que.pop();
    return std::make_pair(Ans, Ans + Que.top() + s[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) Son[i] = std::move(std::vector<int>());
        for (int i = 2, x; i <= n; ++i) std::cin >> x, Son[x].push_back(i);
        for (int i = 1; i <= n; ++i) std::cin >> s[i];
        std::cout << Dfs(1, k).first << '\n';
    }
    return 0;
}