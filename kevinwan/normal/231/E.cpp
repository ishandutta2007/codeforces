#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
const ll mod=1e9+7;
vector<int>g[mn],gg[mn];
bool ins[mn],vis[mn];
int o[mn],l[mn],scc[mn];
stack<int>s;
int ct,sct;
void dfs1(int x,int p){
    ins[x]=vis[x]=1;
    o[x]=l[x]=ct++;
    s.push(x);
    for(int y:g[x])if(y!=p){
        if(!vis[y])dfs1(y,x),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(l[x]==o[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[x]=sct++,ins[x]=0,s.pop();
    }
}
int dep[mn],anc[mn][17],val[mn],vdep[mn];
void dfs2(int x,int p){
    anc[x][0]=p;
    for(int y:gg[x])if(y!=p)dep[y]=dep[x]+1,vdep[y]=vdep[x]+val[y],dfs2(y,x);
}
void go(int&a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
}
int lca(int a,int b){
    if(dep[a]>dep[b])go(a,dep[a]-dep[b]);
    else go(b,dep[b]-dep[a]);
    if(a==b)return a;
    for(int i=16;i>=0;i--)if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    return anc[a][0];
}
int dis(int a,int b){
    int l=lca(a,b);
    return vdep[a]+vdep[b]-vdep[l]*2+val[l];
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++)for(int j:g[i])if(scc[i]!=scc[j])gg[scc[i]].push_back(scc[j]);
    for(int i=1;i<=n;i++)val[scc[i]]++;
    for(int i=0;i<sct;i++)val[i]=(val[i]>=3);
    for(int i=0;i<sct;i++)sort(gg[i].begin(),gg[i].end()),gg[i].erase(unique(gg[i].begin(),gg[i].end()),gg[i].end());
    dfs2(0,0);
    for(int i=1;i<17;i++)for(int j=0;j<sct;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",po(2,dis(scc[a],scc[b])));
    }
}