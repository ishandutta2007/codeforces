#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m;
int W[200001];
vector<int> edge[200001];

int uf[200001];
int sz[200001];
int find(int x) {
    if (uf[x]) return uf[x] = find(uf[x]);
    return x;
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    uf[y] = x;
    sz[x] += sz[y];
    return 1;
}

int par[200001];
int dep[200001];
int back[200001];
llong sum[200001];
void dfs(int x, int p) {
    par[x] = p;
    back[x] = dep[x] = dep[p] + 1;
    sum[x] = sum[p] + W[x];
    for (int i : edge[x]) {
        if (i == p) continue;
        if (dep[i]) {
            back[x] = min(back[x], dep[i]);
            continue;
        }
        dfs(i, x);
        back[x] = min(back[x], back[i]);
    }
    if (back[x] < dep[x]) merge(x, p);
}

bool up[200001], dn[200001];
bool ch[200001];

void dfs2(int x, int p) {
    if (p == 0 || sz[find(x)] > 1) up[x] = dn[x] = 1;
    up[x] |= up[p];
    for (int i : edge[x]) {
        if (par[i] != x) continue;
        dfs2(i, x);
        dn[x] |= dn[i];
    }
    ch[x] = up[x] && dn[x];
}

llong dfs3(int x, int p) {
    llong ret = 0;
    for (int i : edge[x]) {
        if (par[i] != x) continue;
        ret = max(ret, dfs3(i, x));
    }
    if (ch[x]) return ret;
    return ret + W[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> W[i], sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int s;
    cin >> s;
    dfs(s, 0);
    llong ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, sum[i]);
    dfs2(s, 0);
    llong bsum = 0;
    int bcnt = 0;
    for (int i = 1; i <= n; ++i) if (ch[i]) bsum += W[i], ++bcnt;
    if (bcnt > 0) ans = max(ans, bsum + dfs3(s, 0));
    debug("%lld\n", bsum);
    printf("%lld\n", ans);
    return 0;
}