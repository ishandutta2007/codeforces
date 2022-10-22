#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[5];
ll dpp[5];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    dp[4] = 1;
    int n;
    cin >> n;
    while(n--){
        for(int i=1; i<=4; i++) dpp[i] = dp[i];
        for(int i=1; i<=4; i++){
            dp[i] = dpp[1]+dpp[2]+dpp[3]+dpp[4]-dpp[i];
            dp[i] %= MOD;
        }
    }
    cout << dp[4];
    return 0;
}