#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e8;
const ll MOD = 1E9+123;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll base = DIM;
ll n;
pp A[DIM];
set<ll> S;
map<ll,ll> M;
pp T[DIM*4];
void update(ll t,ll tl,ll tr,ll pos,pp val){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        T[t].fi+=val.fi;
        T[t].sc+=val.sc;
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t].fi = T[t*2+1].fi+T[t*2+2].fi;
    T[t].sc = T[t*2+1].sc+T[t*2+2].sc;
}
pp query(ll t,ll tl,ll tr,ll l,ll r){
    if (l>r)return {0,0};
    if (tl>r || l>tr)return {0,0};
    if (l<=tl && tr<=r)return T[t];
    ll tm = (tl+tr)/2;
    pp qe = query(t*2+1,tl,tm,l,r);
    pp qe1 = query(t*2+2,tm+1,tr,l,r);
    qe.fi+=qe1.fi;
    qe.sc+=qe1.sc;
    return qe;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i].fi;
    forn(i,n){
        cin>>A[i].sc;
        S.insert(A[i].sc);
    }
    ll ptr = 0;
    for(ll to:S){
        M[to] = ++ptr;
    }
    sort(A+1,A+1+n);
    forn(i,n){
        update(0,1,ptr,M[A[i].sc],{A[i].fi,1});
    }
    ll res = 0;
    forn(i,n){
        update(0,1,ptr,M[A[i].sc],{-A[i].fi,-1});
        pp qe=query(0,1,ptr,M[A[i].sc],ptr);
        res+=qe.fi-A[i].fi*qe.sc;
    }
    cout<<res<<endl;
    return 0;
}