#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, mx;
int val[MAXN], par[MAXN], dub[MAXN], pos[MAXN];
llint dp[MAXN];
vector <int> v[MAXN], r[MAXN];
vector <llint> prf[MAXN], suf[MAXN];

void dfs (int x, int rod) {
    par[x] = rod;
    dub[x] = 1 + dub[rod];
    mx = max(mx, dub[x]);
    r[dub[x]].push_back(x);
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
    }
}

bool cmp (int a, int b) {return val[a] < val[b];}

void precompute_layer (int d) {
    sort(r[d].begin(), r[d].end(), cmp);
    for (int i = 0; i < r[d].size(); i++) {
        pos[r[d][i]] = i;
    }
    for (int i = 0; i < r[d].size(); i++) {
        int x = r[d][i];
        llint tmp = dp[x] - val[x];
        if (prf[d].empty()) {
            prf[d].push_back(tmp);
        } else {
            prf[d].push_back(max(tmp, prf[d].back()));
        }
    }
    for (int i = (int) r[d].size() - 1; i >= 0; i--) {
        int x = r[d][i];
        llint tmp = dp[x] + val[x];
        if (suf[d].empty()) {
            suf[d].push_back(tmp);
        } else {
            suf[d].push_back(max(tmp, suf[d].back()));
        }
    }
    reverse(suf[d].begin(), suf[d].end());
}

void calc (int x) {
    int d = dub[x] + 1;
    llint res = 0;
    for (auto sus : v[x]) {
        if (sus == par[x]) continue;
        res = max(res, dp[sus] + abs(val[sus] - val[r[d][0]]));
        res = max(res, dp[sus] + abs(val[sus] - val[r[d].back()]));
        int ind = pos[sus];
        if (ind - 1 >= 0) res = max(res, prf[d][ind - 1] + val[sus]);
        if (ind + 1 < r[d].size()) res = max(res, suf[d][ind + 1] - val[sus]);
    }
    dp[x] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            v[i].clear(); r[i].clear();
            prf[i].clear(); suf[i].clear();
            dp[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            int sus; cin >> sus;
            v[i].push_back(sus);
            v[sus].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            cin >> val[i];
        }
        dfs(1, 0);
        for (int d = mx; d >= 2; d--) {
            for (auto x : r[d]) calc(x);
            precompute_layer(d);
        }
        calc(1);
        cout << dp[1] << '\n';
    }
    return 0;
}