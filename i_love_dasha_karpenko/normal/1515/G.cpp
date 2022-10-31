//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define gcd sdfds
const ll DIM = 2E5+7;
vector<pair<ll,ll> > G[DIM];
ll vis[DIM],cmp = 0;
vector<ll> V;
void dfs(ll v){
    vis[v] = 1;
    for(auto [to,l]:G[v]){
        if (l<0 || vis[to])
            continue;
        dfs(to);
    }
    V.push_back(v);
}
ll gcd[DIM],dist[DIM];
void solve(ll v){
    vis[v] = cmp;
    for(auto [to,l]:G[v]){
         l = -l;
         if (l<0 || (vis[to]!=0 && vis[v]!=vis[to]))
             continue;
         if (vis[to]){
             gcd[cmp] = __gcd(gcd[cmp],dist[v]-dist[to]+l);
         }
         else {
            dist[to] = dist[v]+l;
            solve(to);
         }
    }
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        ll a,b,l;
        cin>>a>>b>>l;
        G[a].push_back({b,l});
        G[b].push_back({a,-l});
    }
    for(ll i = 1;i<=n;++i)
        if (!vis[i])
            dfs(i);
    memset(vis,0,sizeof(vis));
    reverse(V.begin(),V.end());
    for(ll v:V){
        if (vis[v]==0){
            ++cmp;
            solve(v);
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll v,s,t;
        cin>>v>>s>>t;
        if ((t-s)%__gcd(t,gcd[vis[v]]))
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}