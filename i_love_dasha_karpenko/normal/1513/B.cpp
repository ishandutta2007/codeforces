#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MOD = 1E9+7;
const ll SZ = 35;
ll cnt[SZ],fact[DIM],rev[DIM];

ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = (x*mult)%MOD;
        power = (power>>1);
        mult = (mult*mult)%MOD;
    }
    return x;
}
ll A(ll n,ll k){
    if (n<k)
        return 0;
    return (fact[n]*rev[n-k])%MOD;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = rev[0] = 1;
    for(ll i = 1;i<DIM;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    ll t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        ll n;
        cin>>n;
        map<ll,ll> M;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            M[x]++;
            ll bit = 0;
            while(x){
                cnt[bit++]+=(x&1);
                x = (x>>1);
            }
        }
        ll num = 0;
        for(ll i = 0;i<SZ;++i){
            if (cnt[i]==n)
                num+=(1<<i);
        }
        ll clk = M[num];
        ll res = (A(clk,2)*fact[n-2])%MOD;
        cout<<res<<endl;
    }
    return 0;
}