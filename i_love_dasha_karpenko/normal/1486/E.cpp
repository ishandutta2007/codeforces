#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E5+7;
const ll MULT = 57;
const ll INF = 1E18;
ll dist[DIM][MULT],D[DIM];
vector<pair<ll,ll> > G[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        ll v,u,w;
        cin>>v>>u>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    memset(dist,-1,sizeof(dist));
    memset(D,-1,sizeof(D));
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > Q;
    Q.push({0,1});
    D[1] = 0;
    while(!Q.empty()){
        ll v = Q.top().second;
        ll dd = Q.top().first;
        Q.pop();
        if (dd>D[v])continue;
        for(auto to:G[v]){
            if (dist[to.first][to.second]==-1 || dist[to.first][to.second]>D[v]+to.second){
                dist[to.first][to.second] = D[v];
                for(auto tt:G[to.first]){
                    if (D[tt.first]==-1 || D[tt.first]>dist[to.first][to.second]+(tt.second+to.second)*(tt.second+to.second)){
                        D[tt.first] = dist[to.first][to.second]+(tt.second+to.second)*(tt.second+to.second);
                        Q.push({D[tt.first],tt.first});
                    }
                }
            }
        }
    }
    for(ll i = 1;i<=n;++i)
        cout<<D[i]<<' ';
    cout<<endl;
    return 0;
}