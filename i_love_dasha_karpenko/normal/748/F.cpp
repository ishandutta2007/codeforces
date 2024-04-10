//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

const int N = 2E5+7;
vector<int> G[N];
int sz[N],vis[N],n,k;
void calc(int v,int par){
    sz[v] = vis[v];
    for(int to:G[v]){
        if (to==par)
            continue;
        calc(to,v);
        sz[v]+=sz[to];
    }
}
int fnd(int v,int par){
    for(int to:G[v]){
        if (to==par)
            continue;
        if (sz[to]>k)
            return fnd(to,v);
    }
    return v;
}
int ptr = 0;
vector<int> V[N];
void dfs(int v,int par){
    if (vis[v])
        V[ptr].push_back(v);
    for(int to:G[v]){
        if (to!=par)
            dfs(to,v);
    }
}
void solve(){
    cin>>n>>k;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i<=k*2;++i){
        int x;
        cin>>x;
        vis[x] = 1;
    }
    calc(1,1);
    int cent = fnd(1,1);
    priority_queue<pair<int,int> > Q;
    for(auto to:G[cent]){
        ++ptr;
        dfs(to,cent);
        if (!V[ptr].empty())
            Q.push({V[ptr].size(),ptr});
        else --ptr;
    }
    if (vis[cent]){
        V[++ptr].push_back(cent);
        Q.push({1,ptr});
    }
    cout<<1<<endl<<cent<<endl;
    while(!Q.empty()){
        int a = Q.top().second; Q.pop();
        int b = Q.top().second; Q.pop();
        cout<<V[a].back()<<' '<<V[b].back()<<' '<<cent<<endl;
        V[a].pop_back();
        V[b].pop_back();
        if (!V[a].empty())
            Q.push({V[a].size(),a});
        if (!V[b].empty())
            Q.push({V[b].size(),b});
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}