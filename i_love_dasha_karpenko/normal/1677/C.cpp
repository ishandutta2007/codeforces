#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
const int N = 1e5+7;
int u[N];
vector<int> G[N];
int vis[N],sz = 0;

void dfs(int v){
    vis[v] = 1;
    ++sz;
    for(int to:G[v]){
        if (!vis[to]){
            dfs(to);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>u[i];
    }
    for(int i = 1;i<=n;++i){
        int v;
        cin>>v;
        G[u[i]].push_back(v);
        G[v].push_back(u[i]);
    }
    int cnt = 0;
    for(int i = 1;i<=n;++i){
        if (!vis[i]){
            sz = 0;
            dfs(i);
            cnt += sz/2;
        }
    }
    ll res = 0;
    for(int i = n;i>n-cnt;i-=1){
        res+=i;
    }
    for(int i = 1;i<=cnt;i+=1){
        res-=i;
    }
    cout<<res*2<<endl;
    for(int i = 1;i<=n;++i){
        vis[i] = 0;
        G[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}