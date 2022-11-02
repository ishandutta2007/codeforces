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

const int M = 500;
const int N = 100005;
const int64 mod = 1000000007;

void init();
int64 C(int m, int n);
void insert(int x);

char str[N];
int n, l, cnt, x, y;
int ans[M][N];
int64 pre[N], inv[N], re[N], id[N];

inline void init() {
    pre[0] = inv[0] = inv[1] = re[0] = 1;
    for (int i = 1; i < N; ++i) pre[i] = pre[i - 1] * i % mod;
    for (int i = 2; i < N; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i < N; ++i) re[i] = re[i - 1] * inv[i] % mod;
}
inline int64 C(int m, int n) { return pre[m] * re[m - n] % mod * re[n] % mod; }
inline void insert(int x) {
    if (id[x]) return;
    id[x] = ++cnt;
    int64 tmp = 1;
    for (int i = x; i < N; ++i) {
        ans[cnt][i] = (ans[cnt][i - 1] * 26ll + C(i - 1, x - 1) * tmp) % mod;
        tmp = tmp * 25 % mod;
    }
}

int main() {
    oct::sync();
    init();
    std::cin >> n;
    std::cin >> str, l = strlen(str);
    insert(l);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        if (x == 1) {
            std::cin >> str, l = strlen(str);
            insert(l);
        } else {
            std::cin >> y;
            std::cout << ans[id[l]][y] << '\n';
        }
    }
    return 0;
}