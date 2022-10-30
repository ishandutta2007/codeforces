#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int MOD = 998244353;
const int N = 250+7;
ll dp[N][N];
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power>0){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll fact[N],rev[N];
ll C(int n,int k){
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}

void solve() {

    int n,k;
    cin>>n>>k;

    dp[1][1] = 1;
    for(int cmp = 1;cmp<n;++cmp){
        for(int w = 1;w<=k+1;++w){
            dp[cmp][w] = (dp[cmp][w]+dp[cmp][w-1])%MOD;
            if (cmp==1)
                dp[cmp][w] = 1;
            for(int ncmp = cmp+1;ncmp<=n;++ncmp){
                dp[ncmp][w+1] = (dp[ncmp][w+1]+dp[cmp][w]*binpow(k-w+1,(cmp+ncmp-3)*(ncmp-cmp)/2)%MOD*C(n-cmp,ncmp-cmp))%MOD;
            }
        }
    }
    ll res = 0;
    for(int i = 1;i<=k+1;++i)
        res = (res+dp[n][i])%MOD;
    cout<<res<<endl;
}
signed main(){
    fact[0] = 1;
    for(int i = 1;i<N;++i)
        fact[i] = fact[i-1]*i%MOD;
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i =N-1;i>=1;--i)
        rev[i-1] = rev[i]*i%MOD;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}