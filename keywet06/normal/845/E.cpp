// oct code object CF/CF845E.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF845Ex2eCPP
#define OCT_CODE_OBJECT_CFx2fCF845Ex2eCPP

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

const int N = 1005;

struct node {
    int x, y;
};

int n, m, k;
int x[N], y[N], sx, sy;
int mp[N][N];
node pos[N];

int read() {
    static int x;
    std::cin >> x;
    return x;
}
bool check(int mid) {
    memset(mp, 0, sizeof(mp));
    sx = 0, sy = 0, memset(x, 0, sizeof(x)), memset(y, 0, sizeof(y));
    for (int i = 1; i <= k; ++i) {
        x[++sx] = std::max(1, pos[i].x - mid);
        x[++sx] = std::min(n + 1, pos[i].x + mid + 1);
        y[++sy] = std::max(1, pos[i].y - mid);
        y[++sy] = std::min(m + 1, pos[i].y + mid + 1);
    }
    x[++sx] = 1, x[++sx] = n + 1, y[++sy] = 1, y[++sy] = m + 1,
    std::sort(x + 1, x + sx + 1);
    sx = std::unique(x + 1, x + sx + 1) - (x + 1);
    std::sort(y + 1, y + sy + 1);
    sy = std::unique(y + 1, y + sy + 1) - (y + 1);
    for (int i = 1; i <= k; ++i) {
        int x1, x2, y1, y2;
        x1 = lob(x + 1, x + sx + 1, std::max(1, pos[i].x - mid)) - x;
        x2 = lob(x + 1, x + sx + 1, std::min(n + 1, pos[i].x + mid + 1)) - x;
        y1 = lob(y + 1, y + sy + 1, std::max(1, pos[i].y - mid)) - y;
        y2 = lob(y + 1, y + sy + 1, std::min(m + 1, pos[i].y + mid + 1)) - y;
        ++mp[x1][y1], --mp[x1][y2], --mp[x2][y1], ++mp[x2][y2];
    }
    int up = 0, down = sx, l = sy, r = 0;
    for (int i = 1; i < sx; ++i) {
        for (int j = 1; j < sy; ++j) {
            mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
            if (mp[i][j]) continue;
            oct::mad(up, i), oct::mid(down, i), oct::mid(l, j), oct::mad(r, j);
        }
    }
    if (down == sx || l == sy) return 1;
    down = x[down], up = x[up + 1] - 1, l = y[l], r = y[r + 1] - 1;
    if (up - down > mid * 2 || r - l > mid * 2) return 0;
    return 1;
}

int main() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; ++i) pos[i] = (node){read(), read()};
    int l = 0, r = 1e9, mid;
    while (l < r) check(mid = (l + r) >> 1) ? r = mid : l = mid + 1;
    std::cout << l << std::endl;
    return 0;
}

#endif  // oct code end CF/CF845E.cpp