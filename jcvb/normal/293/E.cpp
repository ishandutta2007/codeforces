#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,l,w;
struct edge{
    int v,next,w;
}e[200005];int etot=0;int g[100005];
void ae(int u,int v,int w){
    e[etot].v=v;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
}
ll ans=0;
int vis[100005]={0};
int qu[100005],sz[100005],pre[100005],bo[100005];

int gc(int rt){
    int p=0,q=0;
    qu[q++]=rt;pre[rt]=0;
    while(p!=q){
        int u=qu[p++];sz[u]=bo[u]=1;
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u] && !vis[e[i].v]){
            qu[q++]=e[i].v;pre[e[i].v]=u;
        }
    }
    for (int i=q-1;i>=0;i--){
        if(bo[qu[i]] && 2*sz[qu[i]]>=q)return qu[i];
        sz[pre[qu[i]]]+=sz[qu[i]];
        if(2*sz[qu[i]]>q)bo[pre[qu[i]]]=0;
    }
}
struct node{
    int d,w;
}s[100005];
int cmp(const node&a,const node&b){
    return a.w<b.w;
}
int dis[100005],wei[100005];
int tot;
int bit[100005];
void bitupd(int x,int del){x++;for(;x<=n;x+=x&-x)bit[x]+=del;}
int bitque(int x){x++;int ans=0;for(;x>0;x-=x&-x)ans+=bit[x];return ans;}
ll calc(int rt,int iw){
    int ot=tot;
    int p=0,q=0;
    qu[q++]=rt;pre[rt]=0;dis[rt]=1,wei[rt]=iw;
    while(p!=q){
        int u=qu[p++];s[tot++]=(node){dis[u],wei[u]};
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u] && !vis[e[i].v]){
            dis[e[i].v]=dis[u]+1;
            wei[e[i].v]=wei[u]+e[i].w;
            qu[q++]=e[i].v;
            pre[e[i].v]=u;
        }
    }
    sort(s+ot,s+tot,cmp);
    int i,j;
    ll ans=0;
    for (i=tot-1,j=ot;i>=ot;i--){
        while(j<tot && s[j].w+s[i].w<=w)bitupd(s[j++].d,1);
        ans+=bitque(l-s[i].d);
    }
    for (int k=j-1;k>=ot;k--)bitupd(s[k].d,-1);
    return ans;
}
void work(int u){
    int x=gc(u);
    vis[x]=1;
    tot=0;
    ll an=0;
    for (int i=g[x];~i;i=e[i].next)if(!vis[e[i].v]){
        an-=calc(e[i].v,e[i].w);
    }
    s[tot++]=(node){0,0};
    sort(s,s+tot,cmp);
    int i,j;
    for (i=tot-1,j=0;i>=0;i--){
        while(j<tot && s[j].w+s[i].w<=w)bitupd(s[j++].d,1);
        an+=bitque(l-s[i].d);
    }
    for (int k=j-1;k>=0;k--)bitupd(s[k].d,-1);
    ans+=(an-1)/2;
    for (int i=g[x];~i;i=e[i].next)if(!vis[e[i].v])work(e[i].v);
}

int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d%d%d",&n,&l,&w);l=min(l,n-1);
    for (int i=2;i<=n;i++){
        int y,w;scanf("%d%d",&y,&w);
        ae(i,y,w);
        ae(y,i,w);
    }
    work(1);
    cout<<ans<<endl;
    return 0;
}