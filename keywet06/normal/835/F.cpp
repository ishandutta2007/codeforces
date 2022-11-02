// oct code object CF/CF835F.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF835Fx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF835Fx2eCPP

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

const int N = 1000005;

bool vis[N], in[N];
int n, m, tot, top;
int head[N], a[N], sta[N];
int64 fi[N], se[N], mx[N], s0[N], s1[N], t0[N], t1[N], eVal[N];

struct edge {
    int to, nxt;
    int64 val;
} e[N << 1];

inline void add(int from, int to, int64 val) {
    e[++tot].to = to;
    e[tot].val = val;
    e[tot].nxt = head[from];
    head[from] = tot;
}
inline bool getCir(int x, int fat) {
    if (vis[x]) {
        while (1) {
            int now = sta[top];
            in[now] = 1;
            a[++m] = now;
            --top;
            if (now == x) return 1;
        }
    }
    vis[x] = 1, sta[++top] = x;
    int tmp = top;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fat) continue;
        if (getCir(y, x)) return 1;
        top = tmp;
    }
    return 0;
}
inline void getval(int x, int to) {
    if (to == m + 1) return;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y != a[to + 1]) continue;
        eVal[to] = e[i].val;
        getval(y, to + 1);
    }
}
inline int64 getmax(int x, int fat) {
    int64 res = 0LL;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fat || in[y]) continue;
        int64 tmp = getmax(y, x), now = fi[y] + e[i].val;
        oct::mad(res, tmp);
        now > fi[x] ? se[x] = fi[x],
                      fi[x] = now : (now > se[x] ? se[x] = now : 0);
    }
    oct::mad(res, fi[x] + se[x]);
    return res;
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        int64 v;
        std::cin >> x >> y >> v, add(x, y, v), add(y, x, v);
    }
    getCir(1, 0), a[m + 1] = a[1], getval(a[1], 1);
    for (int i = 1; i <= m; i++) mx[i] = getmax(a[i], 0);
    int64 tmp = 0LL;
    for (int i = 1; i < m; i++) {
        s0[i] = std::max(s0[i - 1], tmp + fi[a[i]]);
        tmp += eVal[i];
    }
    tmp = 0LL;
    for (int i = m; i > 1; i--) {
        s1[i] = std::max(s1[i + 1], tmp + fi[a[i]]);
        tmp += eVal[i - 1];
    }
    tmp = 0LL;
    for (int i = 1; i <= m; i++) {
        t0[i] = std::max(t0[i - 1], std::max(mx[i], tmp + fi[a[i]]));
        oct::mad(tmp, fi[a[i]]);
        tmp += eVal[i];
    }
    tmp = 0LL;
    for (int i = m; i > 1; i--) {
        t1[i] = std::max(t1[i + 1], std::max(mx[i], tmp + fi[a[i]]));
        oct::mad(tmp, fi[a[i]]);
        tmp += eVal[i - 1];
    }
    int64 ans = t0[m];
    for (int i = 1; i < m; i++) {
        oct::mid(ans, std::max(std::max(t0[i], t1[i + 1]),
                               s0[i] + s1[i + 1] + eVal[m]));
    }
    std::cout << ans << std::endl;
    return 0;
}

#endif  // oct code end CF/CF833C.cpp