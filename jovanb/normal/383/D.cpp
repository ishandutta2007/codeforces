#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int offset = 15005;
const int MOD = 1000000007;

int dp[1005][35005];
int niz[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        for(int j=-10000; j<=10000; j++){
            dp[i][j+offset] += (dp[i-1][j+offset-niz[i]]+dp[i-1][j+offset+niz[i]])%MOD;
        }
        dp[i][niz[i]+offset] = (1+dp[i][niz[i]+offset])%MOD;
        dp[i][-niz[i]+offset] = (1+dp[i][-niz[i]+offset])%MOD;
    }
    ll res=0;
    for(int i=1; i<=n; i++){
        res = (res+dp[i][offset])%MOD;
    }
    cout << res;
    return 0;
}