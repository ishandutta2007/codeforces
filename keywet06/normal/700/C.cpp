// oct code title CF/CF700C.cpp

#ifndef OCT_CODE_INSERT_PREx2DDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2DDOCUMENT

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#ifndef STL_BITS__2F_STDCx2Bx2Bx2FH
#define STL_BITS__2F_STDCx2Bx2Bx2FH
#include <bits/stdc++.h>
#endif

#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define pup push
#define mkp make_pair
#define fir first
#define sec second
#define ite iterator
#define lob lower_bound
#define upb upper_bound
#define reg register

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;
using pi64 = std::pair<int64, int64>;

namespace oct {

/* Array tn4 is the 4-direction changes in coordinate system.
 * The directions in order is {right, up, left, down}.
 */
const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const double exp = 1e-8;

void sync(int pre = 8);
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);
template <typename _Tp>
_Tp power(_Tp x, int64 m);
template <typename _Tp>
void sort(_Tp &x, _Tp &y);
template <typename _Tp1, typename _Tp2>
std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                std::pair<_Tp1, _Tp2> y);
template <typename _Tp>
_Tp &operator+=(_Tp &x, _Tp y);

inline void sync(int pre) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.flags(std::ios::fixed);
    std::cout.precision(pre);
    std::cout.setf(std::ios::showpoint);
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
template <typename _Tp>
inline _Tp power(_Tp x, int64 m) {
    return m == 1 ? x : (m & 1 ? power(x * x, m / 2) * x : power(x * x, m / 2));
}
template <typename _Tp>
inline void sort(_Tp &x, _Tp &y) {
    if (x > y) std::swap(x, y);
}
template <typename _Tp1, typename _Tp2>
inline std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                       std::pair<_Tp1, _Tp2> y) {
    return x.fir += y.fir, x.sec += y.sec, x;
}
template <typename _Tp>
_Tp &operator+=(_Tp &x, _Tp y) {
    return x = x + y;
}

}  // namespace oct

#endif  // oct code end pre-document

const int N = 100005;
const int V = 1005;
const int E = 60005;

struct line {
    int u, v, w, nt;
};

int n, m, S, T, tmp, ans, sum;
int vis[V], path[V], dfn[V], low[V], road[V], arr[V], lt[V];
int bridge[E];
line ed[E];

void insert(int u, int v, int w) {
    ed[++sum] = (line){u, v, w, lt[u]};
    lt[u] = sum;
}
void addedge(int u, int v, int w) {
    insert(u, v, w);
    insert(v, u, w);
}
bool dfs(int u) {
    vis[u] = 1;
    if (u == T) return true;
    for (int i = lt[u]; i; i = ed[i].nt) {
        int v = ed[i].v;
        if (vis[v]) continue;
        if (dfs(v)) {
            path[++path[0]] = i / 2;
            return true;
        }
    }
    return false;
}
bool dfs_2(int u, int del) {
    vis[u] = 1;
    if (u == T) return true;
    for (int i = lt[u]; i; i = ed[i].nt) {
        int v = ed[i].v;
        if (i / 2 == del) continue;
        if (vis[v]) continue;
        if (dfs_2(v, del)) {
            road[++road[0]] = i / 2;
            return true;
        }
    }
    return false;
}
void tarjan(int u, int fa, int del) {
    dfn[u] = low[u] = ++tmp;
    int flag = 0;
    for (int i = lt[u]; i; i = ed[i].nt) {
        int v = ed[i].v;
        if (i / 2 == del) continue;
        if (v == fa && !flag) {
            flag = 1;
            continue;
        }
        if (!dfn[v]) {
            tarjan(v, u, del);
            oct::mid(low[u], low[v]);
            if (dfn[u] < low[v]) bridge[i / 2] = 1;
        } else
            oct::mid(low[u], dfn[v]);
    }
}

int main() {
    oct::sync();
    std::cin >> n >> m;
    std::cin >> S >> T;
    sum = 1;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        addedge(u, v, w);
    }
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    if (!dfs(S)) {
        std::cout << 0 << std::endl;
        std::cout << 0 << std::endl;
        return 0;
    }
    ans = INT_MAX;
    for (int ii = 1; ii <= path[0]; ii++) {
        memset(bridge, 0, sizeof(bridge));
        memset(vis, 0, sizeof(vis));
        memset(road, 0, sizeof(road));
        memset(dfn, 0, sizeof(dfn));
        tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) tarjan(i, 0, path[ii]);
        }
        if (!dfs_2(S, path[ii])) {
            if (ed[path[ii] * 2].w < ans) {
                ans = ed[path[ii] * 2].w;
                arr[0] = 1;
                arr[1] = path[ii];
            }
        } else {
            for (int i = 1; i <= road[0]; i++) {
                if (bridge[road[i]]) {
                    if (ed[road[i] * 2].w + ed[path[ii] * 2].w < ans) {
                        ans = ed[road[i] * 2].w + ed[path[ii] * 2].w;
                        arr[0] = 2;
                        arr[1] = road[i];
                        arr[2] = path[ii];
                    }
                }
            }
        }
    }
    if (ans == INT_MAX) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ans << std::endl;
    std::cout << arr[0] << std::endl;
    for (int i = 1; i <= arr[0]; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
    return 0;
}