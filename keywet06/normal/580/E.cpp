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
 
const int C = 10;
const int N = 400005;
const int64 mod = 998244353;
 
void pushdown(int u, int l, int r);
void build(int u, int l, int r);
void update(int u, int l, int r, int x, int y, int z);
int64 query(int u, int l, int r, int x, int y);
 
char s[N];
int n, m, k, o, l, r;
int lazy[N], data[N];
int64 sub[N], pre[N];
int64 con[C][N];
 
inline void pushdown(int u, int l, int r) {
    if (!lazy[u]) return;
    int mid = l + r >> 1;
    sub[u << 1] = con[data[u]][mid - l + 1];
    sub[u << 1 | 1] = con[data[u]][r - mid];
    lazy[u << 1] = lazy[u << 1 | 1] = 1;
    data[u << 1] = data[u << 1 | 1] = data[u];
    data[u] = lazy[u] = 0;
}
inline void build(int u, int l, int r) {
    if (l == r) {
        sub[u] = s[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    sub[u] = (pre[r - mid] * sub[u << 1] + sub[u << 1 | 1]) % mod;
}
inline void update(int u, int l, int r, int x, int y, int z) {
    if (x <= l && r <= y) {
        sub[u] = con[z][r - l + 1], lazy[u] = 1, data[u] = z;
        return;
    }
    int mid = l + r >> 1;
    pushdown(u, l, r);
    if (x <= mid) update(u << 1, l, mid, x, y, z);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, z);
    sub[u] = (pre[r - mid] * sub[u << 1] + sub[u << 1 | 1]) % mod;
}
inline int64 query(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return sub[u];
    int mid = l + r >> 1;
    int64 ans = 0;
    pushdown(u, l, r);
    if (x <= mid) ans = query(u << 1, l, mid, x, y);
    if (y > mid) {
        ans = (ans * pre[std::min(y, r) - mid] +
               query(u << 1 | 1, mid + 1, r, x, y)) %
              mod;
    }
    return ans;
}
 
int main() {
    oct::sync();
    std::cin >> n >> m >> k;
    std::cin >> s + 1;
    m += k;
    for (int i = 1; i <= n; ++i) s[i] -= '0';
    for (int c = 0; c < C; ++c) {
        for (int i = 1; i <= n; ++i) con[c][i] = (con[c][i - 1] * C + c) % mod;
    }
    pre[0] = 1;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * C % mod;
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        std::cin >> o >> l >> r >> k;
        if (o == 1) {
            update(1, 1, n, l, r, k);
        } else {
            std::cout << (k == r - l + 1 || query(1, 1, n, l, r - k) ==
                                                query(1, 1, n, l + k, r)
                              ? "YES"
                              : "NO")
                      << '\n';
        }
    }
    return 0;
}