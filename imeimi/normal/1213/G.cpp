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
struct _es {
    int x, y, w;
    void scan() {
        cin >> x >> y >> w;
    }
    bool operator<(const _es &p) const {
        return w < p.w;
    }
} es[200000];

int par[200001];
int sz[200001];

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        es[i].scan();
    }
    sort(es + 1, es + n);
    llong sum = 0;
    for (int i = 1; i <= n; ++i) {
        sz[i] = 1;
    }
    vector<pll> ans;
    ans.emplace_back(0, 0);
    for (int i = 1; i < n; ++i) {
        int x = find(es[i].x);
        int y = find(es[i].y);
        sum += (llong)sz[x] * sz[y];
        par[y] = x;
        sz[x] += sz[y];
        if (ans.back().fs == es[i].w) ans.back().se = sum;
        else ans.emplace_back(es[i].w, sum);
    }
    while (m--) {
        int q;
        cin >> q;
        printf("%lld ", (lower_bound(ans.begin(), ans.end(), pll(q + 1, 0)) - 1)->se);
    }
    return 0;
}