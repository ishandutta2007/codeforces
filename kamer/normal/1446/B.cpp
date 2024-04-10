#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    A.push_back('-');
    B.push_back('-');
    vector<set<int>> A_map(26, set<int>()), B_map(26, set<int>());
    for (int i = 0; i < n; i++) {
        A_map[A[i] - 'a'].insert(i);
    }
    for (int i = 0; i < m; i++) {
        B_map[B[i] - 'a'].insert(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    dp[n][m] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (A[i] == B[j]) {
                dp[i][j] = 2;
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 2);
            } else {
                dp[i][j] = -2;
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] - 2); 
                auto a_it = A_map[B[j] - 'a'].upper_bound(i);
                auto b_it = B_map[A[i] - 'a'].upper_bound(j);
                if (a_it != A_map[B[j] - 'a'].end()) {
                    int a_ind = *a_it;
                    dp[i][j] = max(dp[i][j], max(0, dp[a_ind + 1][j + 1]) + 2 - a_ind + i);
                }

                if (b_it != B_map[A[i] - 'a'].end()) {
                    int b_ind = *b_it;
                    dp[i][j] = max(dp[i][j], max(0, dp[i + 1][b_ind + 1]) + 2 - b_ind + j);
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, dp[i][j]);
        }
    }

    cout << res << "\n";
}