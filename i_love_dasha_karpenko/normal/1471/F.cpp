#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;


ll vis[DIM],dev[DIM],flag = 0;
vector<ll> G[DIM];
void dfs(ll v){
    dev[v] = 1;
    for(ll to:G[v]){
        if (vis[to]!=0){
            if (vis[to]==1 && vis[v]==1)flag = 1;
        }
        if (dev[to])continue;
        if (vis[to]!=0){
            dfs(to);
            continue;
        }
        if (vis[v]==-1){
            vis[to] = 1;
            for(ll tt:G[to]){
                vis[tt] = -1;
            }
            dfs(to);
        }
        else{
            vis[to] = -1;
            dfs(to);
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i = 1;i<=m;++i){
            ll u,v;
            cin>>u>>v;

            G[u].push_back(v);
            G[v].push_back(u);

        }
        vis[1] = 1;
        for(ll to:G[1])vis[to] = -1;
        flag = 0;
        dfs(1);
        vector<ll> ans;
        for(ll i = 1;i<=n;++i){
            if (vis[i]==0)flag=1;
            if(vis[i]==1)ans.push_back(i);
        }
        if (flag==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<ans.size()<<endl;
            for(ll to:ans)cout<<to<<' ';
            cout<<endl;
        }
        for(ll i = 1;i<=n;++i){
            G[i].clear();
            vis[i] = dev[i] = 0;
        }

    }

    return 0;
}