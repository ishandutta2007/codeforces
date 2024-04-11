#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll mod = 998244353;
ll dp[2][1001][2001];

int main() {
    //cout.precision(10);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1001; j++){
            for(int k = 0; k < 2001; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][1][1] = 2;
    dp[1][1][2] = 2;
    for(int number = 2; number <= n; number++){
        for(int connected = 1; connected <= k; connected++){
            dp[0][number][connected] += dp[0][number - 1][connected];
            dp[0][number][connected] += dp[0][number - 1][connected - 1];
            dp[0][number][connected] += dp[1][number - 1][connected];
            dp[0][number][connected] += dp[1][number - 1][connected];
            dp[0][number][connected] = dp[0][number][connected] % mod;
            dp[1][number][connected] += dp[0][number - 1][connected - 1];
            dp[1][number][connected] += dp[0][number - 1][connected - 1];
            dp[1][number][connected] += dp[1][number - 1][connected];
            dp[1][number][connected] += dp[1][number - 1][connected - 2];
            dp[1][number][connected] = dp[1][number][connected] % mod;
        }
    }
    cout << (dp[0][n][k] + dp[1][n][k]) % mod << endl;
    return 0;
}