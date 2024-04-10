#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, W, B, X;
    cin >> n >> W >> B >> X;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<long long> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    int birds = accumulate(c.begin(), c.end(), 0LL);

    long long MAX = 1e14;
    vector<long long> max_capacity(birds + 1, W);
    for (int i = 1; i <= birds; i++) {
        max_capacity[i] = min(max_capacity[i - 1] + B, MAX);
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(birds + 1, -MAX));
    dp[0][0] = W;
    int bs = 0;
    for (int pos = 1; pos <= n; pos++) {
        bs += c[pos - 1];
        deque<pair<long long, int>> q;
        long long offset = 0;
        for (int b = 0; b <= bs; b++) {
            // handle queue
            if (!q.empty() && q.front().second == b - c[pos - 1] - 1)
                q.pop_front();
            long long neww = dp[pos - 1][b];
            if (neww >= 0) {
                neww += offset;
                while (!q.empty() && q.back().first <= neww)
                    q.pop_back();
                q.push_back({neww, b});
            }

            if (!q.empty()) {
                dp[pos][b] = q.front().first - offset;
            }
            offset += cost[pos - 1];
        }
            
        for (int b = 0; b <= bs; b++) {
            if (dp[pos][b] < 0)
                dp[pos][b] = -MAX;
            else
                dp[pos][b] = min(dp[pos][b] + X, max_capacity[b]);
        }
    }

    for (int i = birds; i >= 0; i--) {
        if (dp[n][i] >= 0) {
            cout << i << endl;
            break;
        }
    }
}