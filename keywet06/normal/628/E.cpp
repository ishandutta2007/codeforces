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

const int B = 2;
const int N = 3010;

struct node {
    int x, y;
};

char s[N];
int n, m;
int a[N][N], c[N][N];
int b[N][N][B];
node t;
std::vector<node> d[N];

void add(int x, int y, int k) {
    while (x < N) c[x][y] += k, x += x & (-x);
}
int sum(int x, int y) {
    int res = 0;
    while (x > 0) res += c[x][y], x -= x & (-x);
    return res;
}

int main() {
    oct::sync();
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s + 1;
        for (int j = 1; j <= m; ++j) a[i][j] = s[j] == 'z';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
            if (a[i][j]) {
                b[i][j][0] = b[i][j + 1][0] + 1,
                b[i][j][1] = b[i - 1][j + 1][1] + 1;
            }
        }
    }
    int64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j)
            if (a[i][j]) {
                add(i, j, 1), t.x = i, t.y = j;
                if (i + b[i][j][0] - 1 < N) d[i + b[i][j][0] - 1].push_back(t);
                ans += sum(i, j) - sum(i - std::min(b[i][j][0], b[i][j][1]), j);
            }
        for (int j = 0; j < d[i].size(); j++) add(d[i][j].x, d[i][j].y, -1);
    }
    std::cout << ans << std::endl;
    return 0;
}