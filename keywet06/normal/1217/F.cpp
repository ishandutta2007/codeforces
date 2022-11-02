#include <bits/stdc++.h>

const int N = 5e5;
const int S = 500;

bool able[N], ask[N], vis[N];

int n, m, tote, cnt;
int fa[N];
int op[S], x[S], y[S];
int head[N], to[N], nxt[N], ind[N], que[N];

std::pair<int, int> edge[N];
std::map<std::pair<int, int>, int> id;

int find(int x) {
    while (fa[x] >= 0 && fa[fa[x]] >= 0) {
        x = fa[x] = fa[fa[x]];
    }
    return fa[x] < 0 ? x : fa[x];
}

void insertEdge(int u, int v, int x) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    ind[cnt] = x;
    head[u] = cnt++;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    int last = 0;
    for (int T = 0; T * S < m; ++T) {
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            fa[i] = -1;
            head[i] = -1;
        }
        int tot = std::min(S, m - T * S);
        for (int i = 0; i < tot; ++i) {
            std::cin >> op[i] >> x[i] >> y[i], --x[i], --y[i];
            if (x[i] > y[i]) std::swap(x[i], y[i]);
            if (op[i] == 1) {
                if (!id.count({x[i], y[i]})) {
                    edge[tote] = {x[i], y[i]};
                    id[{x[i], y[i]}] = tote++;
                }
                ask[id[{x[i], y[i]}]] = true;
                int x0 = (x[i] + 1) % n, y0 = (y[i] + 1) % n;
                if (x0 > y0) {
                    std::swap(x0, y0);
                }
                if (!id.count({x0, y0})) {
                    edge[tote] = {x0, y0};
                    id[{x0, y0}] = tote++;
                }
                ask[id[{x0, y0}]] = true;
            }
        }
        for (int i = 0; i < tote; ++i) {
            int u = find(edge[i].first);
            int v = find(edge[i].second);
            if (able[i] && !ask[i] && u != v) {
                if (fa[u] > fa[v]) std::swap(u, v);
                fa[u] += fa[v], fa[v] = u;
            }
        }
        for (int i = 0; i < tote; ++i) {
            int u = find(edge[i].first);
            int v = find(edge[i].second);
            if (ask[i] && u != v) {
                insertEdge(u, v, i);
                insertEdge(v, u, i);
            }
        }
        for (int i = 0; i < tot; ++i) {
            if (op[i] == 1) {
                int x0 = (x[i] + last) % n;
                int y0 = (y[i] + last) % n;
                if (x0 > y0) std::swap(x0, y0);
                able[id[{x0, y0}]] ^= 1;
            } else {
                int l = 0, r = 0;
                int x0 = find((x[i] + last) % n);
                int y0 = find((y[i] + last) % n);
                que[r++] = x0;
                vis[x0] = true;
                while (l < r) {
                    int u = que[l++];
                    for (int j = head[u]; j != -1; j = nxt[j]) {
                        if (able[ind[j]] && !vis[to[j]]) {
                            vis[to[j]] = true;
                            que[r++] = to[j];
                        }
                    }
                }
                if (vis[y0]) {
                    last = 1, std::cout << 1;
                } else {
                    last = 0, std::cout << 0;
                }
                for (int j = 0; j < r; ++j) vis[que[j]] = false;
            }
        }
        memset(ask, 0x00, sizeof(ask));
    }
    std::cout << std::endl;
    return 0;
}