#ifndef OCT_INSERT_PRE_DOCUMENT  // oct insert "pre-document"
#define OCT_INSERT_PRE_DOCUMENT

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#include <bits/stdc++.h>
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
_Tp &operator+=(_Tp &x, _Tp y) {
    return x = x + y;
}

}  // namespace oct

#endif  // oct end "pre-document"

const int N = 1000005;
const int M = N * 2;

void pushup(int u);
void get(int u, int l, int r, int x);
void pushdown(int u, int l, int r);
void update(int u, int l, int r, int ll, int rr, int x);
void build(int u, int l, int r);

int n, m;
int ma[M], mi[M], tg[M];
int64 ans, c1, c2;
int64 s[N], nm[N];
std::vector<int> a[N], ps[N];

inline void pushup(int u) {
    s[u] = s[u << 1] + s[u << 1 | 1];
    ma[u] = std::max(ma[u << 1], ma[u << 1 | 1]);
    mi[u] = std::min(mi[u << 1], mi[u << 1 | 1]);
}
inline void get(int u, int l, int r, int x) {
    s[u] = 1ll * (r - l + 1) * x;
    ma[u] = mi[u] = x;
    tg[u] = x;
}
inline void pushdown(int u, int l, int r) {
    if (!tg[u]) return;
    int mid = l + r >> 1;
    get(u << 1, l, mid, tg[u]), get(u << 1 | 1, mid + 1, r, tg[u]), tg[u] = 0;
}
inline void update(int u, int l, int r, int x, int y, int v) {
    if (mi[u] >= v) return;
    if (x <= l && r <= y && ma[u] < v) {
        get(u, l, r, v);
        return;
    }
    int mid = l + r >> 1;
    pushdown(u, l, r);
    if (x <= mid) update(u << 1, l, mid, x, y, v);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, v);
    pushup(u);
}
inline void build(int u, int l, int r) {
    if (l == r) {
        s[u] = ma[u] = mi[u] = l;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        oct::mad(m, x);
        a[x].pub(i);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; i * j <= m; ++j) {
            int e = a[i * j].size();
            if (e <= 4) {
                for (int k = 0; k < e; ++k) ps[i].pub(a[i * j][k]);
            } else {
                ps[i].pub(a[i * j][0]);
                ps[i].pub(a[i * j][1]);
                ps[i].pub(a[i * j][e - 2]);
                ps[i].pub(a[i * j][e - 1]);
            }
        }
    }
    build(1, 1, n);
    for (int i = m; ~i; --i) {
        nm[i] = 1ll * (n + 1) * n - s[1];
        int e = ps[i].size();
        if (e <= 1) continue;
        std::sort(ps[i].begin(), ps[i].end());
        update(1, 1, n, 1, ps[i][0], ps[i][e - 2]);
        update(1, 1, n, ps[i][0] + 1, ps[i][1], ps[i][e - 1]);
        if (ps[i][1] < n) update(1, 1, n, ps[i][1] + 1, n, n + 1);
    }
    for (int i = 1; i <= m; ++i) ans += 1ll * i * (nm[i] - nm[i - 1]);
    std::cout << ans << std::endl;
    return 0;
}