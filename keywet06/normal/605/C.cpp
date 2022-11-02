#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;
using vi32 = std::vector<int32>;
using qi32 = std::queue<int32>;
using spi32 = std::set<pi32>;

namespace oct {

const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void sync();
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);

inline void sync() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
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

}  // namespace oct

// the pre-document end

const int N = 100005;

double f(double x);

int n, p, q, max;
int a[N], b[N]; 

inline double f(double x) {
    double y = 1;
    for (int i = 1; i <= n; ++i) oct::mid(y, (1.0 - x * b[i]) / a[i]);
    return y * p + x * q;
}

int main() {
    oct::sync();
    std::cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i], oct::mad(max, b[i]);
    double l = 0, r = 1.0 / max, midl, midr;
    for (int i = 1; i <= 100; ++i) {
        midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
        if (f(midl) <= f(midr)) {
            l = midl;
        } else {
            r = midr;
        }
    }
    double ans = f((l + r) / 2);
    std::cout << int(ans) << '.';
    ans -= int(ans);
    for (int i = 1; i <= 15; ++i) {
        ans *= 10;
        std::cout << int(ans);
        ans -= int(ans);
    }
    std::cout << std::endl;
    return 0;
}