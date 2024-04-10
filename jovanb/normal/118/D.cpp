#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][105][3][20];
ll k[3];

const ll MOD = 100000000;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    dp[1][0][1][1] = 1;
    dp[0][1][2][1] = 1;
    int n1, n2;
    cin >> n1 >> n2 >> k[1] >> k[2];
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            if(i == 0 && j == 0) continue;
            for(int k1=1; k1<=2; k1++){
                for(int r=1; r<=k[k1]; r++){
                    if(k1 == 1){
                        if(i < n1 && r < k[k1]){dp[i+1][j][1][r+1] += dp[i][j][k1][r]; dp[i+1][j][1][r+1] %= MOD;}
                        if(j < n2){dp[i][j+1][2][1] += dp[i][j][k1][r]; dp[i][j+1][2][1] %= MOD;}
                    }
                    if(k1 == 2){
                        if(j < n2 && r < k[k1]){dp[i][j+1][2][r+1] += dp[i][j][k1][r]; dp[i][j+1][2][r+1] %= MOD;}
                        if(i < n1){dp[i+1][j][1][1] += dp[i][j][k1][r]; dp[i+1][j][1][1] %= MOD;}
                    }
                }
            }
        }
    }
    ll ukup = 0;
    for(int k1=1; k1<=2; k1++){
        for(int r=1; r<=k[k1]; r++){
            ukup += dp[n1][n2][k1][r];
        }
    }
    cout << ukup%MOD;
    return 0;
}