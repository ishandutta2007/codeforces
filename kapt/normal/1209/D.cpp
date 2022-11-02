#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int used[MAXN];
int use[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        use[u] = true;
        use[v] = true;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int n1 = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            n1++;
            if (!used[i]) {
                dfs(i);
                cnt++;
            }
        }
    }
    cout << max(cnt - n1 + k, 0);
    return 0;
}