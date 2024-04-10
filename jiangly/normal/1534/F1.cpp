#include <bits/stdc++.h>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> m >> n;
    std::vector<std::string> s(m);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        while (h[i] < m && s[h[i]][i] == '.') {
            h[i]++;
        }
    }
    if (h == std::vector<int>(n, m)) {
        std::cout << "0\n";
        return 0;
    }
    std::vector<std::vector<int>> e(n * m);
    std::vector<int> dfn(n * m, -1), low(n * m, -1), belong(n * m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0, last = -1; j < m; j++) {
            if (s[j][i] == '#') {
                if (last != -1) {
                    if (last == j - 1) {
                        e[i * m + j].push_back(i * m + last);
                    }
                    e[i * m + last].push_back(i * m + j);
                }
                last = j;
            }
            if (last != -1 && i && s[j][i - 1] == '#') {
                e[i * m + last].push_back((i - 1) * m + j);
            }
            if (last != -1 && i < n - 1 && s[j][i + 1] == '#') {
                e[i * m + last].push_back((i + 1) * m + j);
            }
        }
    }
    std::vector<int> stk;
    int now = 0, cnt = 0;
    std::function<void(int)> tarjan = [&](int u) {
        stk.push_back(u);
        dfn[u] = low[u] = now++;
        for (auto v : e[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (belong[v] == -1) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                stk.pop_back();
                belong[v] = cnt;
            } while (v != u);
            cnt++;
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[j][i] == '#' && dfn[i * m + j] == -1) {
                tarjan(i * m + j);
            }
        }
    }
    std::vector<int> deg(cnt);
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        for (auto v : e[i]) {
            if (belong[i] != belong[v]) {
                deg[belong[v]]++;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        ans += !deg[i];
    }
    std::cout << ans << "\n";
    return 0;
}