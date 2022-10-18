#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(3, std::numeric_limits<int>::min()));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        for (int j = 0; j < 3; j++) {
            int z = (j + x) % 3;
            auto& y = dp[i+1][z];
            if (z == 0)
                y = max(y, dp[i][j] + 1);
            else
                y = max(y, dp[i][j]);
            auto& r = dp[i+1][0];
            r = max(r, dp[i][j]);
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
}