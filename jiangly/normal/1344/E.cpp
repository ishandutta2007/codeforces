// luogu
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
std::vector<std::pair<int, int>> ver;
struct Node {
    Node *ch[2], *p;
    int id, tag, tim;
    Node(int id) : ch{nullptr, nullptr}, p(nullptr), id(id), tag(0), tim(0) {}
    void set(int x) {
        tag = std::max(tag, x);
        tim = std::max(tim, x);
    }
    void push() {
        if (ch[0] != nullptr)
            ch[0] -> set(tag);
        if (ch[1] != nullptr)
            ch[1] -> set(tag);
        tag = 0;
    }
    void pull() {
        
    }
    bool isroot() {
        return p == nullptr || (p -> ch[0] != this && p -> ch[1] != this);
    }
    bool pos() {
        return p -> ch[1] == this;
    }
    void rotate() {
        Node *q = p;
        bool x = !pos();
        q -> ch[!x] = ch[x];
        if (ch[x] != nullptr)
            ch[x] -> p = q;
        p = q -> p;
        if (!q -> isroot())
            q -> p -> ch[q -> pos()] = this;
        ch[x] = q;
        q -> p = this;
        q -> pull();
    }
    void splay() {
        std::vector<Node *> s;
        for (Node *i = this; !i -> isroot(); i = i -> p)
            s.push_back(i -> p);
        while (!s.empty()) {
            s.back() -> push();
            s.pop_back();
        }
        push();
        while (!isroot()) {
            if (!p -> isroot()) {
                if (pos() == p -> pos()) {
                    p -> rotate();
                } else {
                    rotate();
                }
            }
            rotate();
        }
        pull();
    }
    void access(int t) {
        ver.clear();
        for (Node *i = this, *q = nullptr; i != nullptr; q = i, i = i -> p) {
            i -> splay();
            if (q != nullptr) {
                ver.emplace_back(i -> id, i -> tim);
                i -> ch[1] = q;
            }
            i -> pull();
        }
        splay();
        if (ch[0] != nullptr)
            ch[0] -> set(t);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    std::vector<int> parent(n, -1), son(n, -1);
    std::vector<long long> dep(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, d;
        std::cin >> u >> v >> d;
        --u;
        --v;
        e[u].emplace_back(v, d);
        parent[v] = u;
        son[u] = v;
    }
    std::function<void(int)> dfs = [&](int u) {
        for (auto [v, d] : e[u]) {
            dep[v] = dep[u] + d;
            dfs(v);
        }
    };
    dfs(0);
    std::vector<Node *> nodes(n);
    for (int i = 0; i < n; ++i)
        nodes[i] = new Node(i);
    std::vector<std::pair<int, int>> trains;
    for (int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;
        --s;
        trains.emplace_back(s, t);
    }
    for (int i = 1; i < n; ++i)
        nodes[i] -> p = nodes[parent[i]];
    for (int i = 0; i < n; ++i) {
        if (son[i] != -1) {
            nodes[i] -> splay();
            nodes[son[i]] -> splay();
            nodes[i] -> ch[1] = nodes[son[i]];
            nodes[son[i]] -> p = nodes[i];
        }
    }
    std::vector<std::pair<long long, long long>> ranges;
    for (auto [s, t] : trains) {
        nodes[s] -> access(t);
        for (auto [u, l] : ver)
            ranges.emplace_back((l == 0 ? 0ll : l + dep[u]) + 1, t + dep[u]);
    }
    std::sort(ranges.begin(), ranges.end());
    int i = 0;
    std::priority_queue<long long, std::vector<long long>, std::greater<>> h;
    for (long long t = 1; i < int(ranges.size()) || !h.empty(); ++t) {
        if (h.empty())
            t = std::max(t, ranges[i].first);
        while (i < int(ranges.size()) && ranges[i].first == t)
            h.push(ranges[i++].second);
        if (h.top() < t) {
            std::cout << t - 1 << " " << std::count_if(ranges.begin(), ranges.end(), [&](auto x) {return x.second < t - 1;}) << "\n";
            return 0;
        }
        h.pop();
    }
    std::cout << -1 << " " << ranges.size() << "\n";
    return 0;
}