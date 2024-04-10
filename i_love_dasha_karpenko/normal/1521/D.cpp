//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E6+7;
vector<ll> G[DIM];
ll fr[DIM],st[DIM],dt[DIM];
vector<pair<ll,ll> > V;
vector<pair<ll,ll> > edges;
void dfs(ll v,ll par){
    fr[v] = 1;
    st[v] = v;
    for(ll to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
    }
    ll last = -1;
    for(ll to:G[v]){
        if (to==par)
            continue;
        if (fr[to] && fr[v]){
            if (last==-1)
                last = to;
            else{
                V.push_back({st[last],st[to]});
                dt[to] = dt[last] = 1;
                last = -1;
                fr[v] = 0;
            }
        }
    }

    if (fr[v]==1 && last!=-1){
        st[v] = st[last];
        dt[last] = 1;
    }

    for(ll to:G[v]){
        if (dt[to] || to==par)
            continue;
        if (fr[to]){
            V.push_back({st[to],to});
        }
        edges.push_back({to,v});
    }
}
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    if (fr[1]){
        V.push_back({1,st[1]});
    }
    vector<pair<ll,ll> > need;
    ll last = 0;
    for(auto to:V){
        if (last!=0){
            need.push_back({last,to.first});
        }
        last = to.second;
    }
    cout<<edges.size()<<endl;
    while(!edges.empty()){
        pair<ll,ll> e1 = edges.back(),e2 = need.back();
        edges.pop_back(); need.pop_back();
        cout<<e1.first<<' '<<e1.second<<' '<<e2.first<<' '<<e2.second<<endl;
    }
    V.clear();
    for(ll i = 1;i<=n;++i){
        G[i].clear();
        fr[i] = st[i] = dt[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}