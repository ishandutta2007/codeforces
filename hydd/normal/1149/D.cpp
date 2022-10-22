//
// Created by hydd on 2022/10/5.
//
#include<bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int main() {
    int n = 0, m = 0, a = 0, b = 0;
    cin >> n >> m >> a >> b;
    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    vector<vector<int>> B(n + 1, vector<int>(n + 1));
    for (int i = 1, u = 0, v = 0, c = 0; i <= m; i++) {
        cin >> u >> v >> c;
        if (c == a) A[u][v] = true, A[v][u] = true;
        else B[u][v] = true, B[v][u] = true;
    }
    vector<int> vis(n + 1), tmp;
    function<void(int)> dfsA = [&dfsA, &n, &A, &vis, &tmp](int u) {
        vis[u] = true;
        tmp.push_back(u);
        for (int v = 1; v <= n; v++)
            if (A[u][v] && !vis[v]) dfsA(v);
    };
    vector<int> bel(n + 1);
    int posl = 0, posr = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        tmp.clear();
        dfsA(i);
        int now = (tmp.size() >= 4 ? ++posr : --posl);
        for (int v: tmp) bel[v] = now;
    }
    queue<pii> quea, queb;
    vector<vector<int>> dp((1 << posr), vector<int>(n + 1, INF));
    dp[0][1] = 0;
    quea.emplace(0, 1);
    while (!quea.empty() || !queb.empty()) {
        int s = 0, u = 0;
        if (queb.empty() ||
            !quea.empty() && dp[quea.front().first][quea.front().second] < dp[queb.front().first][queb.front().second])
            tie(s, u) = quea.front(), quea.pop();
        else
            tie(s, u) = queb.front(), queb.pop();
        for (int v = 1; v <= n; v++) {
            if (!A[u][v]) continue;
            if (bel[v] > 0 && (s >> (bel[v] - 1) & 1)) continue;
            int t = (s | ((bel[u] > 0 && bel[v] != bel[u] ? (1 << (bel[u] - 1)) : 0)));
            if (dp[t][v] > dp[s][u] + a) {
                dp[t][v] = dp[s][u] + a;
                quea.emplace(t, v);
            }
        }
        for (int v = 1; v <= n; v++) {
            if (!B[u][v] || bel[u] == bel[v]) continue;
            if (bel[v] > 0 && (s >> (bel[v] - 1) & 1)) continue;
            int t = (s | ((bel[u] > 0 && bel[v] != bel[u] ? (1 << (bel[u] - 1)) : 0)));
            if (dp[t][v] > dp[s][u] + b) {
                dp[t][v] = dp[s][u] + b;
                queb.emplace(t, v);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        int ans = INF;
        for (auto &f: dp)
            ans = min(ans, f[u]);
        cout << ans << ' ';
    }
    return 0;
}