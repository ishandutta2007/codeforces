#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
int n,l,dep[mn],anc[mn][17],u[mn];
ll s,w[mn],wd[mn],wu[mn];
vector<int>g[mn];
void dfs1(int x,int p){
    if(w[x]>s){
        printf("-1");
        exit(0);
    }
    wd[x]=wd[p]+w[x];
    dep[x]=dep[p]+1;
    anc[x][0]=p;
    for(int y:g[x])if(y!=p){
        dfs1(y,x);
    }
}
int ans=0;
int go(int x,int rl,ll rs){
    int u=x;
    for(int i=16;i>=0;i--){
        if(dep[u]<1<<i)continue;
        if(wd[x]-wd[anc[u][i]]<=rs)u=anc[u][i];
    }
    return min(rl,dep[x]-dep[u]);
}
void dfs2(int x,int p){
    int bes=-1,besv=0;
    for(int y:g[x])if(y!=p){
        dfs2(y,x);
        int pro=go(x,l-u[y],s-wu[y]);
        if(pro>besv)besv=pro,bes=y;
    }
    if(bes==-1)ans++,u[x]=1,wu[x]=w[x];
    else u[x]=u[bes]+1,wu[x]=wu[bes]+w[x];
}
int main(){
   scanf("%d%d%lld",&n,&l,&s);
   for(int i=1;i<=n;i++)scanf("%lld",w+i);
   for(int i=2;i<=n;i++){
       int x;
        scanf("%d",&x);
        g[x].push_back(i);
   }
   dfs1(1,0);
   for(int i=1;i<17;i++)for(int j=0;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
   dfs2(1,0);
   printf("%d",ans);
}