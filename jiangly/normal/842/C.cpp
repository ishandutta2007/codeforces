#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int n;
std::vector<int> a, divisors, ans, cnt;
std::vector<std::vector<int>> e;
void dfs(int u, int p, int g) {
    ans[u] = g;
    for (int i = 0; i < int(divisors.size()); ++i) {
        if (a[u] % divisors[i] != 0)
            --cnt[i];
        if (cnt[i] >= -1)
            ans[u] = std::max(ans[u], divisors[i]);
    }
    for (int v : e[u])
        if (v != p)
            dfs(v, u, std::gcd(g, a[v]));
    for (int i = 0; i < int(divisors.size()); ++i)
        if (a[u] % divisors[i] != 0)
            ++cnt[i];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    ans.resize(n);
    e.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= a[0]; ++i)
        if (a[0] % i == 0)
            divisors.push_back(i);
    cnt.resize(divisors.size());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}