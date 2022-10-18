#include <bits/stdc++.h>
using namespace std;

bitset<501> dp[61][2][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        dp[0][t][u][v] = 1;
    }

    for (int i = 1; i <= 60; i++) {
        for (int x = 0; x < 2; x++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (dp[i-1][x][u][v])
                        dp[i][x][u] |= dp[i-1][!x][v];
                }
            }
        }
    }
    
    bitset<501> reachable;
    reachable.set();
    long long result = 0;
    int bit = 0;
    for (int i = 60; i >= 0; i--) {
        bitset<501> new_reachable;
        for (int u = 0; u < n; u++) {
            if (!reachable[u]) continue;
            new_reachable |= dp[i][bit][u];
        }

        if (new_reachable.any()) {
            reachable = new_reachable;
            result += 1LL << i;
            bit = 1 - bit;
        }
    }

    cout << (result > 1e18 ? -1 : result) << endl;
}