#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=600010;
int From[maxn],Laxt[maxn],To[maxn<<2],Next[maxn<<2],cnt;
int low[maxn],dfn[maxn],times,q[maxn],head,scc_cnt,scc[maxn];
vector<int>G[maxn];
int dis[maxn],S,T,ans;
void add(int u,int v)
{
    Next[++cnt]=Laxt[u]; From[cnt]=u;
    Laxt[u]=cnt; To[cnt]=v;
}
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++times; 
    q[++head]=u;
    for(int i=Laxt[u];i;i=Next[i]){
        if(To[i]==fa) continue;
        if(!dfn[To[i]]) {
              tarjan(To[i],u);
              low[u]=min(low[u],low[To[i]]);
        }
        else low[u]=min(low[u],dfn[To[i]]);
    }
    if(low[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x=q[head--];
            scc[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
void dfs(int u,int f)
{
    dis[u]=dis[f]+1;
    for(int i=0;i<G[u].size();i++){
        if(G[u][i]!=f) dfs(G[u][i],u);
    }
}
int main()
{
    int N,M,u,v,i,j;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    tarjan(1,0);
    for(i=1;i<=N;i++){
        for(j=Laxt[i];j;j=Next[j]){
           if(scc[i]!=scc[To[j]])
             G[scc[i]].push_back(scc[To[j]]);
        }
    }
    dfs(1,0);
    for(i=1;i<=scc_cnt;i++) if(dis[i]>dis[S]) S=i;
    dfs(S,0);
    for(i=1;i<=scc_cnt;i++) ans=max(ans,dis[i]-1);
    printf("%d\n",ans);
    return 0;
}