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

const int M = 40000005;
const int N = 200005;

class node {
   public:
    int64 x, y, d;
};

int c, n, x, y, k, l, tt;
int px[N], py[N], t[N];
int num[M];
int64 ans[N];
node s[N];

int main() {
    oct::sync();
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> px[i] >> py[i], t[i] = i;
    std::sort(t + 1, t + n + 1, [](int x, int y) { return py[x] < py[y]; });
    l = -2000000000, c = 1;
    for (int i = 1; i <= n; ++i) {
        tt = py[t[i]];
        if (l + k < py[t[i]]) {
            py[t[i]] = c += k;
        } else {
            py[t[i]] = c += py[t[i]] - l;
        }
        l = tt;
    }
    c = 0;
    for (int i = 1; i <= n; ++i) {
        s[c++] = {px[i], py[i], 1}, s[c++] = {px[i] + k, py[i], -1};
    }
    std::sort(s, s + c, [](node x, node y) { return x.x < y.x; });
    for (int i = 0; i < c; ++i) {
        for (int j = s[i].y - k + 1; j <= s[i].y; ++j) {
            ans[num[j]] += s[i].x;
            ans[num[j] += s[i].d] -= s[i].x;
        }
    }
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
    std::cout << std::endl;
    return 0;
}