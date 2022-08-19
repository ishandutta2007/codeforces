// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int MAX_N=200005;
int n,m;
vector<pair<int,int>> g[MAX_N];
int fa[MAX_N];
LL ans[MAX_N];
int find(int x){
    while(fa[x]>0&&fa[fa[x]]>0){
        fa[x]=fa[fa[x]];
        x=fa[x];
    }
    return fa[x]<0?x:fa[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        fa[i]=-1;
    }
    for(int i=1;i<=n-1;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[w].emplace_back(u,v);
    }
    for(int i=1;i<=200000;++i){
        ans[i]=ans[i-1];
        for(auto [u,v]:g[i]){
            u=find(u);
            v=find(v);
            ans[i]+=1ll*fa[u]*fa[v];
            if(fa[u]>fa[v]){
                swap(u,v);
            }
            fa[u]+=fa[v];
            fa[v]=u;
        }
    }
    for(int i=1;i<=m;++i){
        int q;
        cin>>q;
        cout<<ans[q];
        if(i<m){
            cout<<' ';
        }
    }
    cout<<endl;
    return 0;
}