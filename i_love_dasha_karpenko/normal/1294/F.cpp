#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
const ll MAXN = 10E8+7;
vector<ll> G[DIM];
ll dist[DIM],P[DIM],need[DIM],vis[DIM];
void dfs(ll v,ll d = 0){
    dist[v] = d;
    for(ll to:G[v]){
        if (dist[to]==-1){
            P[to] = v;
            dfs(to,d+1);
        }
    }
}
void dfs1(ll v,ll d = 0){
    dist[v] = d;
    for(ll to:G[v]){
        if (need[to]!=0 && dist[to]==-1){
            P[to] = v;
            dfs(to,d+1);
        }
    }
}
pp fleks(ll v,ll par){
    vis[v] = 1;
    pp depth = pp{0ll,v};
    for(ll to:G[v]){
        if (need[to]==0 && to!=par){
            pp got = max(depth,fleks(to,v));
            if (got.fi>depth.fi){
                depth = got;
            }
        }
    }
    depth.fi++;
    return depth;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    memset(dist,-1,sizeof(dist));
    dfs(1);
    ll st = 1;
    forn(i,n){
        if (dist[i]>dist[st])st = i;
    }
    memset(dist,-1,sizeof(dist));
    memset(P,-1,sizeof(P));
    dfs(st);
    ll en = 1;
    forn(i,n){
        if (dist[i]>dist[en])en = i;
    }
    ll x = en;
    while(x!=st){
        need[x] = 1;
        x = P[x];
    }
    need[x] = 1;
//    memset(vis,-1,sizeof(vis));
    ll res = -1,c = -1;
    forn(i,n){
        if (need[i]==1){
            for(ll to:G[i]){
                if (vis[to]==0 && need[to]==0){
                    pp val = fleks(to,-1);
                    if (val.fi>res){
                        res = val.fi;
                        c = val.sc;
                    }
                }
            }
        }
    }
    if (c==-1){
        forn(i,n){
            if(i!=st && i!=en){c = i;break;}
        }
    }
    cout<<max(0ll,res)+dist[en]<<endl;
    cout<<st<<' '<<en<<' '<<c<<endl;
    return 0;
}