#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> changes_to_white(m, 0);
    vector<int> changes_to_black(m, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '#')
                changes_to_white[j]++;
            else
                changes_to_black[j]++;
        }
    }

    // vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(y+1, vector<int>(2, numeric_limits<int>::max() / 2)));
    vector<vector<int>> dp(y+1, vector<int>(2, numeric_limits<int>::max() / 2));
    dp[1][0] = changes_to_white[0];
    dp[1][1] = changes_to_black[0];

    for (int i = 2; i < m+1; i++) {
        vector<vector<int>> dp2(y+1, vector<int>(2, numeric_limits<int>::max() / 2));
        for (int last_value = 0; last_value < 2; last_value++) {
            int changes = last_value == 0 ? changes_to_white[i-1] : changes_to_black[i-1];
            
            for (int j = 2; j <= y; j++)
                dp2[j][last_value] = dp[j-1][last_value] + changes;

            for (int j = x; j <= y; j++)
                dp2[1][last_value] = min(dp2[1][last_value], dp[j][1-last_value] + changes);
        }
        dp = dp2;
    }

    int result = numeric_limits<int>::max();
    for (int j = x; j <= y; j++)
        result = min(result, min(dp[j][1], dp[j][0]));
    
    cout << result << endl;
}