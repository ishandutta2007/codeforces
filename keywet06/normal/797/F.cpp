// oct code object CF/CF797F.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF797Fx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF797Fx2eCPP

// oct code object pre-document.cpp
#ifndef OCT_CODE_OBJECT_PREx2dDOCUMENTx2eCPP
#define OCT_CODE_OBJECT_PREx2dDOCUMENTx2eCPP

#if defined(ONLINE_JUDGE) && !defined(LUOGU)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")
#endif

// oct code object stl/bits/stdc++.h
#ifndef OCT_CODE_OBJECT_STL_BITSx2fSTDCx2bx2bx2fH
#define OCT_CODE_OBJECT_STL_BITSx2fSTDCx2bx2bx2fH
#include <bits/stdc++.h>
#endif  // oct code end stl/bits/stdc++.h

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
 * The directions in order is {rght, up, left, down}.
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
_Tp power(_Tp x, int64 tm);
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
inline _Tp power(_Tp x, int64 tm) {
    return tm == 1 ? x
                   : (tm & 1 ? power(x * x, tm / 2) * x : power(x * x, tm / 2));
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

#endif  // oct code end pre-document.cpp

const int B = 2;
const int N = 5005;
const int M = 500004;
const int64 INF = 10000000000000;

struct nh {
    int p, c;
};

int flag;
int vis[N], q[N];
int64 sum[N];
int64 dp[B][N];
nh c[M];

inline int cmp(nh x, nh y) { return x.p < y.p; }
inline int64 get_val(int k) { return dp[flag][k] - sum[k]; }
inline void g(int j, int k) { dp[flag ^ 1][j] = dp[flag][k] + sum[j] - sum[k]; }

int main() {
    int n, m, s = 0;
    std::cin >> n >> m;
    for (int j = 1; j <= n; ++j) std::cin >> vis[j];
    for (int i = 1; i <= m; ++i) std::cin >> c[i].p >> c[i].c, s += c[i].c;
    if (s < n) return std::cout << -1 << std::endl, 0;
    std::sort(vis + 1, vis + n + 1);
    std::sort(c + 1, c + m + 1, cmp);
    for (int j = 1; j <= n; ++j) dp[flag ^ 1][j] = INF;
    for (int i = 1; i <= m; ++i) {
        int head = 1, tail = 0;
        flag ^= 1;
        for (int j = 0; j <= n; ++j) {
            if (j) sum[j] = sum[j - 1] + abs(vis[j] - c[i].p);
            while (head <= tail && j - q[head] > c[i].c) ++head;
            while (head <= tail && get_val(q[tail]) >= get_val(j)) --tail;
            q[++tail] = j, g(j, q[head]);
        }
    }
    std::cout << dp[flag ^ 1][n] << std::endl;
    return 0;
}

#endif  // oct code end CF/CF797F.cpp