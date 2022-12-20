#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll n, m;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pair<ll, pair<int, int>> edges[m];
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = mp(w, mp(u, v));
    }
    sort(edges, edges+m);

    ll dp[n+1];
    ll lastmod[n+1];
    ll prev[n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        lastmod[i] = 1e9;
        prev[i] = 0;
    }
    ll out = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        ll w = edges[i].first;
        if (lastmod[u] != w) {
            if (dp[v] < dp[u]+1) {
                if (lastmod[v] != w) prev[v] = dp[v];
                dp[v] = dp[u]+1;
                out = max(out, dp[v]);
                lastmod[v] = w;
            }
        } else {
            if (dp[v] < prev[u]+1) {
                if (lastmod[v] != w) prev[v] = dp[v];
                dp[v] = prev[u]+1;
                out = max(out, dp[v]);
                lastmod[v] = w;
            }
        }
    }
    cout << out << endl;


}