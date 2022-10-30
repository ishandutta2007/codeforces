#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll sz[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    sz[v] = 1;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
vector<ll> cent;
ll n;
void solve(ll v,ll par){
    sz[v] = 1;
    ll mx = 0;
    for(ll to:G[v]){
        sz[v]+=sz[to];
        mx = max(mx,sz[to]);
    }
    if (mx<=(n-1)/2+(n-1)%2)
        cent.push_back(v);
    for(ll to:G[v]){
        if (to==par)continue;
        ll b1 = sz[v];
        ll b2 = sz[to];
        sz[v]-=sz[to];
        solve(to,v);
        sz[v] = b1;
        sz[to] = b2;
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n;
        for(ll i = 1;i<n;++i){
            ll u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1);
        solve(1,1);
        if(cent.size()<2){
            ll v = 0;
            for(ll to:G[cent[0]]){
                v = to;
                break;
            }
            cout<<v<<' '<<cent[0]<<endl;
            cout<<v<<' '<<cent[0]<<endl;
        }
        else{
            ll a = cent[0],b = cent[1];
            ll v = 0;
            for(ll to:G[b]){
                if (to!=a){
                    v = to;
                    break;
                }
            }

            cout<<b<<' '<<v<<endl;
            cout<<a<<' '<<v<<endl;
        }
        for(ll i = 1;i<=n;++i)G[i].clear();
        cent.clear();
    }
    return 0;
}