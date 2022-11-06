#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

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

int n, k;
vector<pii> edge[500001];

llong dp1[500001]; //<= k
llong dp2[500001]; //< k

void dfs(int x, int p) {
    llong sum = 0;
    vector<llong> ch;
    for (pii i : edge[x]) {
        if (i.fs == p) continue;
        dfs(i.fs, x);
        sum += dp1[i.fs];
        ch.push_back(dp2[i.fs] + i.se - dp1[i.fs]);
    }
    sort(ch.rbegin(), ch.rend());
    dp1[x] = dp2[x] = sum;
    for (int i = 0; i < (int)ch.size(); ++i) {
        sum += ch[i];
        if (i + 1 <= k) dp1[x] = max(dp1[x], sum);
        if (i + 1 < k) dp2[x] = max(dp2[x], sum);
    }
}

llong solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edge[x].emplace_back(y, w);
        edge[y].emplace_back(x, w);
    }
    dfs(1, 0);
    return dp1[1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}