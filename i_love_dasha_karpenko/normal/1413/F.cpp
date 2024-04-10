#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

const ll DIM = 5E5+7;
const ll INF = 1E18;
struct node{
    ll first,second,num;
};
vector<node > G[DIM];
ll dist[DIM];
void dfs(ll v,ll par){
    for(auto to:G[v]){
        if (to.first==par)continue;
        dist[to.first] = dist[v]+1;
        dfs(to.first,v);
    }
}
ll depth[2][DIM],col[2][DIM],tin[2][DIM],tout[2][DIM],vt[2][DIM],timer = 0,C[2][DIM];
void solve(ll v,ll par,ll type){
    tin[type][v] = ++timer;
    vt[type][timer] = v;
    for(auto to:G[v]){
        if (to.first==par)continue;
        C[type][to.num] = to.first;
        col[type][to.first] = col[type][v]^to.second;
        depth[type][to.first] = depth[type][v]+1;
        solve(to.first,v,type);
    }
    tout[type][v] = timer;
}
pair<ll,ll> T[2][DIM*4];
ll mod[2][DIM*4];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        if (col[0][vt[0][tl]]==0){
            T[0][t] = {depth[0][vt[0][tl]],-INF};
        }
        else{
            T[0][t] = {-INF,depth[0][vt[0][tl]]};
        }
        if (col[1][vt[1][tl]]==0){
            T[1][t] = {depth[1][vt[1][tl]],-INF};
        }
        else{
            T[1][t] = {-INF,depth[1][vt[1][tl]]};
        }
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    for(ll i = 0;i<2;++i){
        T[i][t].first = max(T[i][t*2+1].first,T[i][t*2+2].first);
        T[i][t].second = max(T[i][t*2+1].second,T[i][t*2+2].second);
    }
}
void push(ll t){
    for(ll i = 0;i<2;++i){
        if (mod[i][t]==0)continue;
        swap(T[i][t*2+1].first,T[i][t*2+1].second);
        swap(T[i][t*2+2].first,T[i][t*2+2].second);
        mod[i][t*2+1]^=1;
        mod[i][t*2+2]^=1;
        mod[i][t] = 0;
    }
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll type){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        swap(T[type][t].first,T[type][t].second);
        mod[type][t]^=1;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,type);
    update(t*2+2,tm+1,tr,l,r,type);
    T[type][t].first = max(T[type][t*2+1].first,T[type][t*2+2].first);
    T[type][t].second = max(T[type][t*2+1].second,T[type][t*2+2].second);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<n;++i){
        ll u,v,t;
        cin>>u>>v>>t;
        G[u].push_back({v,t,i});
        G[v].push_back({u,t,i});
    }
    dfs(1,0);
    ll mx = 0;
    for(ll i = 1;i<=n;++i){
        if (dist[i]>dist[mx])mx = i;
    }
    memset(dist,0,sizeof(dist));
    dfs(mx,mx);
    ll a = mx,b = 0;
    for(ll i = 1;i<=n;++i){
        if (dist[i]>dist[b])b = i;
    }
    solve(a,a,0);
    timer = 0;
    solve(b,b,1);
    buildtree(0,1,n);
    ll m;
    cin>>m;
    while(m--){
        ll q;
        cin>>q;
        ll v1 = C[0][q],v2 = C[1][q];
        update(0,1,n,tin[0][v1],tout[0][v1],0);
        update(0,1,n,tin[1][v2],tout[1][v2],1);
        cout<<max(T[0][0].first,T[1][0].first)<<endl;
    }
    return 0;

}