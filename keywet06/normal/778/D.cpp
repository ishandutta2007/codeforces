// oct code object CF/CF773D.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF773Dx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF773Dx2eCPP

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

const int N = 55;

int n, m;
char s[N][N], t[N][N];
std::vector<pi5> stp;

inline char getc() {
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    return c;
}
inline void rotate(int x, int y) {
    stp.pub(pi5(x, y));
    if (s[x][y] == 'L') {
        s[x][y] = s[x][y + 1] = 'U', s[x + 1][y] = s[x + 1][y + 1] = 'D';
    } else {
        s[x][y] = s[x + 1][y] = 'L', s[x][y + 1] = s[x + 1][y + 1] = 'R';
    }
}
inline void dfs(int x, int y) {
    if (s[x][y] == 'L') return;
    if (s[x][y + 1] == 'L') dfs(x + 1, y + 1), rotate(x, y + 1);
    rotate(x, y);
}
inline std::vector<pi5> change() {
    int tn = n, tm = m;
    std::map<char, char> map;
    map['U'] = 'L', map['D'] = 'R', map['L'] = 'U', map['R'] = 'D';
    if (m & 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) t[j][i] = map[s[i][j]];
        }
        memcpy(s, t, sizeof(t)), std::swap(tn, tm);
    }
    stp.clear();
    for (int i = 1; i <= tn; ++i) {
        for (int j = 1; j <= tm; ++j) {
            if (s[i][j] == 'U') dfs(i, j);
        }
    }
    if (m & 1) {
        for (auto &t : stp) std::swap(t.fir, t.sec);
    }
    return stp;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) s[i][j] = getc();
    }
    std::vector<pi5> pre = change();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) s[i][j] = getc();
    }
    std::vector<pi5> sre = change();
    std::cout << pre.size() + sre.size() << std::endl;
    for (auto t : pre) std::cout << t.fir << ' ' << t.sec << std::endl;
    reverse(sre.begin(), sre.end());
    for (auto t : sre) std::cout << t.fir << ' ' << t.sec << std::endl;
    return 0;
}

#endif  // oct code end CF/CF773D.cpp