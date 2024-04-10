// oct code title CF/CF715C.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

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

const int N = 200005;
const int M = N << 1;

struct edge {
    int to, next, w;
};

void exgcd(int64 a, int64 b, int64 &x, int64 &y);

int n, m, ecnt;
int cnt[N], son[N], dep[N], head[N], po[N] = {1};
int64 ans;
int64 disup[N], disdown[N];
edge e[M];
std::map<int, int> U, D;

inline void exgcd(int64 a, int64 b, int64 &x, int64 &y) {
    if (!b) {
        x = 1, y = 0;
    } else {
        exgcd(b, a % b, y, x), y -= a / b * x;
    }
}
inline int64 inv(int64 a) {
    int64 x, y;
    exgcd(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}
inline void insert(int u, int v, int w) {
    e[++ecnt].next = head[u];
    e[ecnt].to = v;
    e[ecnt].w = w;
    head[u] = ecnt;
}
inline void pre_dfs(int u, int f) {
    cnt[u] = 1;
    for (int i = head[u]; ~i; i = e[i].next)
        if (e[i].to != f) {
            int v = e[i].to, w = e[i].w;
            disup[v] = (disup[u] + 1ll * po[dep[u]] % m * w) % m;
            disdown[v] = (10ll * disdown[u] % m + w) % m;
            dep[v] = dep[u] + 1;
            pre_dfs(v, u);
            cnt[u] += cnt[v];
            if (cnt[son[u]] < cnt[v]) son[u] = v;
        }
}
inline void calc(int u, int LCA) {
    int64 Ub = disup[u], pl = po[dep[LCA]], pe = po[dep[u]], Dl = disdown[LCA],
          De = disdown[u], Ul = disup[LCA];
    int64 x = ((1ll * Dl * pl % m - 1ll * De * pl % m * pl % m * inv(pe) % m +
                1ll * Ul) %
                   m +
               m) %
              m;
    x = (x + m) % m;
    int64 y =
        (1ll * Dl * inv(pl) % m + 1ll * (Ul - Ub) * inv(pl) % m * inv(pl) % m) %
        m;
    y = (y + m) % m;
    ans += U[x];
    ans += D[y];
}
inline void add(int u) {
    int64 x = disup[u], y = 1ll * disdown[u] * inv(po[dep[u]]) % m;
    U[x]++, D[y]++;
}
inline void update(int u, int f, int LCA, int k) {
    if (k) {
        calc(u, LCA);
    } else {
        add(u);
    }
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (v == f) continue;
        update(v, u, LCA, k);
    }
}
inline void dfs_getans(int u, int f, int h) {
    for (int i = head[u]; ~i; i = e[i].next)
        if (e[i].to != f && e[i].to != son[u]) dfs_getans(e[i].to, u, 0);
    if (son[u]) dfs_getans(son[u], u, 1);
    for (int i = head[u]; ~i; i = e[i].next) {
        if (e[i].to != f && e[i].to != son[u]) {
            update(e[i].to, u, u, 1);
            update(e[i].to, u, u, 0);
        }
    }
    calc(u, u);
    add(u);
    if (!h) U.clear(), D.clear();
}

int main() {
    oct::sync();
    std::cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n + 3; ++i) po[i] = 1LL * po[i - 1] * 10 % m;
    for (int i = 2, u, v, w; i <= n; ++i) {
        std::cin >> u >> v >> w;
        ++u, ++v;
        insert(u, v, w);
        insert(v, u, w);
    }
    pre_dfs(1, 0);
    dfs_getans(1, 0, 1);
    std::cout << ans << std::endl;
    return 0;
}