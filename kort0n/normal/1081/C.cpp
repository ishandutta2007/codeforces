#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;
ll dp[2005][2005];

int main() {
    //cout.precision(10);
    ll n, m, k;
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * (m - 1)) % mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}