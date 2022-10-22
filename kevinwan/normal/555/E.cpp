#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const ll mod=998244353;
vector<int>g[mn],gg[mn];
bool vis[mn],ins[mn];
int o[mn],l[mn],scc[mn];
int ct,sct;
stack<int>s;
void dfs1(int x,int p){
    vis[x]=ins[x]=1;
    s.push(x);
    o[x]=l[x]=ct++;
    bool veshy=0;
    for(int y:g[x]){
        if(y==p&&!veshy){
            veshy=1;
            continue;
        }
        if(!vis[y])dfs1(y,x),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(o[x]==l[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[x]=sct++,ins[x]=0,s.pop();
    }
}
int anc[mn][18],dep[mn];
void dfs2(int x){
    vis[x]=1;
    for(int y:gg[x]){
        if(!vis[y])anc[y][0]=x,dep[y]=dep[x]+1,dfs2(y);
    }
}
void go(int&a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
}
int lca(int a,int b){
    if(dep[a]>dep[b])go(a,dep[a]-dep[b]);
    else go(b,dep[b]-dep[a]);
    for(int i=17;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    if(a!=b)a=anc[a][0],b=anc[b][0];
    if(a!=b){
        printf("No");
        exit(0);
    }
    return a;
}
int up[mn],down[mn];
void dfs3(int x){
    vis[x]=1;
    for(int y:gg[x]){
        if(!vis[y])dfs3(y),up[x]+=up[y],down[x]+=down[y];
    }
    if(up[x]&&down[x]){
        printf("No");
        exit(0);
    }
}
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs1(i,i);
    for(int i=1;i<=n;i++)for(int j:g[i])if(scc[i]!=scc[j]){
        gg[scc[i]].push_back(scc[j]);
    }
    for(int i=0;i<sct;i++)sort(gg[i].begin(),gg[i].end()),gg[i].erase(unique(gg[i].begin(),gg[i].end()),gg[i].end());
    memset(vis,0,sizeof(vis));
    for(int i=0;i<sct;i++)if(!vis[i])dfs2(i),anc[i][0]=i;
    for(int i=1;i<18;i++)for(int j=0;j<sct;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a=scc[a],b=scc[b];
        int l=lca(a,b);
        up[a]++;
        down[b]++;
        up[l]--;
        down[l]--;
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<sct;i++)if(!vis[i])dfs3(i);
    printf("Yes");
}