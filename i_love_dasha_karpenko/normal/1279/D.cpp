#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 10E5+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
ll n,A[DIM],cnt[DIM],rcnt[DIM];
ll binpow(ll x,ll power){
    ll mult = x; x = 1;
    while(power>0){
        if (power&1){
            x = (x*mult)%MOD;
        }
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin>>n;
    forn(i,DIM-1)cnt[i] = 1;
    forn(i,n){
        ll l; cin>>l;
        //cnt+=l;
        forn(j,l){
            ll x; cin>>x;
            A[x]++;
            pp n1 = {1,l};
            //ll r = l;
            n1.fi=(n1.fi*cnt[x])%MOD;
            n1.sc=(n1.sc*cnt[x])%MOD;
            cnt[x]=(cnt[x]*l)%MOD;
            rcnt[x]=(rcnt[x]*l)%MOD;
            rcnt[x]=(rcnt[x]+n1.fi)%MOD;
            ll g = __gcd(cnt[x],rcnt[x]);
            cnt[x]/=g;
            rcnt[x]/=g;
        }
    }
    ll r1 = 0,r2 = 1;
    forn(i,DIM-1){
        if (A[i]==0)continue;
        cnt[i]=(cnt[i]*n)%MOD;
        cnt[i] = (cnt[i]*n)%MOD;
        rcnt[i]=(rcnt[i]*A[i])%MOD;
        ll h = cnt[i];
        cnt[i]=(cnt[i]*r2)%MOD;
        rcnt[i]=(rcnt[i]*r2)%MOD;
        r1 = (r1*h)%MOD;
        r2=(r2*h)%MOD;
        r1=(r1+rcnt[i])%MOD;

        ll g =__gcd(r1,r2);
        r1/=g;
        r2/=g;
    }
    ll g = __gcd(r1,r2);
    r1/=g;
    r2/=g;
    //cout<<r1<<' '<<r2<<endl;
    cout<<(binpow(r2,MOD-2)*r1)%MOD<<endl;
    return 0;

}