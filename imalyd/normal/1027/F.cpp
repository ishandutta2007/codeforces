//Problem F
#include<bits/stdc++.h>
using namespace std;
void rd(int &a){
    a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while( isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
}
const int N=2000005;
int n,a[N],b[N],h[N],m,vis[N],k,cn[N],cm[N],sz[N],fi[N],tot;
struct edge{
    int to,next;
}e[N<<2];
void dfs(int v,int x){
    if(vis[v])return;
    vis[v]=x,++cn[x],cm[x]+=(int)sz[v];
    for(int i=fi[v];i;i=e[i].next)dfs(e[i].to,x);
}
void addedge(int s,int t){++sz[s],e[++tot]=(edge){t,fi[s]},fi[s]=tot;}
int chk(int x){
    k=tot=0;
    memset(vis,0,sizeof(vis));
    memset(cn,0,sizeof(cn));
    memset(cm,0,sizeof(cm));
    memset(fi,0,sizeof(fi));
    memset(sz,0,sizeof(sz));
    for(int i=1;i<=m;i++){
        int v=a[i],u=b[i];
        if(x<u)u=v;
        addedge(v,u),addedge(u,v);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,++k);
    for(int i=1;i<=k;i++)if(cn[i]<(cm[i]>>1))return 0;
    return 1;
}
int main(){
    rd(m);
    for(int i=1;i<=m;i++)rd(a[i]),rd(b[i]),h[++n]=a[i],h[++n]=b[i];
    sort(h+1,h+n+1),h[0]=-1;
    n=unique(h+1,h+n+1)-h-1;
    for(int i=1;i<=m;i++)a[i]=lower_bound(h+1,h+n+1,a[i])-h;
    for(int i=1;i<=m;i++)b[i]=lower_bound(h+1,h+n+1,b[i])-h;
    //printf("%d %d\n",n,m);
    //for(int i=1;i<=m;i++)printf("%d %d\n",a[i],b[i]);
    int l=0,r=n,u=0;
    for(int i=1;i<=m;i++)l=max(l,a[i]);
    while(l<=r){
        int d=(l+r)>>1;
        if(chk(d))u=d,r=d-1;
        else l=d+1;
    }
    printf("%d",h[u]);
    return 0;
}