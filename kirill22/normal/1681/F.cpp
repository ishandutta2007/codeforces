#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 22;
vector<pair<int, int>> g[N];
int n, sz[N], id[N], res[N], res2[N];
vector<int> lst[N];
vector<pair<int, int>> qu[N];
map<int, int> dp[N];
long long ans = 0;

int get(int v, int c) {
    v = id[v];
    if (dp[v].find(c) == dp[v].end()) {
        return 0;
    }
    return dp[v][c];
}

void dfs(int v, int pr, int c) {
    sz[v] = 1;
    id[v] = v;
    lst[c].push_back(v);
    for (auto [x, d] : g[v]) {
        if (x != pr) {
            int root = 0;
            if ((int) lst[d].size() > 0) {
                root = lst[d].back();
            }
            qu[root].push_back({x, d});
            dfs(x, v, d);
            sz[v] += sz[x];
            if ((int) dp[id[x]].size() > (int) dp[id[v]].size()) {
                id[v] = id[x];
            }
        }
    }
    lst[c].pop_back();
    for (auto [x, d] : g[v]) {
        if (x != pr && id[x] != id[v]) {
            for (auto [d2, cnt] : dp[id[x]]) {
                dp[id[v]][d2] += cnt;
            }
        }
    }
    //if (v == 0) cout << get(0, 1) << " " << get(0, 2) << endl;
    for (auto [x, d] : qu[v]) {
        res2[x] = sz[v] - get(v, d);
    }
    res[v] = sz[v] - get(v, c);
    dp[id[v]][c] = sz[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    dfs(0, -1, 0);
    for (int i = 1; i < n; i++) {
        ans += res[i] * 1ll * res2[i];
        //cout << res[i] << " " << res2[i] << endl;
    }
    cout << ans;
}