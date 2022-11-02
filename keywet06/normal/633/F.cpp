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
using pi32 = std::pair<int32, int32>;
using pi32pi32 = std::pair<int32, pi32>;
using cpdr = std::complex<dr>;
using vi32 = std::vector<int32>;
using qi32 = std::queue<int32>;
using spi32 = std::set<pi32>;
using spi32it = spi32::iterator;

namespace oct {

/* Array tn4 is the 4-direction changes in coordinate system.
 * The directions in order is {right, up, left, down}.
 */
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
template <typename _Tp>
_Tp power(_Tp x, int m);
template <typename _Tp>
void sort(_Tp &x, _Tp &y);

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
template <typename _Tp>
inline _Tp power(_Tp x, int m) {
    return m == 1 ? x : (m & 1 ? power(x * x, m / 2) * x : power(x * x, m / 2));
}
template <typename _Tp>
inline void sort(_Tp &x, _Tp &y) {
    if (x > y) std::swap(x, y);
}

}  // namespace oct

// the pre-document end

const int B = 2;
const int N = 100005;

void dfs(int u, int fa);

int n, u, v;
int64 a[N], g[N], h[N], down[N];
int64 f[N][B];
vi32 to[N];

inline void dfs(int u, int fa) {
    f[u][0] = f[u][1] = g[u] = down[u] = a[u];
    for (int v : to[u]) {
        if (v == fa) continue;
        dfs(v, u);
        oct::mad(f[u][0], f[v][0]);
        oct::mad(f[u][0], f[u][1] + f[v][1]);
        oct::mad(f[u][0], down[u] + g[v]);
        oct::mad(f[u][0], down[v] + g[u]);
        oct::mad(f[u][1], f[v][1]);
        oct::mad(f[u][1], down[u] + down[v]);
        oct::mad(g[u], g[v] + a[u]);
        oct::mad(g[u], down[u] + f[v][1]);
        oct::mad(g[u], down[v] + a[u] + h[u]);
        oct::mad(h[u], f[v][1]);
        oct::mad(down[u], a[u] + down[v]);
    }
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i < n; ++i) std::cin >> u >> v, to[u].pub(v), to[v].pub(u);
    dfs(1, 0);
    std::cout << f[1][0] << std::endl;
    return 0;
}