#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e6+10;
int anc[mn][20];
vector<int>g[mn];
int o[mn],ct,sct,val[mn],scc[mn],l[mn];
bool vis[mn],ins[mn];
stack<int>s;
void dfs(int x){
    for(int y:g[x])dfs(y),anc[y][0]=x;
}
int go(int a,int b){
    for(int i=0;b;i++,b>>=1)if(b&1)a=anc[a][i];
    return a;
}
void tj(int x){
    vis[x]=ins[x]=1;
    s.push(x);
    o[x]=l[x]=ct++;
    for(int y:g[x]){
        if(!vis[y])tj(y),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(o[x]==l[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[x]=sct++,ins[x]=0,s.pop();
    }
}

int vv[mn],dp[mn];
void dfs2(int x){
    vis[x]=1;
    dp[x]=vv[x];
    for(int y:g[x]){
        if(!vis[y])dfs2(y);
        dp[x]=max(dp[x],dp[y]+vv[x]);
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    anc[1][0]=1;
    dfs(1);
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    for(int i=1;i<=n;i++)if(g[i].empty()){
        val[i]=1;
        g[i].push_back(go(i,k));
    }
    tj(1);
    for(int i=1;i<=n;i++)g[i].clear(),g[i].reserve(0);
    for(int i=2;i<=n;i++)if(scc[anc[i][0]]!=scc[i])g[scc[anc[i][0]]].push_back(scc[i]);
    for(int i=1;i<=n;i++)vv[scc[i]]+=val[i];
    memset(vis,0,sizeof(vis));
    dfs2(scc[1]);
    printf("%d",dp[scc[1]]);
}