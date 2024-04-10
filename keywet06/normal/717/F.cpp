// oct code title CF/CF717F.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#ifdef ONLINE_JUDGEs
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

const int N = 200010;
const int INF = 1e9;

int n, m;
int a[N], b[N];
int min[N << 2][2], tag[N << 2][2];

inline void pushup(int o) {
    min[o][0] = std::min(min[o * 2][0], min[o * 2 + 1][0]);
    min[o][1] = std::min(min[o * 2][1], min[o * 2 + 1][1]);
}
inline void pushdown(int o) {
    for (int i = 0; i < 2; ++i) {
        if (tag[o][i]) {
            min[o * 2][i] += tag[o][i];
            min[o * 2 + 1][i] += tag[o][i];
            tag[o * 2][i] += tag[o][i];
            tag[o * 2 + 1][i] += tag[o][i];
            tag[o][i] = 0;
        }
    }
}
inline void build(int o, int l, int r) {
    if (l == r) {
        min[o][l & 1] = b[l];
        min[o][l & 1 ^ 1] = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    pushup(o);
}
inline void update(int o, int l, int r, int x, int y, int v, int id) {
    if (x > y) return;
    if (x <= l && r <= y) {
        tag[o][id] += v;
        min[o][id] += v;
        return;
    }
    pushdown(o);
    int mid = (l + r) >> 1;
    if (x <= mid) update(o * 2, l, mid, x, y, v, id);
    if (y > mid) update(o * 2 + 1, mid + 1, r, x, y, v, id);
    pushup(o);
}
inline int query1(int o, int l, int r, int cur, int id) {
    if (cur == 0) return 0;
    if (l == r) return min[o][id];
    pushdown(o);
    int mid = (l + r) >> 1;
    return cur <= mid ? query1(o * 2, l, mid, cur, id)
                      : query1(o * 2 + 1, mid + 1, r, cur, id);
}
inline int query2(int o, int l, int r, int x, int y, int id) {
    if (x <= l && r <= y) return min[o][id];
    pushdown(o);
    int mid = (l + r) >> 1, res = INF;
    if (x <= mid) res = std::min(res, query2(o * 2, l, mid, x, y, id));
    if (y > mid) res = std::min(res, query2(o * 2 + 1, mid + 1, r, x, y, id));
    return res;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = a[i] - b[i - 1];
    build(1, 1, n);
    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
        int id, a, b, k;
        std::cin >> id;
        if (id == 1) {
            std::cin >> a >> b >> k;
            ++a, ++b;
            update(1, 1, n, a, b, k, a & 1);
            if ((b - a + 1) & 1) {
                update(1, 1, n, b + 1, n, k, a & 1);
                update(1, 1, n, b + 1, n, -k, a & 1 ^ 1);
            }
        } else {
            std::cin >> a >> b;
            ++a, ++b;
            if ((b - a + 1) & 1) {
                int temp1 = query1(1, 1, n, a - 1, (a - 1) & 1);
                int temp2 = query2(1, 1, n, a, b, b & 1) + temp1;
                int temp3 = query2(1, 1, n, a, b, b & 1 ^ 1) - temp1;
                int temp4 = query1(1, 1, n, b, b & 1) + temp1;
                std::cout << (temp4 == 1 && temp2 >= 1 && temp3 >= 0) << '\n';
            } else {
                int temp1 = query1(1, 1, n, a - 1, (a - 1) & 1);
                int temp2 = query2(1, 1, n, a, b, b & 1) - temp1;
                int temp3 = query2(1, 1, n, a, b, b & 1 ^ 1) + temp1;
                int temp4 = query1(1, 1, n, b, b & 1) - temp1;
                std::cout << (temp4 == 0 && temp2 >= 0 && temp3 >= 1) << '\n';
            }
        }
    }
    return 0;
}