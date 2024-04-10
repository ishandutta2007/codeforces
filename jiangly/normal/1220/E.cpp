#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct Edge{
    int to;
    bool is_cut;
    Edge(int to):to(to),is_cut(false){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> w(n);
    vector<int> dfn(n,-1);
    vector<int> low(n,-1);
    vector<int> belong(n);
    vector<int> sz;
    vector<LL> sum;
    vector<bool> vis(n);
    vector<Edge> edges;
    vector<vector<int>> g(n);
    for(int i=0;i<n;++i){
        cin>>w[i];
    }
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u].push_back(edges.size());
        edges.emplace_back(v);
        g[v].push_back(edges.size());
        edges.emplace_back(u);
    }
    int s;
    cin>>s;
    --s;
    int cnt=0;
    function<void(int,int)> tarjan=[&](int u,int p){
        dfn[u]=low[u]=cnt++;
        for(int i:g[u]){
            Edge &e=edges[i];
            if(dfn[e.to]==-1){
                tarjan(e.to,u);
                low[u]=min(low[u],low[e.to]);
                if(low[e.to]>dfn[u]){
                    edges[i].is_cut=edges[i^1].is_cut=true;
                }
            }else if(e.to!=p){
                low[u]=min(low[u],dfn[e.to]);
            }
        }
    };
    tarjan(s,-1);
    for(int i=0;i<n;++i){
        if(!vis[i]){
            queue<int> que;
            que.push(i);
            vis[i]=true;
            LL s=0;
            int x=0;
            while(!que.empty()){
                int u=que.front();
                que.pop();
                s+=w[u];
                ++x;
                belong[u]=sum.size();
                for(int i:g[u]){
                    Edge &e=edges[i];
                    if(!e.is_cut&&!vis[e.to]){
                        vis[e.to]=true;
                        que.push(e.to);
                    }
                }
            }
            sum.push_back(s);
            sz.push_back(x);
        }
    }
    vector<vector<int>> g0(sum.size());
    for(int i=0;i<n;++i){
        for(int x:g[i]){
            Edge &e=edges[x];
            if(e.is_cut){
                g0[belong[i]].push_back(belong[e.to]);
            }
        }
    }
    vector<vector<LL>> dp(sum.size(),vector<LL>(2));
    function<void(int,int)> dfs=[&](int u,int p){
        dp[u][0]=-1;
        if(sz[u]>1){
            dp[u][0]=sum[u];
        }
        dp[u][1]=sum[u];
        for(int v:g0[u]){
            if(v!=p){
                dfs(v,u);
                dp[u][1]=max(dp[u][1]+max(0ll,dp[v][0]),max(sum[u],dp[u][0])+dp[v][1]);
                if(dp[v][0]!=-1){
                    if(dp[u][0]==-1){
                        dp[u][0]=sum[u];
                    }
                    dp[u][0]+=dp[v][0];
                }
            }
        }
    };
    dfs(belong[s],-1);
    cout<<dp[belong[s]][1]<<endl;
    return 0;
}