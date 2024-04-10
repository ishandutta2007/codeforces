#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    vector<long long> results;
    for (int i = 0; i < n; i++) {
        int elem = v[n-1-i] - 1;
        for (int j = 0; j <= i; j++) {
            int a = v[n-1-j] - 1;
            dp[elem][a] = adj[elem][a];
            dp[a][elem] = adj[a][elem];
        }

        for (int j = 0; j <= i; j++) {
            int a = v[n-1-j] - 1;
            for (int k = 0; k <= i; k++) {
                int b = v[n-1-k] - 1;
                dp[a][elem] = min(dp[a][elem], dp[a][b] + dp[b][elem]);
                dp[elem][b] = min(dp[elem][b], dp[elem][a] + dp[a][b]);
            }
        }

        for (int j = 0; j <= i; j++) {
            int a = v[n-1-j] - 1;
            for (int k = 0; k <= i; k++) {
                int b = v[n-1-k] - 1;
                dp[a][b] = min(dp[a][b], dp[a][elem] + dp[elem][b]);
                dp[b][a] = min(dp[b][a], dp[b][elem] + dp[elem][a]);
            }
        }

        long long sum = 0;
        for (auto t : dp) for (auto d : t) sum += d;
        results.push_back(sum);
    }

    for (int i = 0; i < n; i++) {
        cout << results[n-1-i] << " ";
    }

    return 0;
}