#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 2E5+7;
const ll MOD = 998244353;
ll fact[DIM],A[DIM],pref[DIM];
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
    for(ll i = 1;i<DIM;++i)fact[i] = fact[i-1]*i%MOD;
    ll n,m;
    cin>>n>>m;
    ll cnt = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n,greater<ll>());
    for(ll i = 1;i<=n;++i){
        pref[i] = (pref[i-1]+A[i])%MOD;
    }
    reverse(A+1,A+1+n);
    while(m--){
        ll a,b;
        cin>>a>>b;
        ll cnt = lower_bound(A+1,A+1+n,b)-A;
        cnt = n-cnt+1;
        if (cnt<a){
            cout<<0<<endl;
            continue;
        }
        ll sum = 0;
        if (cnt>0)
            sum = ((fact[cnt-1]*(cnt-a))%MOD*rev(fact[cnt])%MOD*pref[cnt]%MOD+sum)%MOD;

        sum = (fact[cnt]*(cnt-a+1)%MOD*rev(fact[cnt+1])%MOD*(pref[n]-pref[cnt])%MOD+sum)%MOD;
        sum = (sum+MOD)%MOD;
        cout<<sum<<endl;
    }
    return 0;

}