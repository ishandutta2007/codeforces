#include <iostream>
#include <vector>
#include <algorithm>
constexpr int N = 200'000;
int n;
std::vector<int> e[N];
std::pair<int, int> dp[N][3];
void dfs1(int u, int p) {
    dp[u][0] = {0, u};
    dp[u][1] = dp[u][2] = {-1, -1};
    for (int v : e[u]) {
        if (v != p) {
            dfs1(v, u);
            auto val = dp[v][0];
            ++val.first;
            for (auto &i : dp[u])
                if (val > i)
                    std::swap(i, val);
        }
    }
}
void dfs2(int u, int p) {
    for (int v : e[u]) {
        if (v != p) {
            auto val = dp[u][0].second == dp[v][0].second ? dp[u][1] : dp[u][0];
            ++val.first;
            for (auto &i : dp[v])
                if (val > i)
                    std::swap(i, val);
            dfs2(v, u);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    int ans = 0, a = -1, b = -1, c = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i][2].second == -1)
            continue;
        if (int val = dp[i][0].first + dp[i][1].first + dp[i][2].first; val > ans) {
            ans = val;
            a = dp[i][0].second;
            b = dp[i][1].second;
            c = dp[i][2].second;
        }
    }
    std::cout << ans << "\n";
    std::cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
    return 0;
}