#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100000 +7;
const ll INF = 10E17+7;
ll n,m,k,q,D[DIM],dsu_size[DIM];
int P[DIM];
vector<pair<ll,int> > G[DIM];
priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
struct node{
    int v1,v2; ll w;
};
const bool operator<(const node &a,const node &b){
    return a.w<b.w;
}
int F(int x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
ll ans[DIM*3];
vector<pair<int,int> > V[DIM];
inline int Check(int x,int y){
    return F(x)==F(y);
}
void unite(int x,int y,ll w){
    x = F(x);
    y = F(y);
    if (V[x].size()>V[y].size())swap(x,y);
    for(;!V[x].empty();){
        pp to = V[x].back();
        V[x].pop_back();
        if (Check(y,to.fi))ans[to.sc] = w;
        else V[y].pb(to);
    }
    V[x].shrink_to_fit();
    P[x] = y;
    dsu_size[y]+=dsu_size[x];
}
vector<node> edges;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m>>k>>q;

    forn(i,m){
        ll x,y,w;
        cin>>x>>y>>w;
        G[x].pb({y,w});
        G[y].pb({x,w});
        edges.pb(node{x,y,w});
    }
    forn(i,k)Q.push({0,i});
    for(ll i = k+1;i<=n;i++)D[i] = INF;
    while(!Q.empty()){
        pp te = Q.top();
        ll v = te.sc;
        Q.pop();
        if (te.fi!=D[v])continue;
        for(pp to:G[v]){
            if (D[to.fi]>D[v]+to.sc){
                D[to.fi] = D[v]+to.sc;
                Q.push({D[to.fi],to.fi});
            }
        }
    }
    for(ll i = 0;i<edges.size();i++){
        edges[i].w += D[edges[i].v1]+D[edges[i].v2];
    }
    sort(edges.begin(),edges.end());
    forn(i,q){
        ll x,y; cin>>x>>y;
        V[x].pb({y,i});
        V[y].pb({x,i});
    }
    //node t;
    forn(i,n){
        P[i] = i;
        dsu_size[i] = 1;
    }
    //for(node to:edges)cout<<to.v1<<' '<<to.v2<<' '<<to.w<<endl;
    for(node t:edges){
        //t = edges.back();
        //edges.pop_back();
        if (F(t.v1)==F(t.v2))continue;
        unite(t.v1,t.v2,t.w);
    }
    forn(i,q)cout<<ans[i]<<endl;
    return 0;
}