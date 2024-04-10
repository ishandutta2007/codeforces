#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2e5+7;
const ll MOD = 1e9+7;
int n,l,r;
ll fact[DIM],rev[DIM];
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll C(ll n,ll k){
    if (n<k || n<0 || k<0)
        return 0;
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
ll get(int x){
    int tl = max(1,l+x)-1,tr = n-min(n,r-x);
    int half = (n>>1)+(n&1);
    if (n&1)
        return C(n-tl-tr,half-tl)+C(n-tl-tr,half-tr);
    else
        return C(n-tl-tr,half-tl);
}
int solve(){
    cin>>n>>l>>r;
    int bk = min(r-n,1-l);
    ll res = get(1)*bk%MOD;
    for(int cur = bk+1;cur>0;++cur){
        ll ret = get(cur);
        if (!ret)
            break;
        res = (res+ret)%MOD;
    }
    cout<<res<<endl;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = rev[0] = 1;
    for(int i = 1;i<DIM;++i){
        fact[i] = fact[i-1]*i%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        assert(solve());
    return 0;
}