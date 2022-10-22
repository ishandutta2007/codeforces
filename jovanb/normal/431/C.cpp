#include <bits/stdc++.h>
using namespace std;

long long dp[1000][1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k, d, i, j;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;

    for(i = 1; i <= n; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
        for(j = 1; j <= k; j++){
            if(i-j < 0)break;
            if(j < d){
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
            else{
                dp[i][1] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];

            }
            dp[i][1] %= 1000000007;
            dp[i][0] %= 1000000007;
        }
    }
    cout << dp[n][1];
    return 0;
}