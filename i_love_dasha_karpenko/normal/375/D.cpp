#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const ll DIM = 1E5+7;
const ll INF = 1E18;
struct node{
    ll fi,sc,th;
};
vector<ll> G[DIM];
ll col[DIM],tin[DIM],tout[DIM],timer = 0,pos[DIM];
void dfs(ll v,ll par){
    tin[v] = ++timer;
    pos[timer] = v;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
    }
    tout[v] = timer;
}
vector<node> Q[350];
bool mc(node a,node b){
    return tout[a.fi]<tout[b.fi];
}
ll cntcol[DIM],T[DIM],ans[DIM];

void incr(ll &ps){
    ll num = col[pos[ps+1]];

    cntcol[num]++;
    T[cntcol[num]]++;
    ps++;
}
void inc(ll &ps){
    ll num = col[pos[ps]];
    T[cntcol[num]]--;
    cntcol[num]--;
    ps++;
}
void dec(ll &ps){
    ll num = col[pos[ps-1]];
    cntcol[num]++;
    T[cntcol[num]]++;
    ps--;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,n){
        cin>>col[i];
    }
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,1);

    ll blsz = n/sqrt(n)+(n%ll(sqrt(n))!=0);
    ll blnum = sqrt(n);
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        Q[tin[x]/blsz].pb({x,y,i});
    }
    for(ll bl = 0;bl<350;++bl){
        memset(T,0,sizeof(T));
        memset(cntcol,0,sizeof(cntcol));
        sort(Q[bl].begin(),Q[bl].end(),mc);
        ll l = 1,r = 1;
        cntcol[col[pos[1]]]++;
        T[1]++;
        for(node to:Q[bl]){
            ll v = to.fi;
            while(r<tout[v])incr(r);
            while(l<tin[v])inc(l);
            while(l>tin[v])dec(l);
            ans[to.th] = T[to.sc];
            //vis[to.th] = 1;
        }
    }
    //forn(i,m)if (vis[i]==0)n/=0;
    forn(i,m)cout<<ans[i]<<endl;
    return 0;
}