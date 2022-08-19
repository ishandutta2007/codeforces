#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2E5;
vector<int> e[N];
bool vis[N];
int ans;
void bfs(int s) {
    queue<int> que;
    int mx = s, i = s;
    --ans;
    while (i <= mx) {
        vis[i] = true;
        que.push(i);
        ++ans;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            mx = max(mx, u);
            for (int v : e[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
        while (i <= mx && vis[i])
            ++i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        if (!vis[i])
            bfs(i);
    cout << ans << endl;
    return 0;
}