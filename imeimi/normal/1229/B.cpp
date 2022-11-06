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

const int mod = 1e9 + 7;

llong gcd(llong x, llong y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int n;
vector<pll> G[100001];
llong X[100001];
vector<int> edge[100001];

llong ans = 0;
void dfs(int x, int p) {
    G[x] = G[p];
    for (pll &i : G[x]) i.fs = gcd(i.fs, X[x]);
    if (!G[x].empty() && G[x].back().fs == X[x]) ++G[x].back().se;
    else G[x].emplace_back(X[x], 1);
    vector<pll> nxt;
    for (pll i : G[x]) {
        if (!nxt.empty() && nxt.back().fs == i.fs) nxt.back().se += i.se;
        else nxt.push_back(i);
    }
    G[x] = nxt;
    for (pll i : G[x]) {
        ans += i.fs % mod * i.se % mod;
        ans %= mod;
    }
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> X[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}