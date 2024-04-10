#include <bits/stdc++.h>

inline int Query(int u) {
    std::cout << "? " << u << std::endl;
    int x;
    std::cin >> x;
    return x;
}

int Main() {
    int n;
    std::cin >> n;
    std::vector<int> d(n + 1), p(n + 1), used(n + 1), Ans(n + 1);
    std::vector<std::vector<int> > To(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> d[p[i] = i];
    std::sort(&p[1], &p[n] + 1, [&](int x, int y) { return d[x] > d[y]; });
	for (int i = 1; i < n; ++i) assert(d[p[i]] >= d[p[i + 1]]);
    auto Add = [&](int u, int v) { To[u].push_back(v), To[v].push_back(u); };
    for (int q = 1; q <= n; ++q) {
        int i = p[q];
        if (used[i]) continue;
        used[i] = 1;
        for (int j = 1; j <= d[i]; ++j) {
            int x = Query(i);
            Add(i, x);
            if (used[x]) break;
            used[x] = 1;
        }
    }
    std::function<void(int, int)> Dfs = [&](int u, int c) {
        Ans[u] = c;
        for (auto v : To[u]) {
            if (!Ans[v]) Dfs(v, c);
        }
    };
    int Cnt = 0;
    std::cout << '!';
    for (int i = 1; i <= n; ++i) {
        if (!Ans[i]) Dfs(i, ++Cnt);
        std::cout << ' ' << Ans[i];
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Main();
    return 0;
}