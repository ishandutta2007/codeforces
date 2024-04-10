#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

vector<int> g[200000];
vector<int> gr[200000];

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    int k;
    cin >> k;

    vector<int> path;

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        a--;
        path.push_back(a);
    }

    int t = path.back();

    vector<int> dp(n, 10000000);

    dp[t] = 0;
    set<pair<int, int>> s;
    s.insert(make_pair(0, t));


    while (s.size() != 0) {
        auto p = *(s.begin());
        s.erase(s.begin());

        int v = p.second;
        int val = p.first;
        for (int i = 0; i < gr[v].size(); i++) {
            int u = gr[v][i];
            if (dp[v] + 1 < dp[u]) {
                if (dp[u] == 10000000) {
                    dp[u] = dp[v] + 1;
                    s.insert(make_pair(dp[u], u));
                } else {
                    s.erase(s.find(make_pair(dp[u], u)));
                    dp[u] = dp[v] + 1;
                    s.insert(make_pair(dp[u], u));
                }
            }
        }
    }
    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        for (auto u : g[i]) {
            if (dp[u] + 1 == dp[i]) {
                cnt[i]++;
            }
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < k - 1; i++) {
        int v = path[i];
        int u = path[i + 1];

        if (dp[u] + 1 == dp[v]) {
            if (cnt[v] > 1) {
                ans2++;
            }
        } else {
            ans1++;
            ans2++;
        }
    }

    cout << ans1 << " " << ans2;
    return 0;
}