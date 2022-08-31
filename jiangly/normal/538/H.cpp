#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, T, n, m;
    cin >> t >> T >> n >> m;
    vector<int> l(n), r(n);
    vector<pair<int, int>> d(m);
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        d[i] = {--u, --v};
    }
    vector<int> vals {-INF, 0, t, T};
    for (int i = 0; i < n; ++i) {
        if (l[i] <= T)
            vals.push_back(l[i]);
        if (l[i] <= t)
            vals.push_back(t - l[i]);
        if (r[i] <= T)
            vals.push_back(r[i]);
        if (r[i] <= t)
            vals.push_back(t - r[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int cnt = (int)vals.size(), total = 2 * cnt + n;
    vector<vector<int>> e(2 * total);
    for (int i = 1; i < cnt; ++i) {
        e[total + i - 1].push_back(total + i);
        e[total + cnt + i - 1].push_back(total + cnt + i);
        e[i].push_back(i - 1);
        e[cnt + i].push_back(cnt + i - 1);
    }
    for (int i = 0; i < cnt; ++i) {
        int j = vals[i];
        if (j < 0) {
            e[total + i].push_back(i);
            e[total + cnt + i].push_back(cnt + i);
        }
        if (j >= T) {
            e[i].push_back(total + i);
            e[cnt + i].push_back(total + cnt + i);
        }
        int x = lower_bound(vals.begin(), vals.end(), t - j) - vals.begin() - 1;
        e[total + i].push_back(cnt + x);
        e[total + cnt + i].push_back(x);
        if (i != cnt - 1) {
            x = upper_bound(vals.begin(), vals.end(), T - vals[i + 1]) - vals.begin() - 1;
            e[i].push_back(total + cnt + x);
            e[cnt + i].push_back(total + x);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(vals.begin(), vals.end(), l[i]) - vals.begin() - 1;
        e[2 * cnt + i].push_back(x);
        e[total + 2 * cnt + i].push_back(cnt + x);
        e[total + x].push_back(total + 2 * cnt + i);
        e[total + cnt + x].push_back(2 * cnt + i);
        x = upper_bound(vals.begin(), vals.end(), r[i]) - vals.begin() - 1;
        e[2 * cnt + i].push_back(total + x);
        e[total + 2 * cnt + i].push_back(total + cnt + x);
        e[x].push_back(total + 2 * cnt + i);
        e[cnt + x].push_back(2 * cnt + i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        tie(u, v) = d[i];
        e[2 * cnt + u].push_back(total + 2 * cnt + v);
        e[total + 2 * cnt + u].push_back(2 * cnt + v);
        e[2 * cnt + v].push_back(total + 2 * cnt + u);
        e[total + 2 * cnt + v].push_back(2 * cnt + u);
    }
    vector<int> dfn(2 * total, -1), low(2 * total), be(2 * total, -1), stk;
    int dfs_now = 0, cp = 0;
    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = dfs_now++;
        stk.push_back(u);
        for (int v : e[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (be[v] == -1) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                stk.pop_back();
                be[v] = cp;
            } while (v != u);
            ++cp;
        }
    };
    for (int i = 0; i < 2 * total; ++i)
        if (dfn[i] == -1)
            tarjan(i);
    for (int i = 0; i < total; ++i) {
        if (be[i] == be[total + i]) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }
    cout << "POSSIBLE" << "\n";
    int x = 0, y = 0;
    while (be[total + x] > be[x])
        ++x;
    while (be[total + cnt + y] > be[cnt + y])
        ++y;
    cout << vals[x] << " " << vals[y] << "\n";
    for (int i = 0; i < n; ++i)
        cout << (be[total + 2 * cnt + i] < be[2 * cnt + i]) + 1;
    cout << "\n";
    return 0;
}