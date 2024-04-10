#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    vector<vector<int>> g(n);
    vector<int> vis(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u].push_back(v);
        edges[i]={u,v};
    }
    function<bool(int,int)> dfs=[&](int u,int r){
        vis[u]=1;
        for(int v:g[u]){
            if(vis[v]==1||vis[v]==0&&dfs(v,r)){
                return true;
            }
        }
        vis[u]=2;
        return false;
    };
    bool ok=true;
    for(int i=0;i<n;++i){
        if(vis[i]==0&&dfs(i,i)){
            ok=false;
            break;
        }
    }
    if(ok){
        cout<<1<<endl;
        for(int i=0;i<m;++i){
            cout<<1<<' ';
        }
        cout<<endl;
    }else{
        cout<<2<<endl;
        for(int i=0;i<m;++i){
            if(edges[i].first<edges[i].second){
                cout<<1<<' ';
            }else{
                cout<<2<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}