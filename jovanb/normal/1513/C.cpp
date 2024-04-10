#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int dp[200005][10];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=0; i<=9; i++) dp[0][i] = 1;
    for(int i=1; i<=200000; i++){
        for(int j=0; j<9; j++){
            dp[i][j] = dp[i-1][j+1];
        }
        dp[i][9] = add(dp[i-1][0], dp[i-1][1]);
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int res = 0;
        while(n){
            int x = n%10;
            res = add(res, dp[m][x]);
            n /= 10;
        }
        cout << res << "\n";
    }
    return 0;
}