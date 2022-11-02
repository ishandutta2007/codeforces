// oct code title CF/CF717G.cpp

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

const int N = 1005;
const int M = 20005;

void insert(int u, int v, int d, bool i);
void addedge(int u, int v, int d);
int64 Dijkstra();

int64 n, m, s, l, t, cnt = 1, x, y, d;
int64 head[N], dis[N], fe[N];
int64 next[M], to[M], is[M], val[M];

inline void insert(int u, int v, int d, bool i) {
    next[++cnt] = head[u], head[u] = cnt;
    to[cnt] = v, val[cnt] = d, is[cnt] = i;
}
inline void addedge(int u, int v, int d) {
    insert(u, v, std::max(d, 1), d), insert(v, u, std::max(d, 1), d);
}
inline int64 Dijkstra() {
    oct::priority_queue<pi65> queue;
    pi65 p;
    memset(dis, 1, sizeof(dis));
    queue.push(std::mkp(0, s)), dis[s] = 0;
    while (!queue.empty()) {
        p = queue.top(), queue.pop();
        if (dis[p.sec] < p.fir) continue;
        for (int e = head[p.sec]; e; e = next[e]) {
            if (p.fir + val[e] < dis[to[e]]) {
                dis[to[e]] = p.fir + val[e], fe[to[e]] = e;
                queue.push(std::mkp(dis[to[e]], to[e]));
            }
        }
    }
    return dis[t];
}

int main() {
    oct::sync();
    std::cin >> n >> m >> l >> s >> t;
    for (int i = 1; i <= m; ++i) std::cin >> x >> y >> d, addedge(x, y, d);
    while (d = l - Dijkstra()) {
        if (d < 0) return std::cout << "NO" << std::endl, 0;
        int flag = 1;
        for (int u = t; u != s; u = to[fe[u] ^ 1]) {
            if (!is[fe[u]]) {
                val[fe[u]] = val[fe[u] ^ 1] += d, flag = 0;
                break;
            }
        }
        if (flag) return std::cout << "NO" << std::endl, 0;
    }
    std::cout << "YES" << std::endl;
    for (int i = 2; i <= cnt; i += 2) {
        std::cout << to[i ^ 1] << ' ' << to[i] << ' ' << val[i] << '\n';
    }
    return 0;
}