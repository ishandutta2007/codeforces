#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

vector<int> G[N];
int dp[N];

void dfs(int v, deque<int> &h, set<int> &have) {
    if (G[v].empty()) {
        h.push_front(0);
        have.insert(0);
        dp[v] = 1;
        return;
    }
    int to = G[v][0];
    dfs(to, h, have);
    if (G[v].size() == 1) {
        h.push_front(dp[to]);
        have.insert(dp[to]);
        int mex = dp[to];
        while (have.find(mex) != have.end()) ++mex;
        dp[v] = mex;
        return;
    }
    int x = dp[to];
    int mn = h.size();
    for (int i = 1; i < G[v].size(); ++i) {
        to = G[v][i];
        deque<int> d;
        set<int> have2;
        dfs(to, d, have2);
        x ^= dp[to];
        mn = min(mn, int(d.size()));
        for (int j = 0; j < mn; ++j) h[j] ^= d[j];
    }
    h.resize(mn);
    h.push_front(x);
    have = set<int>(h.begin(), h.end());
    int mex = 0;
    while (have.find(mex) != have.end()) mex++;
    dp[v] = mex;
}

void solve() {
    int n;
    cin >> n;
    fill(G, G + n, vector<int>());
    vector<int> t;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p, --p;
        if (p == -1) {
            t.push_back(i);
        } else {
            G[p].push_back(i);
        }
    }
    int ans = 0;
    for (int v : t) {
        deque<int> h;
        set<int> have;
        dfs(v, h, have);
        ans ^= dp[v];
    }
    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}