#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

ll dp[1005][2005][2][2];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    dp[1][2][0][0] = 1;
    dp[1][2][1][1] = 1;
    dp[1][3][1][0] = 1;
    dp[1][3][0][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=2; j<=k+1; j++){
            dp[i][j][0][0] += dp[i-1][j][0][0]+dp[i-1][j][0][1]+dp[i-1][j][1][0]+dp[i-1][j-1][1][1];
            dp[i][j][0][0] %= MOD;
            dp[i][j][1][1] += dp[i-1][j-1][0][0]+dp[i-1][j][0][1]+dp[i-1][j][1][0]+dp[i-1][j][1][1];
            dp[i][j][1][1] %= MOD;
            dp[i][j][0][1] += dp[i-1][j-1][0][0]+dp[i-1][j][0][1]+dp[i-1][j-2][1][0]+dp[i-1][j-1][1][1];
            dp[i][j][0][1] %= MOD;
            dp[i][j][1][0] += dp[i-1][j-1][0][0]+dp[i-1][j-2][0][1]+dp[i-1][j][1][0]+dp[i-1][j-1][1][1];
            dp[i][j][1][1] %= MOD;
        }
    }
    cout << (dp[n][k+1][0][0]+dp[n][k+1][0][1]+dp[n][k+1][1][0]+dp[n][k+1][1][1])%MOD;
    return 0;
}