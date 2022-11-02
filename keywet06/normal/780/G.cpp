// oct code object CF/CF780G.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF780Gx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF780Gx2eCPP

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

const int N = 1e5 + 10;
const int P = 1e9 + 7;

struct barrier {
    int h, l, r, s;
    bool operator<(const barrier &b) const { return h > b.h; }
};
struct group {
    int h, x;
    group(int _h, int _x) : h(_h), x(_x) {}
};
struct node {
    int l, r, x;
};

int tot, h, n, w;
node t[N << 1];
barrier b[N];
std::stack<group> s[N];

inline void build(int p, int l, int r) {
    if (l == r) return t[p].x = l, void(0);
    int mid = (l + r) >> 1;
    t[p].l = ++tot, t[p].r = ++tot;
    build(t[p].l, l, mid), build(t[p].r, mid + 1, r);
    t[p].x = t[t[p].l].x;
}
inline void del(int p, int l, int r, int pos) {
    int mid = (l + r) >> 1;
    if (l == r) return s[pos].pop();
    int ls = t[p].l, rs = t[p].r;
    pos <= mid ? del(ls, l, mid, pos) : del(rs, mid + 1, r, pos);
    int x = t[ls].x, y = t[rs].x;
    t[p].x = s[y].empty()
                 ? x
                 : (s[x].empty() ? y : (s[x].top().h <= s[y].top().h ? x : y));
}
inline void add(int p, int l, int r, int pos, const group g) {
    int mid = (l + r) >> 1;
    if (l == r) return s[pos].push(g);
    int ls = t[p].l, rs = t[p].r;
    pos <= mid ? add(ls, l, mid, pos, g) : add(rs, mid + 1, r, pos, g);
    int x = t[ls].x, y = t[rs].x;
    t[p].x = s[y].empty()
                 ? x
                 : (s[x].empty() ? y : (s[x].top().h <= s[y].top().h ? x : y));
}
inline int query(int p, int l, int r, int L, int R) {
    int mid = (l + r) >> 1;
    if (l == L && r == R) return t[p].x;
    int ls = t[p].l, rs = t[p].r;
    if (R <= mid) return query(ls, l, mid, L, R);
    if (L > mid) return query(rs, mid + 1, r, L, R);
    int x = query(ls, l, mid, L, mid), y = query(rs, mid + 1, r, mid + 1, R);
    return s[y].empty()
               ? x
               : (s[x].empty() ? y : s[x].top().h <= s[y].top().h ? x : y);
}

int main() {
    oct::sync();
    std::cin >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i].h >> b[i].l >> b[i].r >> b[i].s;
    }
    std::sort(b + 1, b + 1 + n);
    build(0, 1, w);
    for (int i = 1; i <= w; i++) s[i].push(group(h + 1, 1));
    for (int i = 1; i <= n; i++) {
        group p(b[i].h, 0);
        while (1) {
            int j = query(0, 1, w, b[i].l, b[i].r);
            if (s[j].empty()) break;
            group tmp = s[j].top();
            if (tmp.h > b[i].h + b[i].s) break;
            del(0, 1, w, j), p.x = (p.x + tmp.x) % P;
        }
        if (b[i].l == 1) {
            p.x = (p.x + p.x) % P, add(0, 1, w, b[i].r + 1, p);
        } else if (b[i].r == w) {
            p.x = (p.x + p.x) % P, add(0, 1, w, b[i].l - 1, p);
        } else {
            add(0, 1, w, b[i].l - 1, p), add(0, 1, w, b[i].r + 1, p);
        }
    }
    int sum = 0;
    for (int i = 1; i <= w; i++) {
        while (!s[i].empty()) sum = (sum + s[i].top().x) % P, s[i].pop();
    }
    std::cout << sum << std::endl;
    return 0;
}

#endif  // oct code end CF/CF780G.cpp