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

namespace ISAP {

const int N = 20005;
const int M = 200005;
const int64 INF = 1000000016000000063;

int S, T, n, m, x, y, z, cnt = 1, sum;
int head[N], dis[N], vis[N], gap[N], cur[N];
int next[M], to[M];
int64 flow[M];

inline void insert(int x, int y, int z) {
    next[++cnt] = head[x];
    head[x] = cnt;
    to[cnt] = y;
    flow[cnt] = z;
}
inline void addedge(int x, int y, int z) {
    insert(x, y, z);
    insert(y, x, 0);
}
inline int SPFA() {
    memset(dis, 127, sizeof(dis));
    std::queue<int> queue;
    queue.push(T);
    dis[T] = 0;
    vis[T] = 1;
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        vis[u] = 0;
        for (int e = head[u]; e; e = next[e]) {
            if (flow[e ^ 1] && dis[u] + 1 < dis[to[e]]) {
                ++gap[dis[to[e]] = dis[u] + 1];
                if (!vis[to[e]]) {
                    queue.push(to[e]);
                    vis[to[e]] = 1;
                }
            }
        }
    }
    return dis[S] != dis[0];
}
inline int64 dfs(int u, int64 limit) {
    if (u == T) return limit;
    int64 rlow = 0, used = 0;
    for (int &e = cur[u]; e; e = next[e]) {
        if (!flow[e] || dis[to[e]] != dis[u] - 1) continue;
        if (!(rlow = dfs(to[e], std::min(limit - used, flow[e])))) continue;
        used += rlow;
        flow[e] -= rlow;
        flow[e ^ 1] += rlow;
        if (used == limit) return used;
    }
    if (!--gap[dis[u]]) dis[S] = n + 1;
    ++gap[++dis[u]];
    return used;
}
inline int64 ISAP() {
    int64 ans = 0;
    SPFA();
    while (dis[S] < n) {
        memcpy(cur, head, sizeof(head));
        ans += dfs(S, INF);
    }
    return ans;
}

} // namespace ISAP

const int C = 5;
const int N = 20005;

struct node {
    int u, t;
};

bool operator<(node x, node y);
void failure();

int n, b, q;
int count[C];
node so[N];

inline bool operator<(node x, node y) { return x.u < y.u; }
inline void failure() {
    std::cout << "unfair" << std::endl;
    exit(0);
}

int main() {
    oct::sync();
    std::cin >> n >> b >> q;
    ISAP::S = 1, ISAP::T = 2;
    for (int i = 1; i <= q; ++i) std::cin >> so[i].u >> so[i].t;
    std::sort(so + 1, so + q + 1);
    for (int i = 0; i < C; ++i) ISAP::addedge(i + 3, ISAP::T, n / 5);
    so[++q].u = b, so[q].t = n;
    for (int i = 1; i <= q; ++i) {
        if (so[i].t < so[i - 1].t) failure();
        ISAP::addedge(ISAP::S, i + 7, so[i].t - so[i - 1].t);
        memset(count, 0, sizeof(count));
        for (int j = so[i - 1].u + 1; j <= so[i].u; ++j) ++count[j % C];
        for (int j = 0; j < C; ++j) ISAP::addedge(i + 7, j + 3, count[j]);
    }
    ISAP::n = q + 7;
    std::cout << (n == ISAP::ISAP() ? "fair" : "unfair") << std::endl;
    return 0;
}