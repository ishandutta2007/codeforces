//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6+7;
vector<int> G[N],R[N];
vector<int> topsort;
int vis[N],cmp[N],ptr = 0;
void dfs(int v){
    vis[v] = 1;
    for(int to:G[v]){
        if (vis[to])
            continue;
        dfs(to);
    }
    topsort.push_back(v);
}
void cond(int v){
    cmp[v] = ptr;
    for(int to:R[v]){
        if (!cmp[to])
            cond(to);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        if (u==v)
            continue;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    for(int i = 1;i<=n;++i){
        if (!vis[i])
            dfs(i);
    }
    reverse(topsort.begin(),topsort.end());
    for(int v:topsort){
        if (!cmp[v]){
            ++ptr;
            cond(v);
        }
    }

    vector<int> ans1,ans2;
    for(int i = 1;i<=n;++i){
        if(cmp[i]!=ptr){
            ans2.push_back(i);
        }
        else
            ans1.push_back(i);

    }
    if (ptr==1){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        cout<<ans1.size()<<' '<<ans2.size()<<'\n';
        for(int to:ans1)
            cout<<to<<' ';
        cout<<'\n';
        for(int to:ans2)
            cout<<to<<' ';
        cout<<'\n';
    }
    for(int i = 1;i<=n;++i){
        G[i].clear();
        R[i].clear();
        cmp[i] = vis[i] = 0;
    }
    ptr = 0;
    topsort.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}