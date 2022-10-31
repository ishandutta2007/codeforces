#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
ll T[DIM*4],P[DIM],pref[DIM],M[DIM*4];
pp A[DIM];
void buildtree(ll t,ll tl,ll tr){
    if(tl==tr){
        T[t] = pref[tl-1];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
void push(ll t){
    T[t*2+1]+=M[t];
    T[t*2+2]+=M[t];
    M[t*2+1]+=M[t];
    M[t*2+2]+=M[t];
    M[t] = 0;
    T[t] = min(T[t*2+1],T[t*2+2]);
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll delta){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        M[t]+=delta;
        T[t]+=delta;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,delta);
    update(t*2+2,tm+1,tr,l,r,delta);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i].fi;
    forn(i,n){
        cin>>A[i].sc;
        P[A[i].fi] = i;
    }
    forn(i,n){
        pref[i] = pref[i-1]+A[P[i]].sc;
    }
    buildtree(0,1,n+1);
    ll res = INF;
    forn(i,n-1){

        update(0,1,n+1,1,A[i].fi,A[i].sc);
        update(0,1,n+1,A[i].fi+1,n+1,-A[i].sc);
        res = min(res,T[0]);
       // cout<<T[0]<<endl;
    }
    cout<<res<<endl;
    return 0;
}
// 9 7+2