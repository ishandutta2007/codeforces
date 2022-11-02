// oct code title CF/CF750E.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

// #define LUOGU
#if defined(ONLINE_JUDGE) && !defined(LUOGU)
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

const int N = 200100;
const int INF = 1e9;

struct node {
    int a[5][5];
    node() {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j) a[i][j] = INF;
    }
};

char ch[] = {'2', '0', '1', '7', '6'};
char s[N];
int n, m;
node T[N << 2];

inline int find(char x) {
    for (int i = 0; i < 5; ++i) {
        if (x == ch[i]) return i;
    }
    return -1;
}
inline node pushup(node &a, node &b) {
    node res;
    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            for (int k = i; k <= j; ++k) {
                res.a[i][j] = std::min(res.a[i][j], a.a[i][k] + b.a[k][j]);
            }
        }
    }
    return res;
}
inline void build(int p, int l, int r) {
    if (l == r) {
        int f = find(s[l]);
        for (int i = 0; i < 5; ++i) T[p].a[i][i] = 0;
        if (f != -1 && f < 4) {
            T[p].a[f][f + 1] = 0;
            T[p].a[f][f] = 1;
        } else if (f == 4) {
            T[p].a[3][3] = T[p].a[4][4] = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    T[p] = pushup(T[p << 1], T[p << 1 | 1]);
}
inline node query(int p, int l, int r, int ql, int qr) {
    if (ql == l && qr == r) return T[p];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(p << 1, l, mid, ql, qr);
    if (ql > mid) return query(p << 1 | 1, mid + 1, r, ql, qr);
    node tmpl = query(p << 1, l, mid, ql, mid);
    node tmpr = query(p << 1 | 1, mid + 1, r, mid + 1, qr);
    return pushup(tmpl, tmpr);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    std::cin >> s + 1;
    build(1, 1, n);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        int ans = query(1, 1, n, l, r).a[0][4];
        ans = ans == INF ? -1 : ans;
        std::cout << ans << '\n';
    }
    return 0;
}