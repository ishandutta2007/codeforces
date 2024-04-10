#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
const ll DIM = 400000+7;
const ll INF = 10e16;
const ll MOD = 998244353  ;
ll po(ll x,ll power){
    ll mult = x%MOD,ret = 1;
    while(power>0){
        if (power&1)ret = (ret*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll p = 1,q = 1;
    ll res = 0;
    vector<ll> A(n+7);
    forn(i,n)cin>>A[i];
    reverse(A.begin()+1,A.begin()+n+1);
    forn(i,n){
        //if (i!=1)
        //q = (q*100)%MOD;
        ll x=  A[i];
        p*=x;
        q*=100;
        q%=MOD;
        p%=MOD;
        res = (res+q*po(p,MOD-2))%MOD;
        res%=MOD;
    }
    cout<<res<<endl;
    return 0;

}
// 0 1 2 3
// 0 1 -> 0 1 2 1 0
// 1 2 -> 1 2 3 2 1
// 2 3 -> 2 3 2 1 2 3