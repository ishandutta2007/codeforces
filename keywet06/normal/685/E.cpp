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

struct Req {
    int64 l, r, s, t, id;
};
struct Edge {
    int64 v, u, prev1, prev2, next1, next2;
};

const int64 Q = 200000;
const int64 N = 1000;
const int64 M = 200000;

void solve_layer(std::vector<Req> &requests, int64 l, int64 m, int64 r);

char answers[Q];
Edge list[M];
std::vector<int64> fl[N];
std::bitset<N> masks_r[M / 2 + 10];
std::bitset<N> masks_l[M / 2 + 10];

inline void solve_layer(std::vector<Req> &requests, int64 l, int64 m, int64 r) {
    bool has = 0;
    for (int64 i = 0; i != requests.size(); ++i) {
        has |= (requests[i].l <= m - 1 && requests[i].r >= m);
    }
    if (!has) return;
    for (int64 i = 0; i != r - m; ++i) {
        masks_r[i] = std::bitset<N>();
        if (list[m + i].prev1 >= m &&
            list[m + i].prev1 != std::numeric_limits<int64>::max()) {
            masks_r[i] |= masks_r[list[m + i].prev1 - m];
        }
        if (list[m + i].prev2 >= m &&
            list[m + i].prev2 != std::numeric_limits<int64>::max()) {
            masks_r[i] |= masks_r[list[m + i].prev2 - m];
        }
        masks_r[i][list[m + i].v] = true;
        masks_r[i][list[m + i].u] = true;
    }
    for (int64 z = 0; z != m - l; ++z) {
        int64 i = (m - l) - 1 - z;
        masks_l[i] = std::bitset<N>();
        if (list[l + i].next1 < m) masks_l[i] |= masks_l[list[l + i].next1 - l];
        if (list[l + i].next2 < m) masks_l[i] |= masks_l[list[l + i].next2 - l];
        masks_l[i][list[l + i].v] = true;
        masks_l[i][list[l + i].u] = true;
    }
    for (int64 i = 0; i != requests.size();) {
        if (requests[i].l <= m - 1 && requests[i].r >= m) {
            answers[requests[i].id] =
                (masks_r[requests[i].r - m] & masks_l[requests[i].l - l]).any();
            std::swap(requests[i], requests.back());
            requests.pop_back();
        } else {
            ++i;
        }
    }
}
inline void solve(std::vector<Req> &requests, int64 l, int64 r) {
    if (l == r - 1) {
        for (auto &req : requests) {
            answers[req.id] = (req.s == list[l].v || req.s == list[l].u) &&
                              (req.t == list[l].v || req.t == list[l].u);
        }
        return;
    }
    int64 m = l + (r - l) / 2;
    solve_layer(requests, l, m, r);
    std::vector<Req> right;
    for (int64 i = 0; i != requests.size();) {
        if (requests[i].l >= m) {
            right.push_back(requests[i]);
            std::swap(requests[i], requests.back());
            requests.pop_back();
        } else {
            ++i;
        }
    }
    requests.shrink_to_fit();
    solve(requests, l, m);
    solve(right, m, r);
}
int main() {
    oct::sync();
    int64 n, m, q;
    std::cin >> n >> m >> q;
    std::fill(answers, answers + q, 16);
    for (int64 i = 0; i != m; ++i) {
        std::cin >> list[i].v >> list[i].u;
        --list[i].v, --list[i].u;
        list[i].prev1 = list[i].prev2 = list[i].next1 = list[i].next2 =
            std::numeric_limits<int64>::max();
        if (!fl[list[i].v].empty()) {
            auto tmp = list[i].prev1 = fl[list[i].v].back();
            (list[tmp].v == list[i].v ? list[tmp].next1 : list[tmp].next2) = i;
        }
        if (!fl[list[i].u].empty()) {
            auto tmp = list[i].prev2 = fl[list[i].u].back();
            (list[tmp].v == list[i].u ? list[tmp].next1 : list[tmp].next2) = i;
        }
        fl[list[i].v].push_back(i);
        fl[list[i].u].push_back(i);
    }
    std::vector<Req> requests;
    for (int64 i = 0; i != q; ++i) {
        Req req;
        std::cin >> req.l >> req.r >> req.s >> req.t;
        --req.l, --req.r, --req.s, --req.t;
        req.id = i;
        auto it1 = std::lower_bound(fl[req.s].begin(), fl[req.s].end(), req.l);
        auto it2 = std::upper_bound(fl[req.t].begin(), fl[req.t].end(), req.r);
        if (it1 == fl[req.s].end() || it2 == fl[req.t].begin()) {
            answers[i] = 0;
        } else {
            req.l = *it1;
            req.r = *std::prev(it2);
            req.l > req.r ? answers[i] = 0 : (requests.push_back(req), 0);
        }
    }
    solve(requests, 0, m);
    for (int64 i = 0; i != q; ++i) std::cout << (answers[i] ? "Yes\n" : "No\n");
    return 0;
}