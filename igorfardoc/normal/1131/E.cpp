#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vvi dp(n + 1, vi(26, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            int start = 0;
            int end = 0;
            for(int k = 0; k < a[i - 1].size(); k++) {
                if(a[i - 1][k] - 'a' == j) {
                    ++start;
                } else {
                    break;
                }
            }
            for(int k = a[i - 1].size() - 1; k >= 0; k--) {
                if(a[i - 1][k] - 'a' == j) {
                    ++end;
                } else {
                    break;
                }
            }
            int prev = -1;
            for(int k = 0; k < a[i - 1].size(); k++) {
                if(a[i - 1][k] - 'a' != j) {
                    prev = -1;
                    continue;
                }
                if(prev == -1) prev = k;
                dp[i][j] = max(dp[i][j], k - prev + 1);
            }
            if(start == a[i - 1].size()) {
                dp[i][j] = max(dp[i][j], start * (dp[i - 1][j] + 1) + dp[i - 1][j]);
                continue;
            }
            if(dp[i - 1][j] > 0) {
                dp[i][j] = max(dp[i][j], (start + end) + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}