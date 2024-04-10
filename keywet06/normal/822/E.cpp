// oct code object CF/CF822E.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF822Ex2eCPP
#define OCT_CODE_OBJECT_CFx2fCF822Ex2eCPP

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
int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                 {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
double exp = 1e-8;
int64 mods[] = {347480897 /* CCCK */};

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

const int C = 26;
const int K = 35;
const int N = 100005;
const int P = oct::mods[0];
const int P26r = 120281849;

int64 hashs(int l, int r);
int64 hasht(int l, int r);
bool judge(int x, int y, int l);
int solve(int x, int y);
int dfs(int i, int j);

int n, m, k, t;
int f[N][K];
int64 has[N], hat[N], r26[N], p26[N];
std::string S, T;

inline int64 hashs(int l, int r) {
    return (has[r] + P - has[l - 1]) * r26[l - 1] % P;
}
inline int64 hasht(int l, int r) {
    return (hat[r] + P - hat[l - 1]) * r26[l - 1] % P;
}
inline bool judge(int x, int y, int l) {
    return hashs(x, x + l - 1) == hasht(y, y + l - 1);
}
inline int solve(int x, int y) {
    int l = 0, r = std::min(n - x, m - y) + 1, mid;
    while (l < r) judge(x, y, mid = l + r + 1 >> 1) ? l = mid : r = mid - 1;
    return l;
}

int main() {
    oct::sync();
    std::cin >> n >> S >> m >> T >> k, S = ' ' + S, T = ' ' + T, p26[0] = r26[0] = 1;
    for (int i = 1; i <= n; ++i) p26[i] = p26[i - 1] * C % P;
    for (int i = 1; i <= n; ++i) r26[i] = r26[i - 1] * P26r % P;
    for (int i = 1; i <= n; ++i) has[i] = (has[i - 1] + p26[i] * (S[i] - 'a')) % P;
    for (int i = 1; i <= m; ++i) hat[i] = (hat[i - 1] + p26[i] * (T[i] - 'a')) % P;
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (f[i][j] == m) return std::cout << "YES" << std::endl, 0;
            oct::mad(f[i + 1][j], f[i][j]);
            t = solve(i + 1, f[i][j] + 1);
            oct::mad(f[i + t][j + 1], f[i][j] + t);
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}

#endif  // oct code end CF/CF822E.cpp