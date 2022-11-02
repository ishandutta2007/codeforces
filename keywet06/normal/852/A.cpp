// oct code object CF/CF852A.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF852Ax2eCPP
#define OCT_CODE_OBJECT_CFx2fCF852Ax2eCPP

// oct code object pre-document
#ifndef OCT_CODE_OBJECT_PREx2dDOCUMENT
#define OCT_CODE_OBJECT_PREx2dDOCUMENT

#if defined(ONLINE_JUDGE) && !defined(LUOGU)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")
#endif

// oct code object stl/bits/stdc++.h
#ifndef OCT_CODE_OBJECT_STLx2fBITSx2fSTDCx2bx2bx2fH
#define OCT_CODE_OBJECT_STLx2fBITSx2fSTDCx2bx2bx2fH
#include <bits/stdc++.h>
#endif  // oct code end stl/bits/stdc++.h

#define debug std::cerr << "Debug(" << __LINE__ << "): "
#ifdef ONLINE_JUDGE
#define cerr cout
#endif
#define pub push_back
#define pob pop_back
#define pup push
#define mkp std::make_pair
#define fir first
#define sec second
#define ite iterator
#define lob std::lower_bound
#define upb std::upper_bound
#define reg register

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using dr = double;
using ldr = long double;
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
int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                 {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
dr exp = 1e-8;
int64 cmods[] = {998244353, 1000000007};
int64 fmods[] = {347480897 /* CCCK */};

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
    std::cerr.flags(std::ios::fixed);
    std::cerr.precision(pre);
    std::cerr.setf(std::ios::showpoint);
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

const int N = 200005;
const int X = 50000000;

int calc(int x);
bool solve();

bool f[N];
char s[N];
int n, p, t;
std::string r;
std::mt19937 R(time(0));

inline int calc(int x) {
    int ret = 0;
    while (x) ret += x % 10, x /= 10;
    return ret;
}
inline bool solve() {
    for (int i = 0; i < n - 1; ++i) f[i] = !f[i - 1] || R() > X;
    f[n - 1] = 1;
    for (int i = 0; i < n; ++i) p += f[i] ? s[i] : s[i] * 10;
    return calc(calc(p)) < 10;
}

int main() {
    oct::sync();
    std::cin >> n >> s;
    for (int i = 0; i < n; ++i) s[i] -= '0';
    while (!solve()) p = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << char(s[i] + '0');
        if (f[i] && i + 1 < n) std::cout << '+';
    }
    std::cout << std::endl;
    r = "", t = p;
    while (t) r = char(t % 10 + '0') + ('+' + r), t /= 10;
    std::cout << r.substr(0, r.size() - 1) << std::endl;
    r = "", t = calc(p);
    while (t) r = char(t % 10 + '0') + ('+' + r), t /= 10;
    std::cout << r.substr(0, r.size() - 1) << std::endl;
    return 0;
}

#endif  // oct code end CF/CF852A.cpp