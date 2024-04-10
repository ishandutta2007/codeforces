#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 1;
const int MAXX = 1e7 + 1;
int n, q;
int a[MAXN];

struct query {
    int u, v, x, i;
    void scan(int idx) {
        i = idx;
        cin >> u >> v >> x;
    }
} querys[MAXN];
int ans[MAXN];
int dep[MAXN];
int par[MAXN][17];
int st[MAXN];
int ed[MAXN];
vector<int> ps[MAXX];
vector<int> qs[MAXX];
vector<int> edge[MAXN];
int seg[MAXN];
int idx = 0;

void update(int i, int x) {
    while (i <= n) {
        seg[i] += x;
        i += i & -i;
    }
}

int query(int i) {
    int ret = 0;
    while (i) {
        ret += seg[i];
        i -= i & -i;
    }
    return ret;
}

void dfs(int x, int p) {
    dep[x] = dep[p] + 1;
    par[x][0] = p;
    for (int i = 1; i < 17; ++i) {
        par[x][i] = par[par[x][i - 1]][i - 1];
    }
    
    st[x] = ++idx;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
    ed[x] = idx;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 17; i--; ) {
        if ((dep[x] - dep[y]) >> i) {
            x = par[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 17; i--; ) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int pow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    int ret = pow(x, p >> 1);
    ret = (llong)ret * ret % mod;
    if (p & 1) return (llong)ret * x % mod;
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 2; (llong)j * j <= a[i]; ++j) {
            if (a[i] % j > 0) continue;
            int p = 1;
            do {
                a[i] /= j;
                p *= j;
                ps[p].push_back(i);
            } while (a[i] % j == 0);
        }
        if (a[i] > 1) ps[a[i]].push_back(i);
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
        querys[i].scan(i);
        int x = querys[i].x;
        ans[i] = 1;
        for (int j = 2; (llong)j * j <= x; ++j) {
            if (x % j > 0) continue;
            int p = 1;
            do {
                x /= j;
                p *= j;
            } while (x % j == 0);
            qs[p].push_back(i);
        }
        if (x > 1) qs[x].push_back(i);
	}
	dfs(1, 0);
	for (int i = 2; i < MAXX; ++i) {
        if (ps[i].empty()) continue;
        for (llong j = i; j < MAXX; j *= i) {
            for (int it : ps[j]) {
                update(st[it], 1);
                update(ed[it] + 1, -1);
            }
            for (int it : qs[j]) {
                int ret = 0, x, y;
                x = querys[it].u;
                y = querys[it].v;
                ret += query(st[x]);
                ret += query(st[y]);
                ret -= query(st[lca(x, y)]);
                ret -= query(st[par[lca(x, y)][0]]);
                ans[it] = (llong)ans[it] * pow(i, ret) % mod;
            }
            
        }
        for (llong j = i; j < MAXX; j *= i) {
            for (int it : ps[j]) {
                update(st[it], -1);
                update(ed[it] + 1, 1);
            }
            ps[j].clear();
            qs[j].clear();
        }
	}
	for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
	}
	return 0;
}