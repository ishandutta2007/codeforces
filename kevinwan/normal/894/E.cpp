#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
const int mn=1e6+10;
vector<int>g[mn],w[mn],gg[mn],ww[mn];
int o[mn],l[mn],scc[mn];
stack<int>s;
bool vis[mn],ins[mn];
int sct,ct;
void dfs(int x){
    vis[x]=ins[x]=1;
    o[x]=l[x]=ct++;
    s.push(x);
    for(int y:g[x]){
        if(ins[y])l[x]=min(l[x],o[y]);
        else if(!vis[y])dfs(y),l[x]=min(l[x],l[y]);
    }
    if(o[x]==l[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[x]=sct++,ins[x]=0,s.pop();
    }
}
ll hail(int x){
    ll cur=0;
    for(ll i=1<<14;i;i>>=1){
        if((cur+i)*(cur+i-1)/2<=x)cur+=i;
    }
    return x*cur-(cur+1)*cur*(cur-1)/6;
}
ll v[mn],dp[mn];
void dfs2(int x){
    vis[x]=1;
    for(int i=0;i<gg[x].size();i++){
        int y=gg[x][i],d=ww[x][i];
        if(!vis[y])dfs2(y);
        dp[x]=max(dp[x],dp[y]+d);
    }
    dp[x]+=v[x];
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        w[a].push_back(c);
    }
    int s;
    scanf("%d",&s);
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            int k=g[i][j],d=w[i][j];
            if(scc[i]==scc[k])v[scc[i]]+=hail(d);
            else{
                gg[scc[i]].push_back(scc[k]);
                ww[scc[i]].push_back(d);
            }
        }
    }
    memset(vis,0,sizeof(vis));
    dfs2(scc[s]);
    printf("%lld",dp[scc[s]]);
}