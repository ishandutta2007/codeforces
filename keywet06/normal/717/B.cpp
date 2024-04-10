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

const int C = 26;
const int Cs = C << 1;
const int INF = 1061109567;

int64 solve(int64 a, int64 b);
int64 check(int64 x);
void get(int64 x, int64 &tmp, int64 &ans);

int64 c0, c1, n;
int64 at[Cs];

inline int64 solve(int64 a, int64 b) {
    int64 sum = 1, x, t, i;
    for (i = 1; i <= b; ++i) at[i] = i;
    for (i = 0; i < b; ++i) {
        x = a + b - i;
        for (int64 j = 1; j <= b; j++) {
            t = oct::gcd(at[j], x);
            x /= t;
            at[j] /= t;
        }
        if (x > INF / sum) return INF;
        sum *= x;
    }
    return sum;
}
inline int64 check(int64 x) {
    int64 tmp = x / c0 + x / c1 + 1, i, j;
    if (tmp > n) return 1;
    for (i = 1; i <= C; ++i) {
        for (j = i; j * c0 + i * c1 <= x; ++j) {
            if ((tmp += solve(j, i)) > n) return 1;
        }
        for (j = i + 1; j * c1 + i * c0 <= x; ++j) {
            if ((tmp += solve(j, i)) > n) return 1;
        }
    }
    return 0;
}
inline void get(int64 x, int64 &tmp, int64 &ans) {
    int64 c, i, j;
    tmp = x / c0 + x / c1 + 1;
    ans = ((x / c0) * (x / c0 + 1) * c0 + (x / c1) * (x / c1 + 1) * c1) >> 1;
    for (i = 1; i <= C; ++i) {
        for (j = i; j * c0 + i * c1 <= x; ++j) {
            c = solve(j, i), tmp += c, ans += c * (j * c0 + i * c1);
        }
        for (j = i + 1; j * c1 + i * c0 <= x; ++j) {
            c = solve(j, i), tmp += c, ans += c * (j * c1 + i * c0);
        }
    }
}

int main() {
    oct::sync();
    std::cin >> n >> c0 >> c1, --n;
    if (c0 > c1) std::swap(c0, c1);
    if (!c0) return std::cout << n * c1 << std::endl, 0;
    int64 c, sum, l = 0, r = c1 * 26, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        check(mid) ? r = mid - 1 : l = mid + 1;
    }
    get(l - 1, c, sum);
    sum += n * c1 + n * l - c * l + n * c0;
    std::cout << sum << std::endl;
    return 0;
}