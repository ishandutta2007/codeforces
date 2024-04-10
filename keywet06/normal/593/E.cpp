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
using int128 = __int128;
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

class matrix;

const int C = 20;
const int64 mod = 1000000007;

class matrix {
   public:
    int64 d[C][C];
    matrix();
    int64 *operator[](int x);
};

matrix operator*(matrix x, matrix y);
void update(int x, int y);

int n, m, q, p, x, y, t, nx, ny, ti, tmp;
int can[C];
int id[C][C];
matrix now, put, e;

inline matrix::matrix() { memset(d, 0, sizeof(d)); }
inline int64 *matrix::operator[](int x) { return d[x]; }
inline matrix operator*(matrix x, matrix y) {
    matrix ans;
    register int i, j, k;
    for (i = 0; i < C; ++i) {
        for (j = 0; j < C; ++j) {
            for (k = 0; k < C; ++k) ans[i][j] += x[i][k] * y[k][j] % mod;
            ans[i][j] %= mod;
        }
    }
    return ans;
}
inline void update(int x, int y) {
    put[id[x][y]][id[x][y]] = can[id[x][y]];
    for (int i = 0; i < 4; ++i) {
        nx = x + oct::tn4[i][0];
        ny = y + oct::tn4[i][1];
        if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
        nx = id[nx][ny], ny = id[x][y];
        put[nx][ny] = put[ny][nx] = can[nx] && can[ny];
    }
}
inline matrix power(matrix x, int y) {
    return y ? power(x * x, y / 2) * (y & 1 ? x : e) : e;
}

int main() {
    oct::sync();
    std::cin >> n >> m >> q;
    now[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) id[i][j] = i * m + j;
    }
    for (int i = 0; i < n * m; ++i) can[i] = 1, e[i][i] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            x = id[i][j - 1], y = id[i][j];
            put[x][y] = put[y][x] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = id[i - 1][j], y = id[i][j];
            put[x][y] = put[y][x] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) x = id[i][j], put[x][x] = 1;
    }
    ti = 1;
    while (q--) {
        std::cin >> p >> x >> y >> t;
        --x, --y;
        now = power(put, t - ti) * now;
        if (p == 1) {
            std::cout << now[id[x][y]][0] << '\n';
        } else if (p == 2) {
            can[id[x][y]] = 0;
            update(x, y);
        } else {
            can[id[x][y]] = 1;
            update(x, y);
        }
        ti = t;
    }
    return 0;
}