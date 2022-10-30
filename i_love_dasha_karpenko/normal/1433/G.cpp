#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 1E3+7;
const ll INF = 1E18;
vector<pair<ll,ll> > G[DIM];
pair<ll,ll> A[DIM];
ll dist[DIM][DIM],vis[DIM];
void deikjstra(ll v){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> > ,greater<pair<ll,ll> > > Q;
    Q.push({0,v});
    dist[v][v] = 0;
    memset(vis,0,sizeof(vis));

    while(!Q.empty()){
        ll t = Q.top().second;
        Q.pop();
        if (vis[t])continue;
        vis[t] = 1;
        for(auto to:G[t]){
            if (dist[v][to.first]==-1 || dist[v][to.first]>dist[v][t]+to.second){
                dist[v][to.first] = dist[v][t]+to.second;
                Q.push({dist[v][to.first],to.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll> > edges;
    for(ll i = 1;i<=m;++i){
        ll x,y,w;
        cin>>x>>y>>w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
        edges.push_back({x,y});
    }
    for(ll i = 1;i<=k;++i){
        cin>>A[i].first>>A[i].second;
    }
    memset(dist,-1,sizeof(dist));
    for(ll i = 1;i<=n;++i){
        deikjstra(i);
    }

    ll ans = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = i+1;j<=n;++j){
            if (dist[i][j]!=dist[j][i]){
                cout<<"F\n";
                return 0;
            }
        }
    }
    for(ll i = 1;i<=k;++i){
        ans+=dist[A[i].first][A[i].second];
    }
    for(auto to:edges){
        ll res = 0;
        for(ll i = 1;i<=k;++i){
            ll r = min(dist[A[i].first][to.first],dist[to.second][A[i].first])+min(dist[to.first][A[i].second],dist[to.second][A[i].second]);
            res +=min(r,dist[A[i].first][A[i].second]);
        }
        ans = min(ans,res);
    }
    cout<<ans<<endl;

    return 0;

}