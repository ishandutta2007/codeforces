#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll dp[1000005][2];
ll a[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        if(a[i] >= a[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1] - a[i-1] + a[i]);
        if(a[i] <= a[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0] - a[i] + a[i-1]);
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}