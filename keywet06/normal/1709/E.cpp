#include <bits/stdc++.h>

const int N = 200005;

int n;
int a[N], b[N];

std::set<int> s[N];

std::vector<int> To[N];

inline int Dfs(int u, int Fa) {
    b[u] = b[Fa] ^ a[u];
    bool Canc = false;
    int Ans = 0;
    for (int v : To[u]) {
        if (v == Fa) continue;
        Ans += Dfs(v, u), Canc |= s[v].count(b[u] ^ a[u]);
        if (s[v].size() > s[u].size()) s[u].swap(s[v]);
        for (auto x : s[v]) Canc |= s[u].count(x ^ a[u]);
        for (auto x : s[v]) s[u].insert(x);
        s[v].clear();
    }
    s[u].insert(b[u]);
    if (Canc) s[u].clear();
    return Ans + Canc;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1, x, y; i < n; ++i) {
        std::cin >> x >> y;
        To[x].push_back(y);
        To[y].push_back(x);
    }
    std::cout << Dfs(1, 1) << '\n';
    return 0;
}