#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll add(ll a, ll b){
    ll k = a+b;
    if(k < MOD) return k;
    return k%MOD;
}

ll dp[2005][2005];
ll niz[2005];

int main(){

    ll n, h;
    cin >> n >> h;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        niz[i] = h - niz[i];
    }
    if(niz[1] == 0){
        dp[1][0] = 1;
    }
    else if(niz[1] == 1){
        dp[1][0] = 1;
        dp[1][1] = 1;
    }
    //cout << dp[1][0] << " " << dp[1][1] << endl;
    for(ll i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            /// nista
            dp[i+1][j] = add(dp[i+1][j], dp[i][j]*(j == niz[i+1]));
            /// [
            dp[i+1][j+1] = add(dp[i+1][j+1], dp[i][j]*(j+1 == niz[i+1]));
            /// ]
            if(j) dp[i+1][j-1] = add(dp[i+1][j-1], dp[i][j]*1LL*(j)*(j == niz[i+1]));
            /// []
            dp[i+1][j] = add(dp[i+1][j], dp[i][j]*1LL*(j+1)*(j+1 == niz[i+1]));
        }
    }
    cout << dp[n][0];
    return 0;
}