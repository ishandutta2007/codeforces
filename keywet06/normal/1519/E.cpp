#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp std::make_pair
#define pus push
#define pop pop
#define pub push_back
#define pob pop_back

using int32 = int;
using int64 = long long;
using i5 = int32;
using i6 = int64;
using pi5 = std::pair<i5, i5>;
using pi6 = std::pair<i6, i6>;

const int N = 400005;

int mapcnt, n;
int vis[N], deep[N];

int64 pa, pb, pc, pd, x, y;

std::map<pi6, int> map;

std::vector<pi5> ans;
std::vector<pi5> to[N];

int getid(int64 x, int64 y) {
    int64 c = std::__gcd(x, y);
    pi6 p = mkp(x / c, y / c);
    return map[p] ? map[p] : (map[p] = ++mapcnt);
}

inline int dfs(int u, int f) {
    int x;
    pi5 fa = mkp(0, 0);
    std::vector<int> vec;

    vis[u] = 1, deep[u] = deep[f] + 1;
    for (pi5 e : to[u]) {
        if (e.fi == f && !fa.fi) {
            fa = e;
        } else if (vis[e.fi]) {
            if (deep[e.fi] > deep[u]) vec.pub(e.se);
        } else {
            if (x = dfs(e.fi, u)) vec.pub(x);
        }
    }
    for (int i = 0; i + 1 < vec.size(); ++++i) ans.pub(mkp(vec[i], vec[i + 1]));
    if (vec.size() & 1) {
        if (f) ans.pub(mkp(fa.se, vec.back()));
        return 0;
    } else {
        return fa.se;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> pa >> pb >> pc >> pd;
        x = getid(pa * pd + pb * pd, pb * pc);
        y = getid(pa * pd, pb * pc + pb * pd);
        to[x].push_back(mkp(y, i));
        to[y].push_back(mkp(x, i));
    }
    for (int i = 1; i <= mapcnt; ++i) {
        if (!vis[i]) dfs(i, 0);
    }
    std::cout << ans.size() << '\n';
    for (pi5 p : ans) std::cout << p.fi << ' ' << p.se << '\n';
    return 0;
}