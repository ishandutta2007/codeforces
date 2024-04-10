// luogu remote judge
#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1E5, MAX_V = 2E5 + 4, MAX_E = 5E5 + 3, INF = 1E9;
template<typename T>
void cmin(T &a, const T &b) {
    if (b < a)
        a = b;
}
int n, m, r, b;
bool swapped;
int cntx, cnty;
int x[MAX_N], y[MAX_N], vx[MAX_N], vy[MAX_N], cx[MAX_N], cy[MAX_N], ex[MAX_N], ey[MAX_N];
int out[MAX_V];
int cnte;
struct Edge {
    int v, c, nxt;
    Edge() {}
    Edge(int v, int c, int nxt) : v(v), c(c), nxt(nxt) {}
} e[2 * MAX_E];
int head[MAX_V], cur[MAX_V], h[MAX_V];
void link(int u, int v, int c) {
    e[cnte] = Edge(v, c, head[u]);
    head[u] = cnte++;
    e[cnte] = Edge(u, 0, head[v]);
    head[v] = cnte++;
}
void addEdge(int u, int v, int l, int r) {
    if (l > r) {
        cout << -1 << "\n";
        exit(0);
    }
    out[u] += l;
    out[v] -= l;
    link(u, v, r - l);
}
bool bfs(int n, int s, int t) {
    memset(h, -1, n * sizeof(int));
    h[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
            if (e[i].c > 0 && h[e[i].v] == -1) {
                h[e[i].v] = h[u] + 1;
                if (e[i].v == t)
                    return true;
                que.push(e[i].v);
            }
    }
    return false;
}
int dfs(int u, int t, int f) {
    if (u == t)
        return f;
    int r = f;
    for (int &i = cur[u]; i != -1; i = e[i].nxt)
        if (e[i].c > 0 && h[e[i].v] == h[u] + 1) {
            int x = dfs(e[i].v, t, min(r, e[i].c));
            e[i].c -= x;
            e[i ^ 1].c += x;
            r -= x;
            if (r == 0)
                return f;
        }
    return f - r;
}
int maxFlow(int n, int s, int t) {
    int ans = 0;
    int cnt = 0;
    while (bfs(n, s, t)) {
        memcpy(cur, head, n * sizeof(int));
        ans += dfs(s, t, INF);
    }
    return ans;
}
int LRMaxFlow(int n, int s, int t) {
    int tmp = cnte;
    int _s = n, _t = n + 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (out[i] > 0) {
            link(i, _t, out[i]);
            sum += out[i];
        }
        if (out[i] < 0)
            link(_s, i, -out[i]);
    }
    link(t, s, INF);
    if (maxFlow(n + 2, _s, _t) != sum) {
        cout << -1 << "\n";
        exit(0);
    }
    for (int i = tmp; i < cnte; ++i)
        e[i].c = 0;
    maxFlow(n, s, t);
    int ans = 0;
    for (int i = head[t]; i != -1; i = e[i].nxt)
        ans += e[i].c;
    return ans - out[t];
}
int main() {
    memset(head, -1, sizeof(head));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    cin >> r >> b;
    if (r > b) {
        swap(r, b);
        swapped = true;
    }
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    memcpy(vx, x, n * sizeof(int));
    memcpy(vy, y, n * sizeof(int));
    sort(vx, vx + n);
    sort(vy, vy + n);
    cntx = unique(vx, vx + n) - vx;
    cnty = unique(vy, vy + n) - vy;
    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(vx, vx + cntx, x[i]) - vx;
        y[i] = lower_bound(vy, vy + cnty, y[i]) - vy;
        ++cx[x[i]];
        ++cy[y[i]];
    }
    memcpy(ex, cx, cntx * sizeof(int));
    memcpy(ey, cy, cnty * sizeof(int));
    for (int i = 0; i < m; ++i) {
        int t, l, d;
        cin >> t >> l >> d;
        if (t == 1) {
            int x = lower_bound(vx, vx + cntx, l) - vx;
            if (x != cntx && vx[x] == l)
                cmin(ex[x], d);
        } else {
            int y = lower_bound(vy, vy + cnty, l) - vy;
            if (y != cnty && vy[y] == l)
                cmin(ey[y], d);
        }
    }
    int s = cntx + cnty, t = s + 1;
    for (int i = 0; i < cntx; ++i)
        addEdge(s, i, (cx[i] - ex[i] + 1) / 2, (cx[i] + ex[i]) / 2);
    for (int i = 0; i < cnty; ++i)
        addEdge(cntx + i, t, (cy[i] - ey[i] + 1) / 2, (cy[i] + ey[i]) / 2);
    for (int i = 0; i < n; ++i)
        addEdge(x[i], cntx + y[i], 0, 1);
    int ans = LRMaxFlow(s + 2, s, t);
    cout << 1LL * r * ans + 1LL * b * (n - ans) << "\n";
    for (int i = 0; i < n; ++i)
        cout << "rb"[e[2 * (cntx + cnty + i)].c ^ swapped];
    cout << "\n";
    return 0;
}