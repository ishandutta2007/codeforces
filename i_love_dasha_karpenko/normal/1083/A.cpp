#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 3*10E4 +7;
const ll INF = 10E17;
ll W[DIM];
ll inc[DIM];
vector<pp> G[DIM];
void dfs(ll v,ll par){
    inc[v] = W[v];
    for(pp to:G[v]){
        if (to.fi==par)continue;
        dfs(to.fi,v);
        if (inc[to.fi]>=to.sc){
            ll g = inc[to.fi]-to.sc;
            inc[v] = max(inc[v],g+W[v]);
        }
    }
}
ll res = 0;
void push(ll v,ll par,ll flow){
    set<pp> Q;
    for(pp to:G[v]){
        if (to.fi==par)continue;
        if (inc[to.fi]>=to.sc){
            ll g = inc[to.fi]-to.sc;
            Q.insert({g+W[v],to.fi});
        }
    }
    while(Q.size()>2)Q.erase({Q.begin()->fi,Q.begin()->sc});
    flow = max(flow+W[v],W[v]);

    for(pp to:G[v]){
        if (to.fi==par)continue;
        ll ff = flow;
        for(auto it = Q.rbegin();it!=Q.rend();it++){
            pp el = *it;
            if (el.sc==to.fi)continue;
            ff = max(ff,el.fi);
            break;
        }
        res = max(res,ff);
        push(to.fi,v,ff-to.sc);
    }
    res = max(res,flow);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>W[i];
    forn(i,n-1){
        ll x,y,l;
        cin>>x>>y>>l;
        G[x].pb({y,l});
        G[y].pb({x,l});
    }
    dfs(1,-1);
    push(1,-1,0);

    cout<<res<<endl;
    return 0;
}