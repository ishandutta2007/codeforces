#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define fir first
#define sec second

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using int128 = __int128;
using pi32 = std::pair<int32, int32>;

namespace oct {

const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void sync();
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);

inline void sync() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}
template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}
template <typename _Tp>
inline _Tp &mid(_Tp &x, _Tp y) {
    return x = std::min(x, y);
}
template <typename _Tp>
inline bool in(_Tp x, _Tp l, _Tp r) {
    return l <= x && x <= r;
}
template <typename _Tp>
inline _Tp sqr(_Tp x) {
    return x * x;
}

}  // namespace oct

// the pre-document end

const int N = 200005;
const int M = 400005;
const int128 MAX = 1000000000000000001;

void insert(int u, int v, int64 w);
void addedge(int u, int v, int64 w);
void dfs1(int u, int f, int e);
void dfs2(int u, int top);
int128 merge(int128 x, int128 y);
void build(int u, int l, int r);
void update(int u, int l, int r, int x, int64 d);
int128 query(int u, int l, int r, int x, int y);

int n, m, u, v, cnt = 1, o, x;
int head[N], size[N], son[N], fa[N], deep[N], up[N], dfn[N], udfn[N];
int next[M], to[M], id[M];
int64 w;
int64 fv[N];
int64 val[M];
int128 data[M];

inline void insert(int u, int v, int64 w) {
    next[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
inline void addedge(int u, int v, int64 w) {
    insert(u, v, w);
    insert(v, u, w);
}
inline void dfs1(int u, int f, int e) {
    fa[u] = f;
    fv[u] = val[e], id[e] = id[e ^ 1] = u;
    deep[u] = deep[f] + 1, size[u] = 1;
    for (int e = head[u]; e; e = next[e]) {
        if (to[e] == f) continue;
        dfs1(to[e], u, e);
        size[u] += size[to[e]];
        if (size[to[e]] > size[son[u]]) son[u] = to[e];
    }
}
inline void dfs2(int u, int top) {
    dfn[u] = ++cnt, udfn[cnt] = u, up[u] = top;
    if (son[u]) dfs2(son[u], top);
    for (int e = head[u]; e; e = next[e]) {
        if (to[e] == son[u] || to[e] == fa[u]) continue;
        dfs2(to[e], to[e]);
    }
}
inline int128 merge(int128 x, int128 y) { return std::min(MAX, x * y); }
inline void build(int u, int l, int r) {
    if (l == r) {
        data[u] = fv[udfn[l]];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    data[u] = merge(data[u << 1], data[u << 1 | 1]);
}
inline void update(int u, int l, int r, int x, int64 d) {
    if (l == r) {
        data[u] = d;
        return;
    }
    int mid = l + r >> 1;
    x <= mid ? update(u << 1, l, mid, x, d)
             : update(u << 1 | 1, mid + 1, r, x, d);
    data[u] = merge(data[u << 1], data[u << 1 | 1]);
}
inline int128 query(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return data[u];
    int mid = l + r >> 1;
    int128 ans = 1;
    if (x <= mid) ans = merge(ans, query(u << 1, l, mid, x, y));
    if (y > mid) ans = merge(ans, query(u << 1 | 1, mid + 1, r, x, y));
    return ans;
}
inline int128 queryS(int x, int y) {
    int128 ans = 1;
    while (up[x] != up[y]) {
        if (deep[up[x]] < deep[up[y]]) std::swap(x, y);
        ans = merge(ans, query(1, 1, n, dfn[up[x]], dfn[x]));
        if (ans == MAX) return MAX;
        x = fa[up[x]];
    }
    if (x == y) return ans;
    if (deep[x] > deep[y]) std::swap(x, y);
    return merge(ans, query(1, 1, n, dfn[x] + 1, dfn[y]));
}

int main() {
    oct::sync();
    std::cin >> n >> m;
    for (int i = 1; i < n; ++i) std::cin >> u >> v >> w, addedge(u, v, w);
    cnt = 0;
    dfs1(1, 0, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        std::cin >> o;
        if (o == 1) {
            std::cin >> u >> v >> w;
            int64 tmp = queryS(u, v);
            w /= tmp;
            std::cout << w << '\n';
        } else {
            std::cin >> x >> w;
            update(1, 1, n, dfn[id[x * 2]], w);
        }
    }
    return 0;
}