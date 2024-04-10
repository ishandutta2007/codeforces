#include <bits/stdc++.h>

template <typename Type>
using PriQueue = std::priority_queue<Type, std::vector<Type>, std::greater<Type> >;

template <typename Type>
auto GetVector(size_t x) {
    return std::vector<Type>(x);
}

template <typename Type, typename... Args>
auto GetVector(size_t x, Args... args) {
    return std::vector<decltype(GetVector<Type>(args...))>(x, GetVector<Type>(args...));
}

int Main() {
    int n, k;
    std::cin >> n >> k;
    auto Hen = GetVector<int>(k - 1, k), Shu = GetVector<int>(k, k - 1);
    int pnum = (k + 1) * (k + 1);
    std::vector<std::vector<std::pair<int, int>> > To(pnum);
    auto Addedge = [&](int u, int v, int w) {
        To[u].emplace_back(v, w);
        To[v].emplace_back(u, w);
    };
    auto P = [&](int x, int y) { return x * (k + 1) + y; };
    for (int i = 1; i <= n; ++i) {
        int ax, ay, bx, by;
        std::cin >> ax >> ay >> bx >> by;
        --ax, --ay, --bx, --by;
        if (ax > bx || ay > by) std::swap(ax, bx), std::swap(ay, by);
        if (ax < bx) {
            ++Hen[ax][ay];
            ++Hen[k - ax - 2][k - ay - 1];
        } else {
            ++Shu[ax][ay];
            ++Shu[k - ax - 1][k - ay - 2];
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        for (int j = 0; j < k; ++j) Addedge(P(i + 1, j), P(i + 1, j + 1), Hen[i][j]);
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k - 1; ++j) Addedge(P(i, j + 1), P(i + 1, j + 1), Shu[i][j]);
    }
    for (int i = 1; i < k; ++i) {
        Addedge(0, P(0, i), 0);
        Addedge(0, P(i, 0), 0);
        Addedge(0, P(k, i), 0);
        Addedge(0, P(i, k), 0);
    }
    int S = S, T = P(k / 2, k / 2);
    std::vector<int> Dis(pnum, INT_MAX >> 1);
    PriQueue<std::pair<int, int> > Que;
    Que.emplace(Dis[0] = 0, 0);
    while (!Que.empty()) {
        auto [d, u] = Que.top();
        if (Que.pop(), d != Dis[u]) continue;
        if (u == T) break;
        for (auto [v, w] : To[u]) {
            if (d + w < Dis[v]) Que.emplace(Dis[v] = d + w, v);
        }
    }
    return n - Dis[T];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) std::cout << Main() << '\n';
    return 0;
}