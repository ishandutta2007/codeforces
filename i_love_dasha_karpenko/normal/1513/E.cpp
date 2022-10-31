#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MOD = 1E9+7;
const ll INF = 1E9;
const ll LOG = 21;
ll A[DIM],fact[DIM],rev[DIM];
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power = (power>>1);
    }
    return x;
}
ll C(ll n,ll k){
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = rev[0] = 1;
    for (ll i = 1; i < DIM; ++i){
        fact[i] = (fact[i - 1] * i) % MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        sum+=A[i];
    }
    if (sum%n!=0){
        cout<<"0\n";
        return 0;
    }
    sum/=n;
    ll cnt1 = 0,cnt2 = 0,cnt3 = 0;
    map<ll,ll> S1,S2;
    for(ll i = 1;i<=n;++i){
        if (A[i]<sum){
            ++cnt1;
            S1[A[i]]++;
        }
        else if (A[i]>sum){
            ++cnt2;
            S2[A[i]]++;
        }
        else ++cnt3;
    }
    ll div = 1;
    for(auto to:S1){
        div = (div*rev[to.second])%MOD;
    }
    for(auto to:S2){  // cnt1+cnt2-1 - seps
        div = (div*rev[to.second])%MOD;
    }
    ll MU = 0;
    for(ll i = 0;i<=min(cnt1+cnt2,cnt3-1);++i){
        ll cur = C(cnt3-1,i)*C(cnt1+cnt2+1,i+1);
        MU = (MU+cur)%MOD;
    }
    if (cnt3==0)
        MU = 1;
    if (cnt1<=1 || cnt2<=1){
        cout<<fact[cnt1+cnt2]*div%MOD*MU%MOD<<endl;
        return 0;
    }

    else{
        ll res = fact[cnt1]*div%MOD*fact[cnt2]%MOD*fact[2]*MU%MOD;
        cout<<res<<endl;
    }
    return 0;
}