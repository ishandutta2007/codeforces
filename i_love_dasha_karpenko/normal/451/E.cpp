//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 27;
const ll MOD = 1e9+7;
ll binpow(ll x,ll power){
    ll mult = x;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        power = power>>1;
        mult = mult*mult%MOD;
    }
    return x;
}
ll rev[N],F[N],po[N];
ll C(ll n,ll k){
    ll ret = 1;
    for(ll i = n-k+1;i<=n;++i){
        ll mlt = i%MOD;
        ret = (ret*mlt)%MOD;
    }
    ret = ret*rev[k]%MOD;
    return ret;
}
signed main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rev[0] = 1;
    po[0] = 1;
    for(int i = 1;i<N;++i){
        rev[i] = rev[i-1]*binpow(i,MOD-2)%MOD;
        po[i] = po[i-1]*2;
    }
    ll n,s;
    cin>>n>>s;
    for(int i = 0;i<n;++i){
        scanf("%lld",&F[i]);
    }
    ll masksz = 1<<n,res = 0;
    for(ll mask = 0;mask<masksz;++mask){
        ll sz = __builtin_popcount(mask);
        ll mlt = (sz&1)?-1:1;
        ll dif = 0;
        for(int bit = 0;bit<n;++bit){
            if (po[bit]&mask)
                dif+=F[bit]+1;
        }
        if (dif>s)
            continue;
        res+=C(s-dif+n-1,n-1)*mlt;
        if (res>=MOD)
            res-=MOD;
        if (res<0)
            res+=MOD;
    }
    cout<<res<<endl;
    return 0;
}