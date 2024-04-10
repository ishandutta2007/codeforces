#include <bits/stdc++.h>
using namespace std;
constexpr int N = 200'000;
int n, m, a, b;
int t[N];
vector<int> e[N];
void bfs(int s, int d) {
    queue<int> que;
    que.push(s);
    t[s] |= d;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : e[u]) {
            if (v != a && v != b && !(t[v] & d)) {
                t[v] |= d;
                que.push(v);
            }
        }
    }
}
void solve() {
    cin >> n >> m >> a >> b;
    --a;
    --b;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(a, 1);
    bfs(b, 2);
    int c[2] = {};
    for (int i = 0; i < n; ++i) {
        if (i == a || i == b)
            continue;
        if (t[i] == 1)
            ++c[0];
        if (t[i] == 2)
            ++c[1];
    }
    cout << 1LL * c[0] * c[1] << "\n";
    fill(t, t + n, 0);
    for (int i = 0; i < n; ++i)
        e[i].clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}