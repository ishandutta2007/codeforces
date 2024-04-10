// oct code title CF/CF717G.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#ifdef ONLINE_JUDGEs
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

const int C = 600;
const int N = 100005;

void insert(int u, int v, int c, int f);
void addedge(int u, int v, int c, int f);
int bfs();

char s1[C], s2[C];
int n, m, cnt = 1, S, T, ans;
int to[N], next[N], head[C], cost[N], flow[N], pe[C], pv[C], dis[C], inq[C];
std::queue<int> q;

inline void insert(int u, int v, int c, int f) {
    next[++cnt] = head[u], head[u] = cnt;
    to[cnt] = v, cost[cnt] = c, flow[cnt] = f;
}
inline void addedge(int u, int v, int c, int f) {
    insert(u, v, c, f);
    insert(v, u, -c, 0);
}
inline int bfs() {
    memset(dis, 0xc0, sizeof(dis));
    dis[S] = 0, q.push(S);
    int i, u;
    while (!q.empty()) {
        u = q.front(), inq[u] = 0, q.pop();
        for (i = head[u]; i; i = next[i]) {
            if (dis[to[i]] < dis[u] + cost[i] && flow[i]) {
                dis[to[i]] = dis[u] + cost[i], pe[to[i]] = i, pv[to[i]] = u;
                if (!inq[to[i]]) q.push(to[i]), inq[to[i]] = 1;
            }
        }
    }
    return dis[T] > 0;
}

int main() {
    oct::sync();
    std::cin >> n;
    std::cin >> s1 + 1;
    std::cin >> m;
    int i, j, k, a, b;
    for (i = 1; i <= m; i++) {
        std::cin >> s2 >> b, a = strlen(s2);
        for (j = 1; j + a - 1 <= n; j++) {
            for (k = 0; k < a; k++) {
                if (s1[j + k] != s2[k]) break;
            }
            if (k == a) addedge(j, j + a, b, 1);
        }
    }
    std::cin >> a;
    for (i = 0; i <= n; i++) addedge(i, i + 1, 0, a);
    S = 0, T = n + 1;
    while (bfs()) {
        ans += dis[T];
        for (i = T; i != S; i = pv[i]) flow[pe[i]]--, flow[pe[i] ^ 1]++;
    }
    std::cout << ans << std::endl;
    return 0;
}