#include <bits/stdc++.h>

bool Main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), Num(n + 1);
    std::vector<std::vector<int> > To(n + 1);
    for (int i = 0; i < n; ++i) std::cin >> a[i], ++Num[a[i]];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    int p = 0;
    for (int i = 1; i <= n; ++i) p = Num[i] > Num[p] ? i : p;
    Num = std::move(std::vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        if (a[i] != p && b[i] != p) ++Num[b[i]], To[a[i]].push_back(b[i]);
    }
    std::queue<int> Que;
    for (int i = 1; i <= n; ++i) {
        if (!Num[i]) Que.push(i);
    }
    while (!Que.empty()) {
        int u = Que.front();
        Que.pop();
        for (auto v : To[u]) {
            if (!--Num[v]) Que.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (Num[i]) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) std::cout << (Main() ? "AC" : "WA") << '\n';
    return 0;
}