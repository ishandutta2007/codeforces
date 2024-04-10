#ifndef OCT_INSERT_PRE_DOCUMENT  // oct insert "pre-document"
#define OCT_INSERT_PRE_DOCUMENT
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
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

#endif  // oct end "pre-document"

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define RC rotating_calipers

using namespace std;

const int maxn = 100010;

struct point {
    ll x, y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator<(const point &c) const {
        return x < c.x || (x == c.x && y < c.y);
    }
    point operator-(const point &c) const { return point(x - c.x, y - c.y); }
};

ll det(point A, point B) { return A.x * B.y - A.y * B.x; }
ll det(point O, point A, point B) { return det(A - O, B - O); }

point a[maxn], ch[maxn], A, B, C;

void convexhull(int n, int &top) {
    sort(a + 1, a + n + 1);
    top = 0;
    for (int i = 1; i <= n; i++) {
        while (top > 1 && det(ch[top - 1], ch[top], a[i]) <= 0) top--;
        ch[++top] = a[i];
    }
    int ttop = top;
    for (int i = n - 1; i >= 1; i--) {
        while (top > ttop && det(ch[top - 1], ch[top], a[i]) <= 0) top--;
        ch[++top] = a[i];
    }
}
void rotating_calipers(point p[], int top) {
    ll ans = 0;
    int now;
    rep(i, 1, top - 2) {
        int now = i + 2;
        rep(j, i + 1, top - 1) {
            while (now <= top && abs(det(p[i], p[j], p[now])) <
                                     abs(det(p[i], p[j], p[now + 1]))) {
                now++;
            }
            ll tmp = abs(det(p[i], p[j], p[now]));
            if (tmp > ans) ans = tmp, A = p[i], B = p[j], C = p[now];
        }
    }
}
int main() {
    oct::sync();
    int N;
    ll S;
    std::cin >> N >> S;
    for (int i = 1; i <= N; i++) std::cin >> a[i].x >> a[i].y;
    int top;
    convexhull(N, top);
    RC(ch, top - 1);
    std::cout << A.x + B.x - C.x << ' ' << A.y + B.y - C.y << std::endl;
    std::cout << A.x + C.x - B.x << ' ' << A.y + C.y - B.y << std::endl;
    std::cout << B.x + C.x - A.x << ' ' << B.y + C.y - A.y << std::endl;
    return 0;
}