#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int w[MAXN];
vector<int> g[MAXN];
int up[MAXN], ans[MAXN], ansend[MAXN];
int tin[MAXN], t = 0;
int used[MAXN];

void calc_up(int v, int p) {
    used[v] = true;
    tin[v] = ++t;
    up[v] = 1e9;
    for (auto u : g[v]) {
        if (!used[u]) {
            calc_up(u, v);
            ans[v] += ans[u];
            if (up[u] == tin[v]) {
                up[v] = 0;
            }
            if (up[u] < up[v]) {
                up[v] = up[u];
            }
        } else if (u != p){
            up[v] = min(up[v], tin[u]);
        }
    }
    // cout << v << " " << up[v] << " " << tin[v] << endl;
    if (up[v] <= tin[v]) {
        ans[v] += w[v];
    }
}

void calc_ans(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            calc_ans(u);
            ansend[v] = max(ansend[v], ansend[u]);
        }
    }
    ansend[v] += w[v];
}

main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;
    cin >> s;
    s--;
    calc_up(s, -1);
    fill(used, used + n, 0);
    calc_ans(s);
    int res = ans[s];
    int resend = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i] && up[i] > tin[i]) {
            // cout << i << endl;
            resend = max(resend, ansend[i]);
        }
    }
    // cout << res << endl;
    cout << res + resend;
    return 0;
}