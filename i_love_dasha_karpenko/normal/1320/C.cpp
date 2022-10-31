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
const ll DIM = 2*10E4+7;
const ll INF = 10E16;
const ll MAXN = 10E5+7;
ll n,m,p,T[MAXN*4],M[MAXN*4],W[MAXN],tt[MAXN];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = -W[tl];
        M[t] = 0;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = max(T[t*2+1],T[t*2+2]);
}


struct node{
    ll fi,sc,cost;
};
bool mc(node &a,node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
node A[DIM];
void push(ll t){
    T[t*2+1]+=M[t];
    T[t*2+2]+=M[t];
    M[t*2+1]+=M[t];
    M[t*2+2]+=M[t];
    M[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll delta){
    if (l>tr || tl>r)return;
    if (l<=tl && tr<=r){
        T[t]+=delta;
        M[t]+=delta;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,delta);
    update(t*2+2,tm+1,tr,l,r,delta);
    T[t] = max(T[t*2+1],T[t*2+2]);
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    cin>>n>>m>>p;
    forn(i,MAXN-1){
        W[i] = INF;
        tt[i] = INF;
    }
    ll res = -INF;
    forn(i,n){
        ll x,cx;
        cin>>x>>cx;
        tt[x] = min(tt[x],cx);
        res = max(res,-cx);
    }
    ll r1 = -INF;
    for(ll i = MAXN-2;i>0;i--){
        tt[i] = min(tt[i+1],tt[i]);
    }
    forn(j,m){
        ll x,cx;
        cin>>x>>cx;
        W[x] = min(W[x],cx);
        r1 = max(r1,-cx);
    }
    res+=r1;
    ll ts = MAXN-3;
    buildtree(0,1,ts);
    forn(i,p){
        cin>>A[i].fi>>A[i].sc>>A[i].cost;
    }
    sort(A+1,A+1+p,mc);


    forn(i,p){
        update(0,1,ts,A[i].sc+1,ts,A[i].cost);
        ll cost = -tt[A[i].fi+1];
        cost+=T[0];
        res = max(res,cost);
    }
    cout<<res<<endl;
    return 0;
}