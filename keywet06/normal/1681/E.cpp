#include <bits/stdc++.h>

using int64 = long long;

const int64 INF = 1000000000000000000;

int n, N;
std::map<std::array<int, 2>, int> Ind;
std::vector<std::array<int, 2>> Fen;
std::vector<int> Lad;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::vector<int> x1(n - 1), y1(n - 1), x2(n - 1), y2(n - 1);
    std::vector<std::vector<int>> Lar(n);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i], --x1[i], --y1[i], --x2[i], --y2[i];
        auto Add = [&](int x, int y) {
            if (!Ind.contains({x, y})) {
                Lad.push_back(std::max(x, y));
                Lar[std::max(x, y)].push_back(N);
                Fen.push_back({x, y});
                Ind[{x, y}] = N++;
            }
        };
        Add(x1[i], y1[i]);
        Add(x1[i] + 1, y1[i]);
        Add(x2[i], y2[i]);
        Add(x2[i], y2[i] + 1);
    }
    std::vector<std::vector<std::array<int, 2>>> adj(N);
    auto addEdge = [&](int u, int v) {
        int d = std::abs(Fen[u][0] - Fen[v][0]) + std::abs(Fen[u][1] - Fen[v][1]);
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    };
    for (int i = 0; i < n - 1; ++i) {
        addEdge(Ind[{x1[i], y1[i]}], Ind[{x1[i] + 1, y1[i]}]);
        addEdge(Ind[{x2[i], y2[i]}], Ind[{x2[i], y2[i] + 1}]);
    }
    for (int i = 0; i < n; ++i) {
        for (auto u : Lar[i]) {
            for (auto v : Lar[i]) {
                if (u == v) {
                    break;
                }
                addEdge(u, v);
            }
        }
    }
    int q;
    std::cin >> q;
    std::vector<int64> Ans(q, INF);
    x1.resize(q);
    y1.resize(q);
    x2.resize(q);
    y2.resize(q);
    std::vector<int> l1(q), l2(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        --x1[i], --y1[i], --x2[i], --y2[i], l1[i] = std::max(x1[i], y1[i]);
        l2[i] = std::max(x2[i], y2[i]);
        if (l1[i] > l2[i]) {
            std::swap(x1[i], x2[i]);
            std::swap(y1[i], y2[i]);
            std::swap(l1[i], l2[i]);
        }
        if (l1[i] == l2[i]) Ans[i] = std::abs(x1[i] - x2[i]) + std::abs(y1[i] - y2[i]);
    }
    std::vector<int64> dis(N, -1);
    std::function<void(int, int, std::vector<int>)> Prob = [&](int l, int r, std::vector<int> qs) {
        if (l > r || qs.empty()) return;
        int m = (l + r) / 2;
        for (auto s : Lar[m]) {
            for (int i = l; i <= r; ++i) {
                for (auto x : Lar[i]) dis[x] = -1;
            }
            std::priority_queue<std::pair<int64, int>, std::vector<std::pair<int64, int>>, std::greater<>> h;
            h.emplace(0, s);
            while (!h.empty()) {
                auto [d, x] = h.top();
                h.pop();
                if (dis[x] != -1) continue;
                dis[x] = d;
                for (auto [v, c] : adj[x]) {
                    if (l <= Lad[v] && Lad[v] <= r) h.emplace(d + c, v);
                }
            }
            for (auto j : qs) {
                int64 d1 = INF, d2 = INF;
                for (auto u : Lar[l1[j]]) {
                    d1 = std::min(d1, dis[u] + std::abs(x1[j] - Fen[u][0]) + std::abs(y1[j] - Fen[u][1]));
                }
                for (auto u : Lar[l2[j]]) {
                    d2 = std::min(d2, dis[u] + std::abs(x2[j] - Fen[u][0]) + std::abs(y2[j] - Fen[u][1]));
                }
                Ans[j] = std::min(Ans[j], d1 + d2);
            }
        }
        std::vector<int> ql, qr;
        for (auto j : qs) {
            if (l2[j] < m) ql.push_back(j);
            if (l1[j] > m) qr.push_back(j);
        }
        Prob(l, m - 1, ql), Prob(m + 1, r, qr);
    };
    std::vector<int> p(q);
    std::iota(p.begin(), p.end(), 0);
    Prob(0, n - 1, p);
    for (auto x : Ans) std::cout << x << "\n";
    return 0;
}