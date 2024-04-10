#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl
#define pub push_back

const int N = 200005;

int n, k, x, y, u, v;
int dis[N], ans[N], vis[N], tis[N];

std::vector<int> to[N];

std::queue<int> q;

std::stack<int> s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i < n; ++i) std::cin >> x >> y, to[x].pub(y), to[y].pub(x);
    std::cin >> k;
    for (int i = 1; i <= k; ++i) std::cin >> x, q.push(x), vis[x] = 1;
    while (!q.empty()) {
        u = q.front(), q.pop(), s.push(u);
        for (int v : to[u]) {
            if (vis[v]) continue;
            dis[v] = dis[u] + 1, q.push(v), vis[v] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) tis[i] = dis[i];
    memset(vis, 0, sizeof(vis));
    for (int di = n; ~di; --di) {
        while (!s.empty() && tis[u = s.top()] == di) {
            s.pop(), q.push(u), vis[u] = 1;
            dis[u] = tis[u], ans[u] = std::max(ans[u], di);
        }
        while (!q.empty()) {
            u = q.front(), q.pop();
            if (dis[u] <= 1) continue;
            for (int v : to[u]) {
                if (vis[v] && dis[u] - 1 <= dis[v]) continue;
                if (!vis[v]) vis[v] = 1, ans[v] = di;
                dis[v] = dis[u] - 1, q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
    return 0;
}