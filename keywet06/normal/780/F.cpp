// oct code object CF/CF780F.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF780Fx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF780Fx2eCPP

// oct code insert pre-document
#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#if defined(ONLINE_JUDGE) && !defined(LUOGU)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")
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

#endif  // oct code end pre-document

const int L = 61;
const int N = 500;
const int INF = 0x3f3f3f3f;

struct mat {
   public:
    int r, c;
    std::bitset<N> a[N + 5];
    std::bitset<N> &operator[](int x);
    void init(int _r, int _c);
};

int read();
mat operator*(mat x, mat y);

int n, m, opt, u, v, p;
int64 ans;
mat f[L + 5][2], a, b;

inline int read() {
    static int x;
    return std::cin >> x, x;
}
inline std::bitset<N> &mat::operator[](int x) { return a[x]; }
inline void mat::init(int _r, int _c) {
    r = _r, c = _c;
    for (int i = 1; i <= r; ++i) a[i].reset();
}
inline mat operator*(mat x, mat y) {
    mat s;
    s.init(x.r, y.c);
    for (int i = 1; i <= x.r; ++i) {
        for (int k = 1; k <= x.c; ++k) {
            if (x[i][k]) s[i] |= y[k];
        }
    }
    return s;
}

int main() {
    oct::sync();
    n = read(), m = read();
    f[0][0].init(n, n), f[0][1].init(n, n);
    for (int i = 1; i <= m; ++i) {
        u = read(), v = read(), p = read(), f[0][p][u][v] = 1;
    }
    for (int k = 1; k <= L; ++k) {
        f[k][0] = f[k - 1][0] * f[k - 1][1];
        f[k][1] = f[k - 1][1] * f[k - 1][0];
    }
    a.init(1, n), a[1][1] = 1;
    for (int k = L; ~k; --k) {
        b = a * f[k][opt];
        if (b[1].count()) a = b, opt ^= 1, ans += (1ll << k);
        if (ans > int64(1e18)) return std::cout << -1 << std::endl, 0;
    }
    std::cout << ans << std::endl;
    return 0;
}

#endif  // oct code end CF/CF780F.cpp