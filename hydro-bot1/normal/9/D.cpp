// Hydro submission #6220be633d794d828a9cd09d@1646313060473
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dp[40][40];


int main(){
    int n, h; cin >> n >> h;
    for(int i = 0; i <= n; i++) dp[0][i] = 1;
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            for(int z = 0; z < j; z++){
                dp[j][i] += dp[z][i-1] * dp[j - z - 1][i-1];
            }
        }
    }
    cout << dp[n][n] - dp[n][h - 1] << '\n';



}