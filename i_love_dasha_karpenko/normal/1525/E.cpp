//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 5E4+7;
const ll INF = 1E9;
const ll MOD = 998244353;
ll A[DIM][21],fact[21],rev[21];
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = rev[0] = 1;
    for(ll i = 1;i<=20;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            cin>>A[j][i];
        }
    }
    ll res = 0;
    for(ll j = 1;j<=m;++j){

        sort(A[j]+1,A[j]+1+n);
        ll vars = 1;
        for(ll i = 1;i<=n;++i){
            vars = (vars*max(0ll,n-(n+1-A[j][i])-(i-1)))%MOD;
        }
        vars = (fact[n]-vars+MOD)%MOD;
        vars = (vars*rev[n])%MOD;
        res = (res+vars)%MOD;

    }
    cout<<res<<endl; //n-time+1 = grow; grow<A[j][i]; n-time+1<A[i][j]; time>n+1-A[i][j]
    return 0;
}