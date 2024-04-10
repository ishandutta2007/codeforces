// oct code title CF/CF706E.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
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

#ifndef OCT_CODE_INSERT_CF706Ex5fNODE  // oct code insert CF706E_node
#define OCT_NODE_INSERT_CF706Ex5fNODE

class node {
   public:
    double l, r;
    node();
    node(double x);
    node(double _l, double _r);
};

node operator+(node x, node y);

inline node::node() { l = r = 1; }
inline node::node(double x) { l = x, r = 1 - x; }
inline node::node(double _l, double _r) { l = _l, r = _r; }
inline node operator+(node x, node y) {
    return node(x.l * y.l / (1 - (1 - y.l) * (1 - x.r)),
                x.r * y.r / (1 - (1 - y.l) * (1 - x.r)));
}

#endif  // oct code end CF706E_node

const int N = 100005;
const int M = 262144;

void build(int u, int l, int r);
void update(int u, int l, int r, int x, double a);
node query(int u, int l, int r, int x, int y);

int n, q, x, y, z;
double a[N];
node d[M];

inline void build(int u, int l, int r) {
    if (l == r) return void(d[u] = a[l]);
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    d[u] = d[u << 1] + d[u << 1 | 1];
}
inline void update(int u, int l, int r, int x, double a) {
    if (l == r) return void(d[u] = a);
    int mid = l + r >> 1;
    x <= mid ? update(u << 1, l, mid, x, a)
             : update(u << 1 | 1, mid + 1, r, x, a);
    d[u] = d[u << 1] + d[u << 1 | 1];
}
inline node query(int u, int l, int r, int x, int y) {
    if (oct::in(l, r, x, y)) return d[u];
    int mid = l + r >> 1;
    node ans;
    if (x <= mid) ans = ans + query(u << 1, l, mid, x, y);
    if (y > mid) ans = ans + query(u << 1 | 1, mid + 1, r, x, y);
    return ans;
}

int main() {
    oct::sync();
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> x >> y, a[i] = 1.0 * x / y;
    build(1, 1, n);
    while (q--) {
        std::cin >> x;
        if (x == 1) {
            std::cin >> x >> y >> z;
            update(1, 1, n, x, 1.0 * y / z);
        } else {
            std::cin >> x >> y;
            std::cout << query(1, 1, n, x, y).l << '\n';
        }
    }
    return 0;
}