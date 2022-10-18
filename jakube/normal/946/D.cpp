#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> lessons;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1')
                lessons.push_back(j);
        }
        int sz = lessons.size();
        if (!sz) {
            dp[i+1] = dp[i];
            continue;
        }
        vector<int> dp2(sz + 1, lessons.back() - lessons.front() + 1);
        for (int j = 0; j < sz; j++) {
            for (int k = j; k < sz; k++) {
                dp2[sz-(k-j+1)] = min(dp2[sz-(k-j+1)], lessons[k] - lessons[j] + 1);
            }
        }
        dp2[sz] = 0;

        for (int j = 0; j <= k; j++) {
            dp[i+1][j] = dp[i][j] + dp2[0];
            for (int r = 0; r <= sz && r <= j; r++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j-r] + dp2[r]);
            }
        }
    }
    cout << dp[n][k] << endl;
}