#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int n, m;
std::vector<int> p;
std::vector<long long> c;
std::vector<std::vector<int>> e;
void solve() {
    std::cin >> n >> m;
    c.resize(n);
    e.assign(n, {});
    for (int i = 0; i < n; ++i)
        std::cin >> c[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        std::sort(e[i].begin(), e[i].end());
    p.resize(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int u, int v) {
        if (e[u].size() != e[v].size())
            return e[u].size() < e[v].size();
        return e[u] < e[v];
    });
    for (int i = 0; i < n; ) {
        int j = i;
        long long sum = 0;
        while (j < n && e[p[i]] == e[p[j]]) {
            sum += c[p[j]];
            ++j;
        }
        if (!e[p[i]].empty())
            ans = std::gcd(ans, sum);
        i = j;
    }
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}