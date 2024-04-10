#include <iostream>
#include <vector>
#include <algorithm>
constexpr long long INF = 1'000'000'000'000'000'000;
constexpr int C = 100'000;
struct Line {
    int k;
    long long b;
    Line(int k, long long b) : k(k), b(b) {}
};
long long f(const Line &line, int x) {
    return 1LL * line.k * x + line.b;
}
struct Node {
    Node *lc, *rc;
    Line line;
    Node(const Line &line) : lc(nullptr), rc(nullptr), line(line) {}
};
int n;
std::vector<int> a, b;
std::vector<long long> dp;
std::vector<std::vector<int>> e;
std::vector<Node *> rt;
void modify(Node *&p, int l, int r, Line line) {
    if (p == nullptr) {
        p = new Node(line);
        return;
    }
    int m = (l + r) / 2;
    bool le = f(p -> line, l) < f(line, l);
    bool mi = f(p -> line, m) < f(line, m);
    if (!mi)
        std::swap(p -> line, line);
    if (r - l == 1)
        return;
    if (le != mi) {
        modify(p -> lc, l, m, line);
    } else {
        modify(p -> rc, m, r, line);
    }
}
Node *merge(Node *p, Node *q, int l, int r) {
    if (p == nullptr)
        return q;
    if (q == nullptr)
        return p;
    int m = (l + r) / 2;
    p -> lc = merge(p -> lc, q -> lc, l, m);
    p -> rc = merge(p -> rc, q -> rc, m, r);
    modify(p, l, r, q -> line);
    return p;
}
long long query(Node *p, int l, int r, int x) {
    if (p == nullptr)
        return INF;
    long long ans = f(p -> line, x);
    if (r - l == 1)
        return ans;
    int m = (l + r) / 2;
    if (x < m) {
        return std::min(ans, query(p -> lc, l, m, x));
    } else {
        return std::min(ans, query(p -> rc, m, r, x));
    }
}
void dfs(int u, int p) {
    if (!e[u].empty()) {
        for (int v : e[u]) {
            e[v].erase(std::find(e[v].begin(), e[v].end(), u));
            dfs(v, u);
            rt[u] = merge(rt[u], rt[v], -C, C + 1);
        }
        dp[u] = query(rt[u], -C, C + 1, a[u]);
    }
    modify(rt[u], -C, C + 1, Line(b[u], dp[u]));
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    b.resize(n);
    dp.resize(n);
    e.resize(n);
    rt.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i)
        std::cout << dp[i] << " \n"[i == n - 1];
    return 0;
}