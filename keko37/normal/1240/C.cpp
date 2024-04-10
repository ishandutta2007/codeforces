#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 500005;

int q, n, k;
vector < pair <int, llint> > v[MAXN];
llint dp[2][MAXN], par[MAXN];

void dfs (int x, int rod) {
    par[x] = rod;
    for (auto pp : v[x]) {
        if (pp.first != rod) dfs(pp.first, x);
    }
}

llint calc (int tip, int x) {
    if (dp[tip][x] != -1) return dp[tip][x];
    vector < pair <llint, int> > ch;
    for (auto pp : v[x]) {
        llint sus = pp.first, w = pp.second;
        if (sus == par[x]) continue;
        ch.push_back({w + calc(1, sus) - calc(0, sus), sus});
    }
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
    llint res = 0;
    int lim = k - tip;
    for (int i=0; i<ch.size(); i++) {
        llint val = ch[i].first, sus = ch[i].second;
        if (i < lim) res += max(calc(0, sus), calc(0, sus) + val); else res += calc(0, sus);
    }
    return dp[tip][x] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            v[i].clear();
            dp[0][i] = dp[1][i] = -1;
        }
        for (int i=0; i<n-1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            v[a].push_back({b, w});
            v[b].push_back({a, w});
        }
        dfs(1, 0);
        cout << calc(0, 1) << '\n';
    }
    return 0;
}