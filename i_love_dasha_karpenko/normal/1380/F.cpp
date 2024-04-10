#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 5E5+7;

const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll MOD = 998244353 ;
ll dp[10][DIM],re[10][DIM];
ll binpow(ll x,ll power){
    ll mult = x;
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
ll gi(char ch){
    return ch-'0';
}
ll A[DIM];
struct node{
    ll fi,sc,pref,en;
};
node T[DIM*4];

node mer(node a,node b,ll tl,ll tr){
    ll tm = (tl+tr)/2;
    a.fi = (a.fi*re[1][a.sc])%MOD;
    if (b.sc==tr-tm){
        a.fi = (a.fi*dp[1][a.sc+b.sc])%MOD;

        if (a.sc==tm+1-tl){
            a.pref = a.sc+b.sc;
            a.en = 1;
        }
        a.sc+=b.sc;
    }
    else{
        b.fi = (b.fi*re[b.en][b.pref+1])%MOD;
        a.fi = (a.fi*dp[b.en][a.sc+b.pref+1])%MOD;
        a.fi = (a.fi*b.fi)%MOD;
        if (a.sc==tm+1-tl){
            a.pref+=b.pref;
            a.en = b.en;
        }
        a.sc = b.sc;
    }
    return a;
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t].fi = A[tl]+1;
        T[t].sc = (A[tl]==1);
        T[t].pref = (A[tl]==1);
        T[t].en = A[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = mer(T[t*2+1],T[t*2+2],tl,tr);
}
void update(ll t,ll tl,ll tr,ll pos,ll val){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        A[tl] = val;
        T[t].fi = A[tl]+1;
        T[t].sc = (A[tl]==1);
        T[t].pref = (A[tl]==1);
        T[t].en = A[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = mer(T[t*2+1],T[t*2+2],tl,tr);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll last = 0;last<10;++last){
        dp[last][1] = last+1;
        dp[last][0] = 1;
        re[last][0] = 1;
        re[last][1] = rev(last+1);
        for(ll len = 2;len<DIM;++len){
            ll x = 9-(len>2?1:last);
            dp[last][len] = (dp[last][len-1]*2+dp[last][len-2]*x)%MOD;
            re[last][len] = rev(dp[last][len]);
        }
    }
    ll n,m;
    cin>>n>>m;
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
    }
    /*ll res = 1;
    for(ll i = n;i>=1;--i){
        mu[i] = A[i]+1;
        if (A[i]==1 && i<n)mu[i]=(((10-1-A[i+1])*rev(mu[i-1))%MOD+mu[i])%MOD;
        res = (res*mu[i])%MOD;
    }*/
    buildtree(0,1,n);
    forn(i,m){
        ll pos,val;
        cin>>pos>>val;
        update(0,1,n,pos,val);
        cout<<T[0].fi<<endl;
    }

    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,