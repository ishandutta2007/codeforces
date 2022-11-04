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
        vi a(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        vi can;
        int now = a[0];
        int id1 = 0;
        for(int i = 1; i < 2 * n; i++) {
            if(a[i] > now) {
                can.push_back(i - id1);
                now = a[i];
                id1 = i;
            }
        }
        can.push_back(2 * n - id1);
        vector<vector<bool>> dp(n + 1, vector<bool>(can.size() + 1, false));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= can.size(); j++) {
                if(i == 0) {
                    dp[i][j] = true;
                    continue;
                }
                if(j == 0) {
                    continue;
                }
                dp[i][j] = dp[i][j - 1];
                if(i >= can[j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - can[j - 1]][j - 1];
                }
            }
        }
        if(dp[n][can.size()]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}