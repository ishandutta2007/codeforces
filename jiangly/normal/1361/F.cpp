#include <bits/stdc++.h>
#include <bits/extc++.h>
constexpr int N = 2e5;
int n;
int p[N], w[N], ch[N][2], parent[2 * N], dep[2 * N];
long long ans, res[N], all[N];
__gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> t[2 * N];
void dfs(int u, int l, int r) {
    for (int i = l; i < r; ++i)
        t[u].insert(p[i]);
    if (r - l == 1)
        return;
    if (u - l == 1)
        ch[u][0] = l + n;
    if (r - u == 1)
        ch[u][1] = u + n;
    dep[ch[u][0]] = dep[ch[u][1]] = dep[u] + 1;
    parent[ch[u][0]] = parent[ch[u][1]] = u;
    dfs(ch[u][0], l, u);
    dfs(ch[u][1], u, r);
    for (int i = l; i < u; ++i)
        res[u] += t[ch[u][1]].order_of_key(p[i]);
    all[u] = 1ll * (u - l) * (r - u);
    ans += std::min(res[u], all[u] - res[u]);
}
void modify(int u, int x, int y) {
    int p = parent[u];
    ans -= std::min(res[p], all[p] - res[p]);
    if (ch[p][0] == u) {
        res[p] += t[ch[p][1]].order_of_key(y);
        res[p] -= t[ch[p][1]].order_of_key(x);
    } else {
        res[p] += t[ch[p][0]].order_of_key(x + 1);
        res[p] -= t[ch[p][0]].order_of_key(y + 1);
    }
    t[u].erase(x);
    t[u].insert(y);
    ans += std::min(res[p], all[p] - res[p]);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    for (int i = 1; i < n; ++i)
        std::cin >> w[i];
    std::vector<int> stk;
    for (int i = 1; i < n; ++i) {
        while (!stk.empty() && w[i] < w[stk.back()]) {
            ch[stk.back()][1] = ch[i][0];
            ch[i][0] = stk.back();
            stk.pop_back();
        }
        stk.push_back(i);
    }
    while (stk.size() > 1) {
        int u = stk.back();
        stk.pop_back();
        ch[stk.back()][1] = u;
    }
    dfs(stk[0], 0, n);
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        int x = p[u];
        int y = p[v];
        std::swap(p[u], p[v]);
        u += n;
        v += n;
        while (u != v) {
            if (dep[u] > dep[v]) {
                modify(u, x, y);
                u = parent[u];
            } else {
                modify(v, y, x);
                v = parent[v];
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}