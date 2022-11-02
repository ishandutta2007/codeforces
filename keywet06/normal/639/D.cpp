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
using pi64 = std::pair<int64, int64>;
using pi64i32 = std::pair<int64, int32>;
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
_Tp power(_Tp x, int64 m);
template <typename _Tp>
void sort(_Tp &x, _Tp &y);
template <typename _Tp1, typename _Tp2>
std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                std::pair<_Tp1, _Tp2> y);
template <typename _Tp>
_Tp &operator+=(_Tp &x, _Tp y);

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

// the pre-document end

const int N = 2e5 + 7;
const int64 INF = 0x3f3f3f3f3f3f3f3f;

int64 solve(pi64 *a, int64 b, int64 c);

int n, k, b, c, t[N];
int64 ans = INF, cnt = 0;
pi64 a[N];
std::priority_queue<pi64i32> que;

inline int64 solve(pi64 *a, int64 b, int64 c) {
    while(!que.empty()) que.pop();
    cnt = 0;
    int64 ans = INF, ret = 0;
    for(int i = 1; i <= k; ++i) {
        ret += a[i].sec * c;
        ret += (a[i].fir - a[i - 1].fir) * cnt * b;
        que.push(std::mkp(c * a[i].sec + (a[1].fir - a[i].fir) * b, i));
        cnt++;
    }
    oct::mid(ans, ret);
    for(int i = k + 1; i <= n; ++i) {
        int p = que.top().sec; que.pop(); cnt--;
        ret -= a[p].sec * c;
        ret -= (a[i - 1].fir - a[p].fir) * b;
        ret += (a[i].fir - a[i - 1].fir) * cnt * b;
        ret += a[i].sec * c;
        que.push(std::mkp(c * a[i].sec + (a[1].fir - a[i].fir) * b, i));
        cnt++;
        oct::mid(ans, ret);
    }
    return ans;
}

int main() {
    oct::sync();
    std::cin >> n >> k >> b >> c;
    for(int i = 1; i <= n; ++i) std::cin >> t[i], t[i] += 1000000000;
    std::sort(t + 1, t + 1 + n);
    for(int i = 1; i <= n; ++i) a[i].fir = t[i], a[i].sec = 0;
    oct::mid(ans, solve(a, c, 0));
    for(int j = 0; j < 5; ++j) {
        for(int i = 1; i <= n; ++i) {
            a[i].sec = ((j - (t[i] % 5)) + 5) % 5;
            a[i].fir = (t[i] + a[i].sec) / 5;
        }
        oct::mid(ans, solve(a, b, c));
    }
    std::cout << ans << std::endl;
    return 0;
}