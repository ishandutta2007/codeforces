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

const int K = 1005;
const int N = 30005;
const int M = 120005;
const int64 pws = 10000019;
const int64 mod = 1000000007;

int n, k, q, cnt, tim, opt, x, c;
int val[N], wi[N], st[N], fi[N];
int tr[K][K];
int dp[N][K];
int64 ans, mul;
std::vector<int> qry;
std::vector<int> num[M];

inline void update(int u, int l, int r, int x, int y, int d) {
    if (x <= l && r <= y) {
        num[u].pub(d);
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) update(u << 1, l, mid, x, y, d);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, d);
}
inline void change(int *u, int *v, std::vector<int> &vec) {
    for (int i = 0; i <= k; ++i) u[i] = v[i];
    for (int d : vec) {
        for (int i = k; i >= wi[d]; --i) oct::mad(u[i], u[i - wi[d]] + val[d]);
    }
}
inline void finish(int u, int l, int r) {
    if (l == r) {
        change(dp[l], tr[c], num[u]);
        return;
    }
    int mid = l + r >> 1;
    ++c;
    change(tr[c], tr[c - 1], num[u]);
    finish(u << 1, l, mid);
    finish(u << 1 | 1, mid + 1, r);
    --c;
}

int main() {
    oct::sync();
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> val[i] >> wi[i];
        st[i] = 1, fi[i] = N;
    }
    cnt = n;
    std::cin >> q;
    for (int i = 1; i <= q; ++i) {
        std::cin >> opt;
        if (opt == 1) {
            ++cnt;
            std::cin >> val[cnt] >> wi[cnt];
            st[cnt] = i, fi[cnt] = q;
        } else if (opt == 2) {
            std::cin >> x, fi[x] = i;
        } else {
            qry.pub(i);
        }
    }
    for (int i = 1; i <= cnt; ++i) oct::mid(fi[i], q);
    for (int i = 1; i <= cnt; ++i) update(1, 1, q, st[i], fi[i], i);
    finish(1, 1, q);
    for (int s : qry) {
        ans = 0, mul = 1;
        for (int i = 1; i <= k; ++i) {
            ans += dp[s][i] * mul % mod;
            mul = mul * pws % mod;
        }
        std::cout << ans % mod << std::endl;
    }
    return 0;
}