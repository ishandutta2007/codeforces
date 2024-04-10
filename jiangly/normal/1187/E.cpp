// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<bool>vis(n);
    vector<int>sz(n),mx(n);
    vector<long long>sum(n);
    int root,tot;
    long long s;
    function<void(int,int)> getsize=[&](int u,int f){
        sz[u]=1;
        mx[u]=0;
        for(auto v:adj[u]){
            if(v==f||vis[v]){
                continue;
            }
            getsize(v,u);
            sz[u]+=sz[v];
            mx[u]=max(mx[u],sz[v]);
        }
    };
    function<void(int,int)> getroot=[&](int u,int f){
        if(max(mx[u],tot-sz[u])<max(mx[root],tot-sz[root])){
            root=u;
        }
        for(auto v:adj[u]){
            if(v==f||vis[v]){
                continue;
            }
            getroot(v,u);
        }
    };
    function<void(int,int,int)> dfs1=[&](int u,int f,int d){
        ++tot;
        s+=d;
        for(auto v:adj[u]){
            if(v==f||vis[v]){
                continue;
            }
            dfs1(v,u,d+1);
        }
    };
    function<void(int,int,int,int)> dfs2=[&](int u,int f,int d,int k){
        sum[u]+=k*(s+(long long)d*tot);
        for(auto v:adj[u]){
            if(v==f||vis[v]){
                continue;
            }
            dfs2(v,u,d+1,k);
        }
    };
    function<void(int)> solve=[&](int u){
        getsize(u,-1);
        root=u;
        tot=sz[u];
        getroot(u,-1);
        int r=root;
        vis[r]=true;
        tot=0;
        s=0;
        dfs1(r,-1,0);
        dfs2(r,-1,0,1);
        for(auto v:adj[r]){
            if(vis[v]){
                continue;
            }
            tot=0;
            s=0;
            dfs1(v,r,1);
            dfs2(v,r,1,-1);
            solve(v);
        }
    };
    solve(0);
    long long ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans,sum[i]);
    }
    ans+=n;
    cout<<ans<<endl;
    return 0;
}