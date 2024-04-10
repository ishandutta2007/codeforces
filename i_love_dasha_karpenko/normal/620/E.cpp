#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 4*10E4+7;
const ld INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 107;
ll n,m,col[DIM],tin[DIM],tout[DIM],timer = 0,mas[DIM],T[DIM*4],mod[DIM*4];
vector<ll> G[DIM];
void dfs(ll v){
    tin[v] = ++timer;
    mas[timer] = v;
    for(ll to:G[v]){
        if (tin[to]==0)dfs(to);
    }
    tout[v] = timer;
}
void push(ll t){
    if (mod[t]==0)return;
    mod[t] = 0;
    mod[t*2+1] = 1;
    mod[t*2+2] = 1;
    T[t*2+1] = T[t];
    T[t*2+2] = T[t];
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = col[mas[tl]];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = T[t*2+1]|T[t*2+2];
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || tr<l)return;
    if (l<=tl && tr<=r){
        mod[t] = 1;
        T[t] = val;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = T[t*2+1]|T[t*2+2];
}
ll query(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return 0;
    if (l<=tl && tr<=r)return T[t];
    push(t);
    ll tm = (tl+tr)/2;
    return query(t*2+1,tl,tm,l,r)|query(t*2+2,tm+1,tr,l,r);
}
ll popcount(ll mask){
    ll cnt = 0;
    while(mask>0){
        cnt+=mask&1;
        mask/=2;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n){
        ll x; cin>>x;
        col[i]^=po(x-1);
    }
    forn(i,n-1){
        ll x,y; cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1);
    buildtree(0,1,n);
    forn(q,m){
        ll type; cin>>type;
        if (type==1){
            ll v,c; cin>>v>>c;
            c = po(c-1);
            update(0,1,n,tin[v],tout[v],c);
        }
        else{
            ll v; cin>>v;
            cout<<popcount(query(0,1,n,tin[v],tout[v]))<<endl;
        }
    }
    return 0;

}