#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[100005];
ll binkof[1005][1005];
ll niz[1005];

const ll MOD = 998244353LL;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=1000; i++) binkof[i][0] = 1;
    binkof[0][0] = 1;
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=i; j++){
            binkof[i][j] = (binkof[i-1][j-1]+binkof[i-1][j])%MOD;
        }
    }
    ull sum=0;
    dp[n+1] = 1;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int j=n; j>=1; j--){
        if(niz[j] <= 0) continue;
        for(int i=niz[j]+1+j; i<=n+1; i++){
            ull kom = binkof[i-1-j][niz[j]];
            dp[j] = (kom*dp[i]+dp[j])%MOD;
        }
        sum += dp[j];
        sum %= MOD;
    }
    cout << sum;
    return 0;
}