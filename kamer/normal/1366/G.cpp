#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;
    
    s.append("+");
    t.append("+");
    int n = s.length();
    int m = t.length();
    
    vector<int> nextt(s.length() + 3, -1);
    vector<vector<int>> numCharBuckets(3 * n + 3, vector<int>());
    int prevNumChars = 0;
    numCharBuckets[n + 1].push_back(0);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '.') {
            prevNumChars--;
        } else {
            prevNumChars++;
        }
        numCharBuckets[prevNumChars + n + 1].push_back(i);
    }

    for (int num = 0; num < 3 * n + 3; num++) {
        for (int i = 0; i + 1 < numCharBuckets[num].size(); i++) {
            nextt[numCharBuckets[num][i]] = numCharBuckets[num][i + 1];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 2 * n));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) {
                dp[i][j] = 0;
            } else if (j == n - 1) {
                dp[i][j] = 2 * n;
            } else {
                if (s[j] == '.') {
                    dp[i][j] = dp[i][j + 1] + 1;
                } else {
                    dp[i][j] = dp[i][j + 1] + 1;
                    if (nextt[j] != -1) {
                        dp[i][j] = min(dp[i][j], dp[i][nextt[j]]);
                    }
                    if (s[j] == t[i]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                    }
                }
            }
        }
    }

    cout << dp[0][0] << "\n";
}