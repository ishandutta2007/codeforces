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
        vi a(n), b(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ans += (n - 1) * a[i] * a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            ans += (n - 1) * b[i] * b[i];
        }
        vi suff(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i] + b[i];
        }
        vvi dp(n + 1, vi(100 * n + 1, 0));
        for(int i = 1; i <= n; i++) {
            int sum = suff[i];
            for(int j = 0; j <= 100 * n; j++) {
                if(sum - j < 0 || j + max(a[i - 1], b[i - 1]) > 100 * n) continue;
                int other = sum - j;
                dp[i][j] = min(dp[i - 1][j + a[i - 1]] + 2 * a[i - 1] * j + 2 * b[i - 1] * other, dp[i - 1][j + b[i - 1]] + 2 * b[i - 1] * j + 2 * a[i - 1] * other);
            }
        }
        ans += dp[n][0];
        cout << ans << '\n';
    }
}