//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E18;
vector<pair<ll,ll> > G[DIM];
ll dist1[DIM],dist2[DIM],dist3[DIM],dist4[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(ll i = 1;i<=n;++i){
        dist3[i] = dist2[i] = dist4[i] = INF;
    }
    memset(dist1,-1,sizeof(dist1));
    dist1[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > Q;
    Q.push({0,1});
    while(!Q.empty()){
        ll dd = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dd>dist1[v])continue;
        for(auto to:G[v]){
            if (dist1[to.first]==-1 || dist1[to.first]>dist1[v]+to.second){
                dist1[to.first] = dist1[v]+to.second;
                Q.push({dist1[to.first],to.first});
            }
            dist2[to.first] = min(dist2[to.first],dist1[v]+to.second*2);
            dist3[to.first] = min(dist3[to.first],dist1[v]);
            dist4[to.first] = min(dist4[to.first],dist1[v]+to.second);
        }
    }
    for(ll i = 1;i<=n;++i){
        if (dist2[i]==INF)continue;
        Q.push({dist2[i],i});
    }
    while(!Q.empty()){
        ll dd = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dd>dist2[v])continue;
        for(auto to:G[v]){
            if (dist2[to.first]>dist2[v]+to.second){
                dist2[to.first] = dist2[v]+to.second;
                Q.push({dist2[to.first],to.first});
            }
            dist4[to.first] = min(dist4[to.first],dist2[v]);
        }
    }
    for(ll i = 1;i<=n;++i){
        if (dist3[i]==INF)continue;
        Q.push({dist3[i],i});
    }
    while(!Q.empty()){
        ll dd = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dd>dist3[v])continue;
        for(auto to:G[v]){
            if (dist3[to.first]>dist3[v]+to.second){
                dist3[to.first] = dist3[v]+to.second;
                Q.push({dist3[to.first],to.first});
            }
            dist4[to.first] = min(dist4[to.first],dist3[v]+to.second*2);
        }
    }
    for(ll i = 1;i<=n;++i){
        if (dist4[i]==INF)continue;
        Q.push({dist4[i],i});
    }
    while(!Q.empty()){
        ll dd = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dd>dist4[v])continue;
        for(auto to:G[v]){
            if (dist4[to.first]>dist4[v]+to.second){
                dist4[to.first] = dist4[v]+to.second;
                Q.push({dist4[to.first],to.first});
            }
        }
    }
    for(ll i = 2;i<=n;++i)cout<<dist4[i]<<' ';
    cout<<endl;
    return 0;
}