// oct code object CF/CF799E.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF799Ex2eCPP
#define OCT_CODE_OBJECT_CFx2fCF799Ex2eCPP

// oct code object pre-document.cpp
#ifndef OCT_CODE_OBJECT_PREx2dDOCUMENTx2eCPP
#define OCT_CODE_OBJECT_PREx2dDOCUMENTx2eCPP

#if defined(ONLINE_JUDGE) && !defined(LUOGU)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")
#endif

// oct code object stl/bits/stdc++.h
#ifndef OCT_CODE_OBJECT_STL_BITSx2fSTDCx2bx2bx2fH
#define OCT_CODE_OBJECT_STL_BITSx2fSTDCx2bx2bx2fH
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

#endif  // oct code end pre-document.cpp

const int N = 200010;
const int M = N << 2;
int64 ans;
int n, m, k, na, nb, nc, nd, t;
int A[N], B[N], C[N], D[N], v[N], tag[N], p[N], ta[N], tb[N], td[N];
int ca[M], cb[M], cd[M];
int64 sa[N], sb[N], sd[N], ref[N];

bool cmp(const int &a, const int &b) { return v[a] < v[b]; }
void insert(int l, int r, int x, int a, int b, int c) {
    if (c == 0) ca[x] = b;
    if (c == 1) cb[x] = b;
    if (c == 2) cd[x] = b;
    if (l == r) return;
    int mid = (l + r) >> 1;
    a <= mid ? insert(l, mid, x << 1, a, b, c)
             : insert(mid + 1, r, x << 1 | 1, a, b, c);
}
int64 query(int l, int r, int x, int a) {
    if (l == r) {
        return sa[std::max(ca[x], a)] + sb[std::max(cb[x], a)] + sd[cd[x]] -
               ref[l] * (std::max(ca[x], a) + std::max(cb[x], a) + cd[x] + k -
                         a - m);
    }
    int mid = (l + r) >> 1, t = std::max(ca[x << 1], a) +
                                std::max(cb[x << 1], a) + cd[x << 1] + k - a;
    return t >= m ? query(l, mid, x << 1, a) : query(mid + 1, r, x << 1 | 1, a);
}
void build(int l, int r, int x) {
    if (l == r) return ca[x] = ta[l], cb[x] = tb[l], cd[x] = td[l], void(0);
    int mid = (l + r) >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    ca[x] = ca[x << 1 | 1], cb[x] = cb[x << 1 | 1], cd[x] = cd[x << 1 | 1];
}
int main() {
    std::cin >> n >> m >> k;
    int i, a, b;
    for (i = 1; i <= n; ++i) std::cin >> v[i], p[i] = i;
    std::sort(p + 1, p + n + 1, cmp);
    for (i = 1; i <= n; ++i) {
        if (i == 1 || v[p[i]] > ref[t]) ref[++t] = v[p[i]];
        v[p[i]] = t;
    }
    std::cin >> a;
    for (i = 1; i <= a; ++i) std::cin >> b, tag[b] |= 1;
    std::cin >> a;
    for (i = 1; i <= a; ++i) std::cin >> b, tag[b] |= 2;
    for (i = 1; i <= n; ++i) {
        if (tag[i] == 0) D[++nd] = ref[v[i]], td[v[i]]++;
        if (tag[i] == 1) A[++na] = ref[v[i]], ta[v[i]]++;
        if (tag[i] == 2) B[++nb] = ref[v[i]], tb[v[i]]++;
        if (tag[i] == 3) C[++nc] = ref[v[i]];
    }
    std::sort(A + 1, A + na + 1), std::sort(B + 1, B + nb + 1);
    std::sort(C + 1, C + nc + 1), std::sort(D + 1, D + nd + 1);
    for (i = 1; i <= t; ++i) {
        ta[i] += ta[i - 1], tb[i] += tb[i - 1], td[i] += td[i - 1];
    }
    for (i = 1; i <= na; ++i) sa[i] = sa[i - 1] + A[i];
    for (i = 1; i <= nb; ++i) sb[i] = sb[i - 1] + B[i];
    for (i = 1; i <= nd; ++i) sd[i] = sd[i - 1] + D[i];
    int64 sum = 0;
    ans = 1ll << 60;
    build(0, t, 1);
    for (i = 0; i <= std::min(nc, m); ++i) {
        sum += C[i];
        if (std::min(na, nb) >= k - i && 2 * k - i <= m &&
            i + na + nb + nd >= m) {
            ans = std::min(ans, sum + query(0, t, 1, k - i));
        }
    }
    std::cout << (ans == 1ll << 60 ? -1 : ans) << std::endl;
    return 0;
}

#endif  // oct code end CF/CF799E.cpp