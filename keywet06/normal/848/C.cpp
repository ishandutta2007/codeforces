// oct code object CF/CF848C.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF848Cx2eCPP
#define OCT_CODE_OBJECT_CFx2fCF848Cx2eCPP

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

const int N = 700009;

struct que {
    int x, y, opt, v;
};

void upd(int x, int k);
int64 qu(int x);
void cdq(int l, int r);

int n, m, cnt, q_num;
int a[N], b[N], pre[N];
int64 c[N], ans[N];
std::set<int> S[N];
std::set<int>::iterator it;
que Q[N], tmp[N];

inline void upd(int x, int k) {
    for (; x <= n + 1; x += (x & -x)) c[x] += k;
}
inline int64 qu(int x) {
    int64 ans = 0;
    for (; x; x -= (x & -x)) ans += c[x];
    return ans;
}
inline void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    int i = l, j = mid + 1, k = l - 1;
    while (i <= mid || j <= r)
        if (j > r || i <= mid && (Q[i].x < Q[j].x ||
                                  Q[i].x == Q[j].x && Q[i].opt < Q[j].opt)) {
            if (Q[i].opt == 1) upd(Q[i].y, Q[i].v);
            tmp[++k] = Q[i], ++i;
        } else {
            if (Q[j].opt == 2) {
                Q[j].v > 0 ? ans[Q[j].v] += qu(Q[j].y)
                           : ans[-Q[j].v] -= qu(Q[j].y);
            }
            tmp[++k] = Q[j], ++j;
        }
    for (int i = l; i <= mid; ++i) {
        if (Q[i].opt == 1) upd(Q[i].y, -Q[i].v);
    }
    for (int i = l; i <= r; ++i) Q[i] = tmp[i];
    for (int i = l; i <= r; ++i) ans[Q[i].v] += qu(Q[j].y) - qu(Q[j].x);
}

int main() {
    oct::sync();
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i], pre[i] = b[a[i]], b[a[i]] = i, S[a[i]].insert(i),
                          Q[++q_num] = (que){i, pre[i], 1, i - pre[i]};
    }
    for (int i = 1, opt, x, y; i <= m; ++i) {
        std::cin >> opt >> x >> y;
        if (opt == 1) {
            int p1 = 0, n1 = 0;
            it = S[a[x]].find(x);
            if (it != S[a[x]].begin()) --it, p1 = *it, ++it;
            if ((++it) != S[a[x]].end()) n1 = *it;
            --it, S[a[x]].erase(*it);
            Q[++q_num] = (que){x, pre[x], 1, pre[x] - x};
            if (n1) {
                Q[++q_num] = (que){n1, pre[n1], 1, pre[n1] - n1};
                Q[++q_num] = (que){n1, pre[n1] = p1, 1, n1 - pre[n1]};
            }
            int p2 = 0, n2 = 0;
            a[x] = y, S[a[x]].insert(x), it = S[a[x]].find(x);
            if (it != S[a[x]].begin()) --it, p2 = *it, ++it;
            if ((++it) != S[a[x]].end()) n2 = *it;
            --it, pre[x] = p2, Q[++q_num] = (que){x, pre[x], 1, x - pre[x]};
            if (n2) {
                Q[++q_num] = (que){n2, pre[n2], 1, pre[n2] - n2};
                Q[++q_num] = (que){n2, pre[n2] = x, 1, n2 - pre[n2]};
            }
        } else {
            ++cnt;
            Q[++q_num] = (que){x - 1, x - 1, 2, cnt};
            Q[++q_num] = (que){y, y, 2, cnt};
            Q[++q_num] = (que){x - 1, y, 2, -cnt};
            Q[++q_num] = (que){y, x - 1, 2, -cnt};
        }
    }
    for (int i = 1; i <= q_num; ++i) Q[i].x++, Q[i].y++;
    cdq(1, q_num);
    for (int i = 1; i <= cnt; ++i) std::cout << ans[i] << std::endl;
}

#endif  // oct code end CF/CF848C.cpp