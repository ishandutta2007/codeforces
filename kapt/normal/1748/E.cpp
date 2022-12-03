#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e6, MOD = 1e9 + 7;
vector<int> g[MAXN], top;
int used[MAXN];

void build_top(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            build_top(u);
        }
    }
    top.push_back(v);
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        top.clear();
        vector<array<int, 2>> st;
        vector<array<int, 3>> edg;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            int lst = -1;
            while (!st.empty() && a > st.back()[0]) {
                lst = st.back()[1];
                st.pop_back();
            }
            if (lst != -1) {
                g[i].push_back(lst);
                edg.push_back({i, lst, 1});
            }
            if (!st.empty()) {
                g[st.back()[1]].push_back(i);
                edg.push_back({st.back()[1], i, 0});
            }
            st.push_back({a, i});
        }
        fill(used, used + n, 0);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                build_top(i);
            }
        }
        vector<vector<int>> dp(n, vector<int>(m + 1, 0)), p(n, vector<int>(m + 1, 0));
        vector<int> soft(n, -1), hard(n, -1);
        for (auto elem : edg) {
            if (elem[2] == 0) {
                soft[elem[0]] = max(soft[elem[0]], elem[1]);
            } else {
                hard[elem[0]] = elem[1];
            }
        }
        for (int v : top) {
            for (int j = 1; j <= m; ++j) {
                dp[v][j] = 1;
                if (soft[v] != -1) {
                    dp[v][j] *= p[soft[v]][j];
                }
                if (hard[v] != -1) {
                    dp[v][j] *= p[hard[v]][j - 1];
                }
                dp[v][j] %= MOD;
                p[v][j] = (p[v][j - 1] + dp[v][j]) % MOD;
            }
        }
        cout << p[top.back()][m] << endl;
    }
    return 0;
}