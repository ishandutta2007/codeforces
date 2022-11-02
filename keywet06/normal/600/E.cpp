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

class node;

const int N = 100005;
const int M = 200005;
const int P = 10000005;

class node {
   public:
    int ls, rs, max;
    int64 sum;
};

void insert(int u, int v);
void addedge(int u, int v);
void pushup(node &u);
void update(node &u, int l, int r, int x);
int merge(int u, int v, int l, int r);

int n, cnt, u, v;
int head[N], col[N], size[N], root[N];
int next[M], to[M];
int64 ans[N];
node nd[P];

inline void insert(int u, int v) {
    next[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
inline void addedge(int u, int v) {
    insert(u, v);
    insert(v, u);
}
inline void pushup(node &u) {
    if (nd[u.ls].max > nd[u.rs].max) {
        u.max = nd[u.ls].max, u.sum = nd[u.ls].sum;
    } else if (nd[u.ls].max < nd[u.rs].max) {
        u.max = nd[u.rs].max, u.sum = nd[u.rs].sum;
    } else {
        u.max = nd[u.ls].max, u.sum = nd[u.ls].sum + nd[u.rs].sum;
    }
}
inline void update(node &u, int l, int r, int x) {
    if (l == r) {
        ++u.max, u.sum = l;
        return;
    }
    int mid = l + r >> 1;
    x <= mid ? update(nd[u.ls = &(nd[++cnt] = nd[u.ls]) - nd], l, mid, x)
             : update(nd[u.rs = &(nd[++cnt] = nd[u.rs]) - nd], mid + 1, r, x);
    pushup(u);
}
inline int merge(int u, int v, int l, int r) {
    if (!u || !v) return u + v;
    if (l == r) {
        nd[u].max += nd[v].max;
        return u;
    }
    int mid = l + r >> 1, p = ++cnt;
    nd[p].ls = merge(nd[u].ls, nd[v].ls, l, mid);
    nd[p].rs = merge(nd[u].rs, nd[v].rs, mid + 1, r);
    pushup(nd[p]);
    return p;
}
inline void dfs(int u, int f) {
    size[u] = 1;
    root[u] = ++cnt;
    for (int e = head[u]; e; e = next[e]) {
        if (to[e] == f) continue;
        dfs(to[e], u);
        root[u] = size[to[e]] < size[u] ? merge(root[u], root[to[e]], 1, n)
                                        : merge(root[to[e]], root[u], 1, n);
        size[u] += size[to[e]];
    }
    update(nd[root[u]], 1, n, col[u]);
    ans[u] = nd[root[u]].sum;
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> col[i];
    for (int i = 1; i < n; ++i) std::cin >> u >> v, addedge(u, v);
    cnt = 0;
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
    std::cout << std::endl;
    return 0;
}