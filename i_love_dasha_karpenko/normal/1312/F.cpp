#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 3E5;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll A[DIM],dp[DIM][3];
ll pref[DIM],hh[DIM];
ll base = 4;
set<pp> S;
ll mex(vector<ll> V){
    sort(V.begin(),V.end());
    ll cur = 0;
    for(ll to:V){
        if(to==cur)cur++;
        if (to>cur)return cur;
    }
    return cur;
}
ll ff(ll val,ll mod){
    if (val<0)return 0;
    return dp[val][mod];
}
pp findcyc(ll x,ll y,ll z){
    forn(i,DIM-1){
        ll h = 0;

        dp[i][0] = mex({ff(i-x,0),ff(i-y,1),ff(i-z,2)});

        dp[i][1] = mex({ff(i-x,0),ff(i-z,2)});

        dp[i][2] = mex({ff(i-x,0),ff(i-y,1)});

        h=(h+dp[i][0])*base;
        h = (h+dp[i][1])*base;
        h = (h+dp[i][2]);
        hh[i] = h;
        if (i<5)continue;
        for(ll j = i;j>i-5 && j>0;--j){
            pref[i]*=base*base*base;
            pref[i]+=hh[j];
        }
        pp el = *S.lower_bound({pref[i],-INF});

        if (el.fi==pref[i])return {el.sc,i};
        S.insert({pref[i],i});
    }
}

ll F(ll val,pp per,ll mod){
    if (val<=0)return 0;
    if (val<=per.sc)return dp[val][mod];
    val-=per.fi;
    val%=(per.sc-per.fi);
    return dp[val+per.fi][mod];
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        S.clear();
        ll n,x,y,z;
        cin>>n>>x>>y>>z;
        forn(i,n)cin>>A[i];
        pp per = findcyc(x,y,z);
        ll res = 0;
        forn(i,n){
            res^=F(A[i],per,0);
        }
        ll cnt = 0;
        forn(i,n){
            res^=F(A[i],per,0);
            if (!(res^F(A[i]-x,per,0)))cnt++;
            if (!(res^F(A[i]-y,per,1)))cnt++;
            if (!(res^F(A[i]-z,per,2)))cnt++;
            res^=F(A[i],per,0);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
// a[i]-b[i]>b[j]-a[j]