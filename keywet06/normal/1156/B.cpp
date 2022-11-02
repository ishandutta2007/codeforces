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
 
const int C = 26;
 
void put(int x);
 
int T, cnt;
int c[C], f[C];
std::string s;
 
inline void put(int x) {
    for (int i = 0; i < c[x]; ++i) std::cout << char(x + 'a');
}
 
int main() {
    oct::sync();
    std::cin >> T;
    while (T--) {
        cnt = 0;
        memset(c, 0, sizeof(c));
        std::cin >> s;
        for (char ch : s) ++c[ch - 'a'];
        for (int i = 0; i < C; ++i) {
            if (c[i]) f[cnt++] = i;
        }
        if (cnt == 2 && f[0] + 1 == f[1] ||
            cnt == 3 && f[0] + 1 == f[1] && f[1] + 1 == f[2]) {
            std::cout << "No answer" << std::endl;
            continue;
        }
        if (cnt == 3 && f[0] + 1 == f[1]) {
            put(f[0]), put(f[2]), put(f[1]);
        } else if (cnt == 3 && f[1] + 1 == f[2]) {
            put(f[1]), put(f[0]), put(f[2]);
        } else {
            for (int i = 1; i < cnt; i += 2) put(f[i]);
            for (int i = 0; i < cnt; i += 2) put(f[i]);
        }
        std::cout << std::endl;
    }
    return 0;
}