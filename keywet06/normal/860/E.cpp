// oct code object CF/CF860E.cpp
#ifndef OCT_CODE_OBJECT_CFx2fCF860Ex2eCPP
#define OCT_CODE_OBJECT_CFx2fCF860Ex2eCPP

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

#define int int64

struct tree {
    int64 get(int l, int r) { return get_do(0, 0, cnt, l, r); }

    void incr(int l, int r, int64 c) { incr_do(0, 0, cnt, l, r, c); }

    int64 get_do(int no, int nl, int nr, int l, int r) {
        push(no, nl, nr);
        if (l <= nl and nr <= r) return vals[no];
        if (r <= nl or nr <= l) return 0;

        int mi = nl + (nr - nl) / 2;
        return get_do(2 * no + 1, nl, mi, l, r) +
               get_do(2 * no + 2, mi, nr, l, r);
    }

    void push(int no, int nl, int nr) {
        if (mods[no]) {
            vals[no] += (nr - nl) * mods[no];

            if (nl != nr - 1) {
                mods[2 * no + 1] += mods[no];
                mods[2 * no + 2] += mods[no];
            }
        }
        mods[no] = 0;
    }

    void incr_do(int no, int nl, int nr, int l, int r, int64 c) {
        push(no, nl, nr);

        if (l <= nl and nr <= r) {
            mods[no] += c;
            return;
        }

        if (r <= nl or nr <= l) return;

        int mi = nl + (nr - nl) / 2;
        incr_do(2 * no + 1, nl, mi, l, r, c);
        incr_do(2 * no + 2, mi, nr, l, r, c);
        vals[no] += c * (std::min(nr, r) - std::max(l, nl));
    }

    std::vector<int64> vals;
    std::vector<int64> mods;
    int cnt = 0;
};

const int N = 600000;

int ws[N];

int pi[N], si[N], par[N], dt[N];
std::vector<int> tops;
std::vector<int> gh[N], dl[N];
std::vector<tree> ps;

int build(int v) {
    ws[v] = 1;
    for (int u : gh[v]) {
        dt[u] = dt[v] + 1, par[u] = v, dl[dt[u]].pub(u), ws[v] += build(u);
    }
    if (gh[v].empty()) {
        ps.resize(ps.size() + 1), ps.back().cnt += 1, tops.pub(v);
        pi[v] = ps.size() - 1, si[v] = 0;
    } else {
        int hv = -1;
        for (int u : gh[v]) {
            if (hv == -1 || ws[u] > ws[hv]) hv = u;
        }
        ps[pi[hv]].cnt += 1, tops[pi[hv]] = v;
        pi[v] = pi[hv], si[v] = si[hv] + 1;
    }

    return ws[v];
}

int64 ans[N];

int32 main() {
    int n, root = -1, p;
    std::cin >> n;
    for (int i = 0; i != n; ++i) {
        std::cin >> p, --p == -1 ? void(root = i) : void(gh[p].pub(i));
    }
    par[root] = -1;
    dl[0].pub(root);
    build(root);
    for (int i = 0; i != ps.size(); ++i) {
        ps[i].vals.resize(ps[i].cnt * 4), ps[i].mods.resize(ps[i].cnt * 4);
    }
    for (int d = 0; !dl[d].empty(); ++d) {
        for (int v : dl[d]) {
            int x = par[v];
            while (x != -1) {
                ps[pi[x]].incr(si[x], ps[pi[x]].cnt, +1), x = par[tops[pi[x]]];
            }
        }
        for (int v : dl[d]) {
            ans[v] = 0;
            int x = par[v];
            while (x != -1) {
                ans[v] += ps[pi[x]].get(si[x], ps[pi[x]].cnt);
                x = par[tops[pi[x]]];
            }
        }
    }
    for (int i = 0; i != n; ++i) std::cout << ans[i] << ' ';
    std::cout << std::endl;
    return 0;
}

#endif  // oct code end CF/CF860E.cpp