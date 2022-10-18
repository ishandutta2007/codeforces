#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }
    
    if (m == n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    int best = 0;
    int best_c = 999;
    vector<int> dp(1 << n, 0);
    for (int i = 1; i < (1 << n); i++) {
        int cnt = __builtin_popcount(i);
        if (cnt >= best_c) 
            continue;

        if (cnt == 1) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    dp[i] = adj[j] | (1 << j);
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    int without = i ^ (1 << j);
                    if ((dp[without] ^ without) & (1 << j)) {
                        dp[i] = dp[without] | i | adj[j];
                        break;
                    }
                }
            }
        }

        if (dp[i] == (1 << n) - 1) {
            best = i;
            best_c = cnt;
        }
    }
    
    cout << best_c << endl;
    for (int j = 0; j < n; j++) {
        if (best & (1 << j))
            cout << j + 1 << ' ';
    }
    cout << endl;
}