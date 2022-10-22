#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1000018171;
const int mn=2e5+10;
int u[mn],v[mn],w[mn];
inline int h(int a,int b){return a^u[b]^v[b];}
vector<int>g[mn];
ll ds[mn],dt[mn],dp1[mn],dp2[mn];
bool vis[mn];
int s,t;
void dfs1(int x){
    vis[x]=1;
    for(int i:g[x]){
        int y=h(x,i);
        if(ds[y]!=ds[x]+w[i]||u[i]!=x)continue;
        if(!vis[y])dfs1(y);
        dp1[x]+=dp1[y];
        dp1[x]%=mod;
    }
}
void dfs2(int x){
    vis[x]=1;
    for(int i:g[x]){
        int y=h(x,i);
        if(dt[y]!=dt[x]+w[i]||v[i]!=x)continue;
        if(!vis[y])dfs2(y);
        dp2[x]+=dp2[y];
        dp2[x]%=mod;
    }
}
ll ans[mn];
int main(){
    int n,m;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++)scanf("%d%d%d",u+i,v+i,w+i),g[u[i]].push_back(i),g[v[i]].push_back(i);
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({0,s});
    memset(ds,0x3f,sizeof(ds));
    memset(dt,0x3f,sizeof(dt));
    while(pq.size()){
        ll d=pq.top().first,x=pq.top().second;
        pq.pop();
        if(ds[x]!=0x3f3f3f3f3f3f3f3f)continue;
        ds[x]=d;
        for(int i:g[x]){
            if(x!=u[i])continue;
            int y=h(x,i);
            pq.push({d+w[i],y});
        }
    }
    pq.push({0,t});
    while(pq.size()){
        ll d=pq.top().first,x=pq.top().second;
        pq.pop();
        if(dt[x]!=0x3f3f3f3f3f3f3f3f)continue;
        dt[x]=d;
        for(int i:g[x]){
            if(x!=v[i])continue;
            int y=h(x,i);
            pq.push({d+w[i],y});
        }
    }
    dp1[t]=dp2[s]=1;
    dfs1(s);
    memset(vis,0,sizeof(vis));
    dfs2(t);
    for(int i=0;i<m;i++){
        if(dp2[u[i]]*dp1[v[i]]%mod==dp1[s]&&ds[u[i]]+dt[v[i]]+w[i]==ds[t])ans[i]=-1;
    }
    for(int i=0;i<m;i++){
        if(ans[i]==-1)continue;
        ans[i]=w[i]-(ds[t]-ds[u[i]]-dt[v[i]]-1);
    }
    for(int i=0;i<m;i++){
        if(ans[i]==-1)printf("YES\n");
        else if(ans[i]>=w[i])printf("NO\n");
        else printf("CAN %lld\n",ans[i]);
    }
}