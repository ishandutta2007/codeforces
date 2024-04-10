#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, m, k;
ll arr[303030], ans;
ll dp[303030][10];

int main() {
    cin >> n >> m >> k;
    for (ll i=0; i<n; i++) cin >> arr[i];

    dp[0][1] = arr[0]-k;

    for (ll i=1; i<n; i++) {
        dp[i][1] = max(arr[i]-k, dp[i-1][m]+arr[i]-k);
        for (ll j=2; j<=min(m, i+1); j++) {
            dp[i][j] = dp[i-1][j-1]+arr[i];
        }
    }

    for (ll i=0; i<n; i++) {
        for (ll j=0; j<=m; j++) {
            ans = max(ans, dp[i][j]);

           // cout << dp[i][j] << ' ';
        }
      //  cout << '\n';
    }

    cout << ans;
}