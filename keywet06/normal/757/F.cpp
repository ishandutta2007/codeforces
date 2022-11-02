#ifndef OCT_CODE_TITLE_CFx2fCF757Fx2eCPP  // oct code object CF/CF757F.cpp
#define OCT_CODE_TITLE_CFx2fCF757Fx2eCPP

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#if defined(ONLINE_JUDGE) && !defined(LUOGU)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#ifndef STL_BITS__2F_STDCx2Bx2Bx2FH
#define STL_BITS__2F_STDCx2Bx2Bx2FH
#include <bits/stdc++.h>
#endif

#define debug std::cerr << "Debug(" << __LINE__ << "): "
#ifdef ONLINE_JUDGE
#define cerr cout
#endif
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
using ldb = long double;
using pi5 = std::pair<int32, int32>;
using pi6 = std::pair<int64, int64>;
using pi56 = std::pair<int32, int64>;
using pi65 = std::pair<int64, int32>;

namespace oct {

template <typename _Tp>
class priority_queue
    : public std::priority_queue<_Tp, std::vector<_Tp>, std::greater<_Tp> > {};

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
bool in(_Tp x, _Tp y, _Tp l, _Tp r);
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
template <typename _Tp>
_Tp gcd(_Tp &x, _Tp &y);

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
inline bool in(_Tp x, _Tp y, _Tp l, _Tp r) {
    return l <= x && y <= r;
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
inline _Tp &operator+=(_Tp &x, _Tp y) {
    return x = x + y;
}
template <typename _Tp>
inline _Tp gcd(_Tp &x, _Tp &y) {
    return std::__gcd(x, y);
}

}  // namespace oct

#endif  // oct code end pre-document

const int D = 200;
const int N = 300005;
const int M = N << 1;

bool vis[N];
int n, m, s, l, l2, l3, l4, sum, x, y, ans;
int topo[N], in_eage[N], hd[N], hd2[N], hd3[N], hd4[N], fa[N], dep[N], siz[N];
int pre[M], ne[M], pre2[M], ne2[M], pre3[M], ne3[M], pre4[M], ne4[M];
int f[N][D];
int64 z;
int64 dis[N];
int64 len[M];
std::queue<int> q;
std::priority_queue<std::pair<int64, int> > qq;

void add(int x, int y, int64 z) {
    l++, pre[l] = hd[x], hd[x] = l, ne[l] = y, len[l] = z;
}
void add2(int x, int y) { l2++, pre2[l2] = hd2[x], hd2[x] = l2, ne2[l2] = y; }
void add3(int x, int y) { l3++, pre3[l3] = hd3[x], hd3[x] = l3, ne3[l3] = y; }
void add4(int x, int y) { l4++, pre4[l4] = hd4[x], hd4[x] = l4, ne4[l4] = y; }
void dijkstra(int x) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[x] = 0;
    qq.push(std::mkp(0, x));
    while (!qq.empty()) {
        int u = qq.top().second;
        qq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int p = hd[u]; p; p = pre[p]) {
            int v = ne[p];
            if (dis[v] > dis[u] + len[p]) {
                dis[v] = dis[u] + len[p];
                qq.push(std::mkp(-dis[v], v));
            }
        }
    }
}
void toposort() {
    for (int i = 1; i <= n; i++) {
        if (in_eage[i] == 0 && dis[i] != dis[0]) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        topo[++sum] = x;
        for (int p = hd2[x]; p; p = pre2[p]) {
            int v = ne2[p];
            in_eage[v]--;
            if (in_eage[v] == 0) q.push(v);
        }
    }
}
void rmq(int x) {
    f[x][0] = fa[x];
    for (int i = 1; i <= 17; i++) f[x][i] = f[f[x][i - 1]][i - 1];
}
int LCA(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int j = 0; j <= 17; j++) {
        if ((dep[x] - dep[y]) & (1 << j)) x = f[x][j];
    }
    if (x == y) return x;
    for (int j = 17; j >= 0; j--) {
        if (f[x][j] != f[y][j]) x = f[x][j], y = f[y][j];
    }
    return fa[x];
}
void build() {
    fa[n + 1] = n + 1;
    f[n + 1][0] = n + 1;
    dep[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
        if (!topo[i]) break;
        int x = topo[i];
        if (!hd4[x]) {
            dep[x] = 2, fa[x] = f[x][0] = n + 1, add3(n + 1, x);
            continue;
        }
        int lca = ne4[hd4[x]];
        for (int p = hd4[x]; p; p = pre4[p]) {
            int v = ne4[p];
            lca = LCA(lca, v);
        }
        fa[x] = lca;
        dep[x] = dep[lca] + 1;
        add3(lca, x), rmq(x);
    }
}
inline void dfs(int x) {
    siz[x] = 1;
    for (int p = hd3[x]; p; p = pre3[p]) dfs(ne3[p]), siz[x] += siz[ne3[p]];
    if (x != n + 1 && x != s) oct::mad(ans, siz[x]);
}

int main() {
    oct::sync();
    std::cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int x, y;
        int64 z;
        std::cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        for (int p = hd[i]; p; p = pre[p]) {
            int v = ne[p];
            if (dis[v] == dis[i] + len[p]) {
                add2(i, v);
                add4(v, i);
                in_eage[v]++;
            }
        }
    }
    toposort();
    build();
    dfs(n + 1);
    std::cout << ans << std::endl;
    return 0;
}

#endif  // oct code end CF/CF757F.cpp