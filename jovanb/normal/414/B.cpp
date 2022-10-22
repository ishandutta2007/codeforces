#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

ll dp[3000][3000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        dp[1][i] = 1;
    }
    for(int k1=1; k1<k; k1++){
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j+=i){
                dp[k1+1][j] += dp[k1][i];
                dp[k1+1][j] %= MOD;
            }
        }
    }
    ll zbir = 0;
    for(int i=1; i<=n; i++){
        zbir += dp[k][i];
        zbir %= MOD;
    }
    cout << zbir;
    return 0;
}