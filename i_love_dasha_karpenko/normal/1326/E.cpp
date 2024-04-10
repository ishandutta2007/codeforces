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
const ll DIM = 3E5+7;
const ll INF = 1E9;

ll n,pos[DIM],Q[DIM],T[DIM*4],add[DIM*4];
void push(ll t){
    T[t*2+1]+=add[t];
    T[t*2+2]+=add[t];
    add[t*2+1]+=add[t];
    add[t*2+2]+=add[t];
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll delta){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        add[t]+=delta;
        T[t]+=delta;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,delta);
    update(t*2+2,tm+1,tr,l,r,delta);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
ll dec(ll x){
    update(0,1,n,1,pos[x],1);
    if (T[0]>0){
        update(0,1,n,1,pos[x],-1);
        return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        ll x;
        cin>>x;
        pos[x] = i;
    }
    forn(i,n)cin>>Q[i];
    ll cur = n;
    forn(i,n){
        cout<<cur<<' ';
        update(0,1,n,1,Q[i],-1);
        while(dec(cur))--cur;

    }
    return 0;
}