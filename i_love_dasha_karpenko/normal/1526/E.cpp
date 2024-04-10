//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 200000+7;
const ll MOD = 998244353;
ll fact[DIM],rev[DIM];
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
ll C(ll n,ll k){
    return (((fact[n]*rev[k])%MOD)*rev[n-k])%MOD;
}
ll A[DIM],pos[DIM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = rev[0] = 1;
    for(ll i = 1;i<DIM;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i) {
        cin >> A[i];
        pos[A[i]] = i;
    }
    pos[n+1] = 0;
    ll cer = 1,opt = 0;
    for(ll i = 2;i<=n;++i){
        if (pos[A[i-1]+1]<pos[A[i]+1])
            ++opt;
        else ++cer;
    }
    ll res = 0;
    for(ll i = cer;i<=min(k,cer+opt);++i){
        res = (res+C(k,i)*C(opt,i-cer))%MOD;
    }
    cout<<res<<endl;
    return 0;
}