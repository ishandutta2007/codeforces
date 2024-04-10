#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int MOD;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int dp[405][405];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> MOD;
    dp[1][1] = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            dp[i+1][j+1] = add(dp[i+1][j+1], mul(j+1, dp[i][j]));
            dp[i+1][j] = add(dp[i+1][j], mul(2*j, dp[i][j]));
            dp[i+2][j] = add(dp[i+2][j], mul(2*j, dp[i][j]));
            dp[i+2][j-1] = add(dp[i+2][j-1], mul(2*j-2, dp[i][j]));
            dp[i+3][j-1] = add(dp[i+3][j-1], mul(j-1, dp[i][j]));
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}