// oct code object CF/CF864F.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF864Fx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF864Fx2eCPP

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

const int L = 3005;
const int N = 400005;
const int INF = 1044266558;

struct pi {
    int s, t, k, id;
};

int val[N], coun, num, n, m, r, k, x, y;
int dnf[L], low[L], vis[L], pos[L];
pi q[N];
std::vector<int> v[L];
std::vector<pi> fq[N];

inline bool cmp(pi a, pi b) { return a.s < b.s; }
inline void tarjan(int u, int fa) {
    dnf[u] = ++coun, low[u] = INF, vis[u] = 1, pos[num++] = u;
    if (fa) {
        for (int i = 0; i < fq[u].size(); ++i) {
            if (fq[u][i].k <= num) val[fq[u][i].id] = pos[fq[u][i].k - 1];
        }
    }
    for (int i = 0; i < v[u].size(); ++i) {
        if (!dnf[v[u][i]]) {
            tarjan(v[u][i], fa && dnf[u] < low[u]);
            low[u] = std::min(low[v[u][i]], low[u]);
        } else if (vis[v[u][i]]) {
            low[u] = oct::mid(low[u], dnf[v[u][i]]);
        }
    }
    vis[u] = 0, --num;
}

int main() {
    oct::sync();
    std::cin >> n >> m >> r;
    memset(val, -1, sizeof(val));
    for (int i = 0; i < m; ++i) std::cin >> x >> y, v[x].pub(y);
    for (int i = 1; i <= n; ++i) std::sort(v[i].begin(), v[i].end());
    for (int i = 0; i < r; ++i) {
        std::cin >> x >> y >> k, q[i] = (pi){x, y, k, i};
    }
    std::sort(q, q + r, cmp);
    for (int i = 0; i < r; ++i) {
        fq[q[i].t].pub(q[i]);
        if (q[i].s != q[i + 1].s) {
            coun = num = 0;
            memset(dnf, 0, sizeof(dnf));
            memset(low, 0, sizeof(low));
            memset(vis, 0, sizeof(vis));
            tarjan(q[i].s, 1);
            for (int j = 1; j <= n; ++j) fq[j].clear();
        }
    }
    for (int i = 0; i < r; ++i) std::cout << val[i] << '\n';
    return 0;
}

#endif  // oct code end CF/CF864F.cpp