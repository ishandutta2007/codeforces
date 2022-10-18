#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<string> board(n);
    for (auto& x : board)
        cin >> x;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = board[i][j] == 'a';
            if (i && j)
                dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            else if (i)
                dp[i][j] += dp[i-1][j];
            else if (j)
                dp[i][j] += dp[i][j-1];
        }
    }

    vector<pair<int, int>> start(2*n, {2*n, 2*n});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            start[i+j+1] = min(start[i+j+1], pair<int, int>{i, j});
            // int len = i + j + 1;
            // int max_as = min(len, dp[i][j] + k);
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    // cout << endl;

    vector<char> ans;
    // if (board[0][0] == 'a' || k > 0)
    //     ans.push_back('a');
    // else
    //     ans.push_back(board[0][0]);

    vector<pair<int, int>> q_cur;

    int len;
    for (len = 1; len <= 2*n - 1; len++) {
        auto [i, j] = start[len];
        vector<pair<int, int>> q;
        while (j >= 0 && i < n) {
            if (min(len, dp[i][j] + k) == len) {
                q.push_back({i, j});
            }
            i++, j--;
        }

        if (q.empty())
            break;
        q_cur = q;
    }

    for (int i = 1; i < len; i++)
        ans.push_back('a');

    if (len == 1) {
        ans.push_back(board[0][0]);
        q_cur.push_back({0, 0});
    }

    while ((int)ans.size() < 2*n - 1) {
        // find next char
        vector<set<pair<int, int>>> q_nexts(26);
        for (auto [i, j] : q_cur) {
            if (i + 1 < n) {
                q_nexts[board[i+1][j] - 'a'].insert({i+1, j});
            }
            if (j + 1 < n) {
                q_nexts[board[i][j+1] - 'a'].insert({i, j+1});
            }
        }
        for (int i = 0; i < 26; i++) {
            if (q_nexts[i].size()) {
                ans.push_back('a' + i);
                q_cur = vector<pair<int, int>>(q_nexts[i].begin(), q_nexts[i].end());
                break;
            }
        }
    }

    for (auto x : ans) {
        cout << x;
    }
    cout << '\n';
}