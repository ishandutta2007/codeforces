#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<vector<int>>>> dp;
int n, k;

int MAX = numeric_limits<int>::max() / 2;

vector<vector<pair<int, int>>> adj;

int compute(int left, int current, int lower_bound, int upper_bound) {
    if (left == 0) {
        return 0;
    }

    if (dp[left][current][lower_bound][upper_bound] >= 0) 
        return dp[left][current][lower_bound][upper_bound];

    int best = MAX;
    for (auto p : adj[current]) {
        if (p.first > lower_bound && p.first < upper_bound) {
            int val;
            if (p.first > current) {
                val = compute(left - 1, p.first, current, upper_bound);
                // val = compute(left - 1, p.first, lower_bound, current);
            } else {
                // val = compute(left - 1, p.first, current, upper_bound);
                val = compute(left - 1, p.first, lower_bound, current);
            }

            best = min(best, val + p.second);
        }
    }

    return dp[left][current][lower_bound][upper_bound] = best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    adj.resize(n+1);
    dp.assign(n + 2, vector<vector<vector<int>>>(n+2, vector<vector<int>>(n + 2, vector<int>(n + 2, -1))));
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    } 
    
    int best = MAX;
    for (int i = 1; i <= n; i++) {
        best = min(best, compute(k - 1, i, 0, n+1));
    }

    if (best == MAX) cout << -1 << endl;
    else
        cout << best << endl;
}