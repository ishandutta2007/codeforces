// oct code title CF/CF706E.cpp

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

const int C = 45;
const int N = 2050;

int g(int x);
int gb(int x);
int ge(int x);
int hb(int x);
int he(int x);
void chk(int i, int j);

char opt[C];
int n, m, k, len, x, y, r, a1, a2, b1, b2, cu, cd, cl, cr;
int l[N];
int a[N][N], id[N][N];
int64 ans;
int64 val[C][C][N];
std::vector<std::pair<int, int64> > f[C][C];

inline int g(int x) { return x / C; }
inline int gb(int x) { return x * C; }
inline int ge(int x) { return x * C + C; }
inline int hb(int x) { return gb(g(x)); }
inline int he(int x) { return ge(g(x)); }
inline void chk(int i, int j) { if (l[id[i][j]]) ans += a[i][j]; }

int main() {
    oct::sync();
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        std::cin >> len;
        while (len--) {
            std::cin >> x >> y >> r, --x, --y;
            a[x][y] = r, id[x][y] = i;
            val[g(x)][g(y)][i] += r;
        }
    }
    do {
        register int i, j, k;
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                for (int k = 1; k < N; ++k) {
                    if (!val[i][j][k]) continue;
                    f[i][j].pub(std::mkp(k, val[i][j][k]));
                }
            }
        }
    } while (0);
    for (int i = 1; i < N; ++i) l[i] = 1;
    register int i, j;
    std::cin >> len;
    while (len--) {
        std::cin >> opt;
        if (opt[0] == 'S') {
            std::cin >> x;
            l[x] ^= 1;
        } else {
            std::cin >> a1 >> b1 >> a2 >> b2;
            --a1, --b1, --a2, --b2, ans = 0;
            if (g(a1) == g(a2) || g(b1) == g(b2)) {
                for (i = a1; i <= a2; ++i) {
                    for (j = b1; j <= b2; ++j) chk(i, j);
                }
                std::cout << ans << std::endl;
                continue;
            }
            cu = g(a1 + C - 1), cd = g(a2 + 1) - 1;
            cl = g(b1 + C - 1), cr = g(b2 + 1) - 1;
            for (i = cu; i <= cd; ++i) {
                for (j = cl; j <= cr; ++j) {
                    for (auto p : f[i][j]) {
                        if (l[p.fir]) ans += p.sec;
                    }
                }
            }
            for (j = b1; j <= b2; ++j) {
                for (i = a1; i < gb(cu); ++i) chk(i, j);
                for (i = ge(cd); i <= a2; ++i) chk(i, j);
            }
            for (i = gb(cu); i < ge(cd); ++i) {
                for (j = b1; j < gb(cl); ++j) chk(i, j);
                for (j = ge(cr); j <= b2; ++j) chk(i, j);
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}