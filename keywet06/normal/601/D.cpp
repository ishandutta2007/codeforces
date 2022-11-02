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

const int C = 26;
const int N = 300005;
const int M = 600005;
const int P = 1200005;

char ch[N];
int n, cnt, u, v, ans, num;
int c[N], head[N];
int next[M], to[M];
int si[P];
int s[P][C];

inline void insert(int u, int v) {
    next[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
inline void addedge(int u, int v) {
    insert(u, v);
    insert(v, u);
}
inline int merge(int u, int v) {
    if (!u || !v) return u + v;
    if (si[u] < si[v]) std::swap(u, v);
    si[u] = 1;
    for (int i = 0; i < C; ++i) si[u] += si[s[u][i] = merge(s[u][i], s[v][i])];
    return u;
}
inline void dfs(int u, int f) {
    si[u] = 1;
    for (int e = head[u]; e; e = next[e]) {
        if (to[e] == f) continue;
        dfs(to[e], u);
        si[u] -= si[s[u][ch[to[e]]]];
        si[u] += si[s[u][ch[to[e]]] = merge(s[u][ch[to[e]]], to[e])];
    }
    if (si[u] + c[u] > ans) {
        ans = si[u] + c[u];
        num = 1;
    } else if (si[u] + c[u] == ans) {
        ++num;
    }
}

int main() {
    oct::sync();
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> c[i];
    std::cin >> ch + 1;
    for (int i = 1; i <= n; ++i) ch[i] -= 'a';
    std::cout << std::endl;
    for (int i = 1; i < n; ++i) std::cin >> u >> v, addedge(u, v);
    dfs(1, 1);
    std::cout << ans << std::endl;
    std::cout << num << std::endl;
    return 0;
}