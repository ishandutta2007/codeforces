#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
constexpr int N = 200'000, M = 200'000, Q = 200'000;
constexpr long long INF = 1'000'000'000'000'000'000;
int n, m, q;
int a[N], b[N];
std::vector<std::pair<int, int>> e[N];
long long min[4 * N], tag[4 * N];
void add(int p, long long v) {
    min[p] += v;
    tag[p] += v;
}
void push(int p) {
    add(2 * p, tag[p]);
    add(2 * p + 1, tag[p]);
    tag[p] = 0;
}
void pull(int p) {
    min[p] = std::min(min[2 * p], min[2 * p + 1]);
}
void build(int p, int l, int r) {
    if (r - l == 1) {
        min[p] = b[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
    pull(p);
}
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y)
        return add(p,v);
    int m = (l + r) / 2;
    push(p);
    rangeAdd(2 * p, l, m, x, y, v);
    rangeAdd(2 * p + 1, m, r, x, y, v);
    pull(p);
}
void rangeAdd(int l, int r, int v) {
    rangeAdd(1, 0, n, l, r, v);
}
long long f[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i)
        std::cin >> a[i] >> b[i + 1];
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        --u;
        e[u].emplace_back(v, c);
    }
    build(1, 0, n);
    for (int i = 0; i < n; ++i) {
        for (auto [v, c] : e[i])
            rangeAdd(0, v, c);
        f[i] = min[1];
    }
    std::multiset<long long> s;
    for (int i = 0; i < n; ++i)
        s.insert(a[i] + f[i]);
    std::cout << *s.begin() << "\n";
    for (int i = 0; i < q; ++i) {
        int j, x;
        std::cin >> j >> x;
        --j;
        s.erase(s.find(a[j] + f[j]));
        a[j] = x;
        s.insert(x + f[j]);
        std::cout << *s.begin() << "\n";
    }
    return 0;
}