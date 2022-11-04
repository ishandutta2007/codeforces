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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = a[i - 1].second + dp[i - 1][min(n, j + 1)];
                if(a[i - 1].first <= j) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][min(n, j + 1)]);
                }
                if(a[i - 1].first > j && i - 1 + j >= a[i - 1].first) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
            }
        }
        cout << dp[n][0] << '\n';
    }
}