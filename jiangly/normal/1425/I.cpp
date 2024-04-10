#include <bits/stdc++.h>

constexpr int N = 5e4;

int t[N], p[N], a[N], in[N], out[N], dep[N], d[N];
std::vector<int> e[N];
int now;
void dfs(int u) {
    in[u] = now++;
    d[in[u]] = a[u];
    for (auto v : e[u]) {
        dep[now] = dep[in[u]] + 1;
        dfs(v);
    }
    out[u] = now;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
        e[p[i]].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int cnt = 0, sum = 0;
        int x;
        std::cin >> x;
        --x;
        for (int j = in[x]; j < out[x]; ++j) {
            if (t[j] <= i) {
                ++cnt;
                sum += dep[j];
                t[j] = i + d[j];
            }
        }
        std::cout << sum - cnt * dep[in[x]] << " " << cnt << "\n";
    }
    
    return 0;
}