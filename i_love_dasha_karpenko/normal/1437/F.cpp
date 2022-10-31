#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 5000+7;
const ll MOD = 998244353 ;
const ll LOG = 60;
const ll INF = 1E18;
ll dp[DIM],sum[DIM][DIM],fact[DIM],re[DIM],A[DIM],su[DIM];
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
ll rev(ll x){
    return binpow(x,MOD-2);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    re[0] = 1;
    for(ll i = 1;i<DIM;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        re[i] = rev(fact[i]);
    }
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)cin>>A[i];
    sort(A+1,A+1+n);
    ll prev = -1;
    ll ptr = 0;
    sum[0][0] = 1;

    for(ll i = 1;i<=n;++i){
        while (A[ptr+1]*2<=A[i])++ptr;
        if (ptr!=prev){
            prev = ptr;
            ll ml = 0;
            for(ll len = 1;len<=ptr+1;++len){
                ml = (ml+sum[len-1][ptr]*fact[ptr-len+1])%MOD;

                dp[len] = (ml*re[ptr-len+1])%MOD;

            }
        }
        for(ll len = 0;len<=n;++len){
            sum[len][i] = (sum[len][i-1]+dp[len])%MOD;
        }
    }
    cout<<sum[n][n]<<endl;
    return 0;

}