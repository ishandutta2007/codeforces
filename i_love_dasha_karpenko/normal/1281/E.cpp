#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 2*10E4+7;
const ll INF = 10E18+173;
const ll MOD = 10E8+7;
ll comp[DIM],res = 0,cnt = 0,n;
vector<pp> G[DIM];
void dfs(ll v,ll par){
    comp[v] = 1;
    for(pp r:G[v]){
        ll to = r.fi,w = r.sc;
        if (to==par)continue;
        dfs(to,v);
        if (comp[to]%2!=0)res+=w;
        comp[v]+=comp[to];
    }
}
void rfs(ll v,ll par){
    for(pp r:G[v]){
        ll to = r.fi,w = r.sc;
        if (to==par)continue;
        rfs(to,v);
        cnt+=min(2*n-comp[to],comp[to])*w;
    }
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        cin>>n;
        forn(i,2*n)G[i].clear();
        cnt = 0; res = 0;
        forn(i,2*n-1){
            ll x,y,z; cin>>x>>y>>z;
            G[x].pb({y,z});
            G[y].pb({x,z});
        }
        dfs(1,-1);
        rfs(1,-1);
        cout<<res<<' '<<cnt<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3