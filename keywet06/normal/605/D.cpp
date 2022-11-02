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
using vi32 = std::vector<int32>;
using qi32 = std::queue<int32>;
using spi32 = std::set<pi32>;

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

const int N = 200005;
const int INF = 2000000000;
const int mod = 1000000007;
const double eps = 1e-9;

int lb(int x);
void add(int x, int v, int id);
vi32 query(int p);
void init();
void print(int i);
void bfs();

int n, num;
int a[N], b[N], c[N], d[N], vis[N], dis[N], pre[N], da[N];
spi32 st[N];

inline int lb(int x) { return x & (-x); }
inline void add(int x, int v, int id) {
    for (; x <= num; x += lb(x)) st[x].insert(std::mkp(v, id));
}
inline vi32 query(int p) {
    int x = a[p], y = b[p];
    vi32 res;
    for (; x; x -= lb(x)) {
        spi32 &now = st[x];
        while (1) {
            spi32::ite it = now.lower_bound(std::mkp(y, 0));
            if (it == now.end()) break;
            res.pub(it->sec);
            now.erase(it);
        }
    }
    return res;
}
inline void init() {
    std::sort(da + 1, da + num + 1);
    num = std::unique(da + 1, da + num + 1) - da - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = num - (std::lob(da + 1, da + num + 1, a[i]) - da) + 1;
        c[i] = num - (std::lob(da + 1, da + num + 1, c[i]) - da) + 1;
        if (i != n) add(c[i], d[i], i);
    }
}
inline void print(int t) {
    std::cout << dis[t] << std::endl;
    for (int u = t; ~u; u = pre[u]) std::cout << u << ' ';
    std::cout << std::endl;
}
inline void bfs() {
    qi32 q;
    q.push(n);
    pre[n] = -1;
    dis[n] = 1;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (a[p] == num && !b[p]) {
            print(p);
            return;
        }
        vi32 next = query(p);
        for (int i = 0, t; i < next.size(); i++) {
            if (vis[next[i]]) continue;
            vis[next[i]] = 1;
            q.push(t = next[i]);
            dis[t] = dis[p] + 1, pre[t] = p;
        }
    }
    std::cout << -1 << std::endl;
}

int main() {
    oct::sync();
    std::cin >> n;
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
        da[++num] = a[i];
        da[++num] = c[i];
        flag |= (!a[i] && !b[i]);
    }
    if (!flag) {
        std::cout << -1 << std::endl;
        return 0;
    }
    init();
    bfs();
    return 0;
}