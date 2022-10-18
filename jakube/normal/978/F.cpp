#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto x = r;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        int R = r[i];
        int possible = lower_bound(x.begin(), x.end(), R) - x.begin();
        for (int u : adj[i]) {
            possible -= r[u] < R;
        }
        cout << possible << ' ';
    }
    cout << '\n';
}