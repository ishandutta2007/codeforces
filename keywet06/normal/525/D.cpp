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
 
const int C = 4;
const int N = 2005;
char p[N][N], v[N][N];
int n, m, fl, fr, fu, fd, bl, br, bu, bd, flag;
inline void change(int x, int y) { p[x][y] = !(v[x][y] = 1); }
inline void update(int x, int y) {
    bl = br = x, bd = bu = y, v[x][y] = 1;
    fl = !p[x - 1][y], fr = !p[x + 1][y], fd = !p[x][y - 1], fu = !p[x][y + 1];
    while (fl + fr + fd + fu) {
        while (fr) {
            ++br, fr = 0;
            for (int i = bd; i <= bu; ++i) change(br, i), fr |= !p[br + 1][i];
            fd |= !p[br][bd - 1], fu |= !p[br][bu + 1];
        }
        while (fu) {
            ++bu, fu = 0;
            for (int i = bl; i <= br; ++i) change(i, bu), fu |= !p[i][bu + 1];
            fl |= !p[bl - 1][bu], fr |= !p[br + 1][bu];
        }
        while (fl) {
            --bl, fl = 0;
            for (int i = bd; i <= bu; ++i) change(bl, i), fl |= !p[bl - 1][i];
            fd |= !p[bl][bd - 1], fu |= !p[bl][bu + 1];
        }
        while (fd) {
            --bd, fd = 0;
            for (int i = bl; i <= br; ++i) change(i, bd), fd |= !p[i][bd - 1];
            fl |= !p[bl - 1][bd], fr |= !p[br + 1][bd];
        }
    }
}
int main() {
    oct::sync();
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> p[i] + 1;
    for (int i = 1; i <= n; ++i) {
        p[i][0] = p[i][m + 1] = 1;
        for (int j = 1; j <= m; ++j) p[i][j] = p[i][j] == '*';
    }
    for (int i = 1; i <= m; ++i) p[0][i] = p[n + 1][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i][j] || p[i][j]) continue;
            update(i, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) p[i][j] = p[i][j] ? '*' : '.';
        p[i][m + 1] = 0;
        std::cout << p[i] + 1 << '\n';
    }
    return 0;
}