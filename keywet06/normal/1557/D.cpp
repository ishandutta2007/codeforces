#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp std::make_pair

using int64 = long long;
using pair = std::pair<int, int>;

const int N = 300005;
const int M = N << 3;

int n, m, c, x, y, z;
int a[N], ti[N], le[N], ri[N], use[N];
int so[M];

pair res, rans;
pair ans[N];
pair data[M], tag[M];

std::stack<int> st;

std::map<int, int> map;

std::vector<pair> rs[N];

inline void update(int u, int l, int r, int x, int y, pair d) {
    if (l >= x && r <= y) {
        tag[u] = std::max(tag[u], d);
        data[u] = std::max(data[u], d);
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) update(u << 1, l, mid, x, y, d);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, d);
    data[u] = std::max(data[u << 1], data[u << 1 | 1]);
}

inline pair query(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return data[u];
    int mid = l + r >> 1;
    pair ret = tag[u];
    if (x <= mid) ret = std::max(ret, query(u << 1, l, mid, x, y));
    if (y > mid) ret = std::max(ret, query(u << 1 | 1, mid + 1, r, x, y));
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> ti[i] >> le[i] >> ri[i];
        so[i * 2 - 1] = le[i], so[i * 2] = ri[i];
    }
    std::sort(so + 1, so + m + m + 1);
    for (int i = 1; i <= 2 * m; ++i) {
        if (so[i] != so[i - 1]) map[so[i]] = ++c;
    }
    for (int i = 1; i <= m; ++i) {
        rs[ti[i]].push_back(mkp(map[le[i]], map[ri[i]]));
    }
    for (int i = 1; i <= n; ++i) {
        res = mkp(0, 0);
        for (pair r : rs[i]) res = std::max(res, query(1, 1, c, r.fi, r.se));
        ++res.fi, ans[i] = res, res.se = i;
        for (pair r : rs[i]) update(1, 1, c, r.fi, r.se, res);
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] > rans) x = i, rans = ans[i];
    }
    std::cout << n - rans.fi << '\n';
    for (int u = x; u; u = ans[u].se) use[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!use[i]) std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}