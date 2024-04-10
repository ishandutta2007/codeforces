#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 3E5+7;
const ll MOD = 998244353;
ll fact[DIM];
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
ll C(ll n,ll k){
    return (fact[n]*rev(fact[k]*fact[n-k]))%MOD;
}
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for(ll i = 1;i<DIM;++i)fact[i] = (fact[i-1]*i)%MOD;
    ll n;
    cin>>n;
    for(ll i = 1;i<=n*2;++i)cin>>A[i];
    sort(A+1,A+1+n*2);
    ll res = 0;
    for(ll i = 1;i<=n*2;++i){
        if (i<=n)res-=A[i];
        else res+=A[i];
    }
    res%=MOD;
    cout<<(res*C(n*2,n))%MOD<<endl;

    return 0;

}