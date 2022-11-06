#include <bits/stdc++.h>

using namespace std;

#define int long long

int N;
vector< vector<int> > graph;
vector<int> a;

vector< vector<int> > dp;

void fill_dp(int v) {
    for (auto u: graph[v]) {
        fill_dp(u);
    }
    int sum = 0;
    int modtwo = 0;
    for (auto u: graph[v]) {
        if (dp[u][1] > dp[u][0]) {
            sum += dp[u][1];
            modtwo ^= 1;
        } else {
            sum += dp[u][0];
        }
    }
    int dec = sum;
    for (auto u: graph[v]) {
        dec = min(dec, abs(dp[u][1] - dp[u][0]));
    }
    dp[v][modtwo] = sum;
    dp[v][modtwo ^ 1] = sum - dec;
    dp[v][1] = max(dp[v][1], dp[v][0] + a[v]);
}

main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    graph.assign(N, vector<int>());
    a.assign(N, 0);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p >> a[i];
        if (p != -1) {
            p--;
            graph[p].push_back(i);
        }
    }

    dp.assign(N, vector<int>(2, 0));

    fill_dp(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
}