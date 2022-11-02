// oct insert "pre-document"

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

// oct end "pre-document"

const int N = 1000010;

struct node {
    int x, y;
    bool operator<(node o);
};

int get(int x, int y);
int find(int x);
void unite(int x, int y);
int dfs(int u);

int n, m, tot, a[N], f[N], par[N];
node dat[N];
std::vector<int> g[N];

inline bool node::operator<(node o) { return a[get(x, y)] < a[get(o.x, o.y)]; }
inline int get(int x, int y) { return (x - 1) * m + y; }
inline int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
inline void unite(int x, int y) { par[find(x)] = find(y); }
inline int dfs(int u) {
    if (~f[u]) return f[u];
    f[u] = 0;
    for (int v : g[u]) oct::mad(f[u], dfs(v));
    return ++f[u];
}

int main() {
    oct::sync();
    std::cin >> n >> m, tot = n * m;
    for (int i = 1; i <= tot; ++i) std::cin >> a[i], par[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)  dat[j] = node{i, j};
        std::sort(dat + 1, dat + m + 1);
        for (int j = 1; j < m; ++j) {
            int u = get(dat[j].x, dat[j].y);
            int v = get(dat[j + 1].x, dat[j + 1].y);
            if (a[u] == a[v]) unite(u, v);
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) 
            dat[i] = node{i, j};
        
        std::sort(dat + 1, dat + n + 1);
        for (int i = 1; i < n; ++i) {
            int u = get(dat[i].x, dat[i].y);
            int v = get(dat[i + 1].x, dat[i + 1].y);
            if (a[u] == a[v]) unite(u, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) 
            dat[j] = node{i, j};
        
        std::sort(dat + 1, dat + m + 1);
        for (int j = 1; j < m; ++j) {
            int u = get(dat[j].x, dat[j].y);
            int v = get(dat[j + 1].x, dat[j + 1].y);
            if ((u = find(u)) != (v = find(v))) g[v].push_back(u);
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) 
            dat[i] = node{i, j};
        
        std::sort(dat + 1, dat + n + 1);
        for (int i = 1; i < n; ++i) {
            int u = get(dat[i].x, dat[i].y);
            int v = get(dat[i + 1].x, dat[i + 1].y);
            if ((u = find(u)) != (v = find(v))) g[v].push_back(u);
        }
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= tot; ++i) {
        if (find(i) == i) dfs(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cout << f[find(get(i, j))] << ' ';
        std::cout << '\n';
    }
    return 0;
}