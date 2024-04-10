#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[300000];
int dp[300000][2];
int n, a, b, da, db;

void dfs(int s, int fa) {
    dp[s][0] = dp[s][1] = 0;
    for (auto v : g[s]) {
        if (v == fa) continue;
        dfs(v, s);
        if (dp[v][0] + 1 > dp[s][0]) {
            dp[s][1] = dp[s][0];
            dp[s][0] = dp[v][0] + 1;
        } else if (dp[v][0] + 1 > dp[s][1]) {
            dp[s][1] = dp[v][0] + 1;
        }
    }
}

int dfs3(int s, int fa) {
    if (s == b) return 0;
    int dist = 0x3f3f3f3f;
    for (auto x : g[s]) {
        if (x == fa) continue;
        dist = min(dist, dfs3(x, s) + 1);
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }
        for (int i = 1; i < n; i++) {
            int aa, bb;
            cin >> aa >> bb;
            g[aa].push_back(bb);
            g[bb].push_back(aa);
        }
        dfs(1, -1);
        int d = 0;
        for (int i = 1; i <= n; i++) {
            d = max(d, dp[i][0] + dp[i][1]);
        }
        int dist = dfs3(a, -1);
        bool f = 1;
        if (2 * da + 1 > min(d, db)) f = 0;
        if (dist <= da) f = 0;
        if (f)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
}