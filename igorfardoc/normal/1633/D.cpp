#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define maxn 1000



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vi dp(maxn + 1, 10000);
    dp[1] = 0;
    for(int i = 1; i <= maxn; i++) {
        for(int x = 1; x <= i; x++) {
            if(i + i / x > maxn) continue;
            dp[i + i / x] = min(dp[i + i / x], dp[i] + 1);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi b(n);
        vi c(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            b[i] = dp[b[i]];
            sum += b[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vvi dp1(n + 1, vi(sum + 1, 0));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0) {
                    dp1[i][j] = 0;
                    continue;
                }
                dp1[i][j] = dp1[i - 1][j];
                if(j >= b[i - 1]) {
                    dp1[i][j] = max(dp1[i][j], c[i - 1] + dp1[i - 1][j - b[i - 1]]);
                }
            }
        }
        cout << dp1[n][min(sum, k)] << '\n';
    }
}