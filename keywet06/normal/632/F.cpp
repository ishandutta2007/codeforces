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
using pi32pi32 = std::pair<int32, pi32>;
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

const int N = 2505;
const int M = N * N;

void failure();

int n, u, v, x, y, cnt, unt, vnt;
int us[N], vs[N], f[N];
int so[M];
int dis[N][N], mat[N][N];

inline void failure() {
    std::cout << "NOT MAGIC" << std::endl;
    exit(0);
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cin >> mat[i][j];
    }
    memset(dis, 1, sizeof(dis));
    for (int i = 1; i <= n; ++i) {
        if (mat[i][i]) failure();
        dis[i][i] = 0, f[i] = i;
        for (int j = 1; j < i; ++j) {
            so[cnt++] = &mat[i][j] - mat[0];
            if (mat[i][j] ^ mat[j][i]) failure();
        }
    }
    std::sort(so, so + cnt,
              [](int x, int y) { return *(mat[0] + x) < *(mat[0] + y); });
    for (int i = 0; i < cnt; ++i) {
        u = so[i] / N, v = so[i] % N;
        if (f[u] == f[v]) continue;
        unt = vnt = 0;
        for (x = 1; x <= n; ++x) {
            if (f[x] == f[u]) us[unt++] = x;
            if (f[x] == f[v]) vs[vnt++] = x;
        }
        for (x = 0; x < unt; ++x) {
            for (y = 0; y < vnt; ++y) {
                dis[us[x]][vs[y]] = dis[vs[y]][us[x]] = mat[u][v];
            }
        }
        for (x = 0; x < vnt; ++x) f[vs[x]] = f[u];
    }
    for (u = 1; u <= n; ++u) {
        for (v = 1; v <= n; ++v) {
            if (mat[u][v] ^ dis[u][v]) failure();
        }
    }
    std::cout << "MAGIC" << std::endl;
    return 0;
}