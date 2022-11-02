// oct code title CF/CF703E.cpp

#ifndef OCT_CODE_INSERT_PREx2DDOCUMENT  // oct code insert pre-document
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

const int N = 1005;
const int M = 10000;
const int K = 1000005;

int64 n, k, m;
int64 a[N], b[N];
pi64 f[N][8000];
std::vector<int64> v;
std::map<int64, int> id;

inline void init() {
    v.clear();
    for (int64 i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            v.push_back(i);
            if (i * i != k) v.push_back(k / i);
        }
    }
    std::sort(v.begin(), v.end());
    m = v.size() - 1;
    id.clear();
    for (int i = 0; i <= m; i++) id[v[i]] = i;
}
inline int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    oct::sync();
    std::cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++) std::cin >> a[i], b[i] = gcd(a[i], k);
    if (k == 1) {
        std::cout << 1 << std::endl;
        std::cout << std::min_element(a + 1, a + 1 + n) - a << std::endl;
        return 0;
    }
    for (int j = 1; j <= m; j++) f[0][j] = pi64(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            int pre = id[v[j] / gcd(v[j], b[i])];
            pi64 t = pi64(f[i - 1][pre].first + 1, f[i - 1][pre].second + a[i]);
            f[i][j] = min(f[i][j], t);
        }
    }
    if (f[n][m].first > n) {
        std::cout << -1;
    } else {
        std::cout << f[n][m].first << std::endl;
        for (int i = n; i >= 1; i--) {
            if (f[i][id[k]] != f[i - 1][id[k]]) {
                std::cout << i << ' ', k /= gcd(k, b[i]);
            }
        }
    }
    std::cout << std::endl;
    return 0;
}