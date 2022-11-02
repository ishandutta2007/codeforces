#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define fir first
#define sec second

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;

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

const int C = 3;
const int N = 10000005;
int max, n, x;
int b[C];
int a[N], c[N];
int64 ans = 1ll << 60;
int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        a[x] ? c[x] = i : a[x] = i;
        if (x > max) max = x;
    }
    for (int i = 1; i <= max; ++i) {
        int v[3], id[3], tot = 0;
        for (int j = i; tot < 2 && j <= max; j += i) {
            if (a[j]) {
                v[++tot] = j, id[tot] = a[j];
                if (c[j] && tot != 2) v[++tot] = j, id[tot] = c[j];
            }
        }
        if (tot == 2 && ans > 1ll * v[1] * v[2] / i) {
            ans = 1ll * v[1] * v[2] / i;
            b[1] = id[1], b[2] = id[2];
        }
    }
    if (b[1] > b[2]) b[1] ^= b[2] ^= b[1] ^= b[2];
    std::cout << b[1] << ' ' << b[2] << std::endl;
    return 0;
}