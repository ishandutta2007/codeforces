#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int N = 100054, M = N * 2;

int n, D, E, root;
int to[M], first[N], next[M];
int p[N], dep[N], deg[N];
int f[N], g[N], fsec[N], count[N];

inline void up(int &x, const int y) { x < y ? x = y : 0; }
inline int max(const int x, const int y) { return x < y ? y : x; }

inline void addedge(int u, int v) {
    to[++E] = v, next[E] = first[u], first[u] = E, ++deg[u];
    to[++E] = u, next[E] = first[v], first[v] = E, ++deg[v];
}

void dfs(int x) {
    int i, y;
    f[x] = fsec[x] = 0;
    for (i = first[x]; i; i = next[i]) {
        if ((y = to[i]) != p[x]) {
            p[y] = x, dep[y] = dep[x] + 1, dfs(y);
            if (f[y] + 1 > f[x]) {
                fsec[x] = f[x], f[x] = f[y] + 1;
            } else {
                up(fsec[x], f[y] + 1);
            }
        }
    }
}

void solve(int x) {
    int i, y, &c = count[x];
    c = 0;
    for (i = first[x]; i; i = next[i]) {
        if (p[y = to[i]] == x) solve(y), c += f[y] + 1 >= D;
    }
}

void solve2(int x) {
    int i, y;
    count[x] += g[x] >= D;
    for (i = first[x]; i; i = next[i]) {
        if (p[y = to[i]] == x) {
            g[y] = max(g[x], f[x] == f[y] + 1 ? fsec[x] : f[x]) + 1, solve2(y);
        }
    }
}

inline int LCA(int x, int y) {
    while (x != y) dep[x] > dep[y] ? x = p[x] : y = p[y];
    return x;
}

namespace node {

int root;
int p[N], dep[N], f[N];
int a[N], b[N];

void dfs(int x) {
    int i, y;
    f[x] = 0;
    for (i = first[x]; i; i = next[i])
        if ((y = to[i]) != p[x])
            p[y] = x, dep[y] = dep[x] + 1, dfs(y), up(f[x], f[y] + 1);
}

inline int LCA(int x, int y) {
    for (; x != y; dep[x] > dep[y] ? x = p[x] : y = p[y])
        ;
    return x;
}

void init(int root_) { root = root_, p[root] = dep[root] = 0, dfs(root); }

inline bool check(int A, int B, int lca) {
    int La = 0, Lb = 0, step, pa, pb, maxa, maxb;
    if (A == lca || B == lca) return true;
    for (; A != lca; A = p[A]) a[La++] = A;
    a[La++] = A, std::reverse(a, a + La);
    for (; B != lca; B = p[B]) b[Lb++] = B;
    b[Lb++] = B, std::reverse(b, b + Lb);
    for (maxa = pa = La - 1, maxb = pb = Lb - 1;;) {
        step = f[a[pa]], pa += step, pb -= step;
        if (pb <= 0) return true;
        if (pa <= maxa) return false;
        maxa = pa;
        step = f[b[pb]], pb += step, pa -= step;
        if (pa <= 0) return true;
        if (pb <= maxb) return false;
        maxb = pb;
    }
}

}  // namespace node

void work() {
    int i, u, v, a, b, c;
    cin >> n >> a >> b, E = 0;
    memset(first, 0, (n + 1) << 2), memset(deg, 0, (n + 1) << 2);
    for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
    dfs(1), c = LCA(a, b), assert(D = dep[a] + dep[b] - dep[c] * 2), solve(1),
            solve2(1);
    for (root = 1; root <= n && count[root] < 3; ++root)
        ;
    if (root > n) {
        cout << "NO\n";
        return;
    }
    node::init(root);
    c = node::LCA(a, b);
    cout << (node::check(a, b, c) || node::check(b, a, c) ? "YES\n" : "NO\n");
}

int main() {
    int T;
    std::ios::sync_with_stdio(false), cin.tie(NULL);
    for (cin >> T; T; --T) work();
    return 0;
}