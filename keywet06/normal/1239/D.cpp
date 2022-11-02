#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> dfn(n, -1), low(n), be(n, -1);
    stack<int> stk;
    int cnt = 0, tot = 0;
    function<void(int)> tarjan = [&](int u) {
        stk.push(u);
        dfn[u] = low[u] = cnt++;
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
                v = stk.top();
                stk.pop();
                be[v] = tot;
            } while (v != u);
            ++tot;
        }
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
    }
    for (int i = 0; i < n; ++i)
        if (dfn[i] == -1) tarjan(i);
    if (tot == 1) {
        cout << "No"
             << "\n";
        return;
    }
    vector<int> j, p;
    for (int i = 0; i < n; ++i) {
        if (be[i] == 0) {
            j.push_back(i);
        } else {
            p.push_back(i);
        }
    }
    cout << "Yes"
         << "\n";
    cout << j.size() << " " << p.size() << "\n";
    for (int i : j) cout << i + 1 << " \n"[i == j.back()];
    for (int i : p) cout << i + 1 << " \n"[i == p.back()];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}