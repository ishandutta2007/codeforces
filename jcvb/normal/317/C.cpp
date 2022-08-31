#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct edge{int v,next,on;}e[100005];int etot=0;int g[305];
void ae(int u,int v){
     e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int n,v;
int cur[305],des[305];
int vis[305]={0};
long long su1,su2;
int au[100000],av[100000],ad[100000],tot=0;
int deg[305]={0};int ok[305]={0};
void p(int u,int v,int w){
     if(w){
           ++tot;au[tot]=u;av[tot]=v;ad[tot]=w;
     }
}
void dfs(int u){
     su1+=cur[u];su2+=des[u];vis[u]=1;
     for (int i=g[u];~i;i=e[i].next)if(!vis[e[i].v]){
         e[i].on=e[i^1].on=1;
         deg[u]++;;deg[e[i].v]++;
         dfs(e[i].v);
     }
}
void down(int u,int mi,int pre=-1){
    for (int i=g[u];~i && mi;i=e[i].next)if(e[i].v!=pre && e[i].on && !ok[e[i].v]){
              down(e[i].v,max(mi-(v-cur[e[i].v]),0),u);
              int del=min(mi,v-cur[e[i].v]);
              p(u,e[i].v,del);
              cur[e[i].v]+=del;
              cur[u]-=del;
              mi-=del;
    }
}
void up(int u,int mi,int pre=-1){
     for (int i=g[u];~i && mi;i=e[i].next)if(e[i].v!=pre && e[i].on && !ok[e[i].v]){
              up(e[i].v,max(mi-cur[e[i].v],0),u);
              int del=min(mi,cur[e[i].v]);
              p(e[i].v,u,del);
              cur[e[i].v]-=del;
              cur[u]+=del;
              mi-=del;
     }
}
int main()
{
    memset(g,-1,sizeof(g));
    int m;
    scanf("%d%d%d",&n,&v,&m);
    for (int i=1;i<=n;i++)scanf("%d",&cur[i]);
    for (int i=1;i<=n;i++)scanf("%d",&des[i]);
    while(m--){
               int x,y;scanf("%d%d",&x,&y);
               ae(x,y);
               ae(y,x);
    }
    for (int i=1;i<=n;i++)
        if(!vis[i]){
                    su1=su2=0;
                    dfs(i);
                    if(su1!=su2){
                                 printf("NO\n");
                                 return 0;
                    }
        }
    for (int i=1;i<=n;i++)
        for (int u=1;u<=n;u++)if(!ok[u] && deg[u]==1){
             if(cur[u]>des[u])down(u,cur[u]-des[u]);
             else if(cur[u]<des[u])up(u,des[u]-cur[u]);
             ok[u]=1;
             for (int i=g[u];~i;i=e[i].next)if(!ok[e[i].v] && e[i].on)deg[e[i].v]--;
        }
    printf("%d\n",tot);
    for (int i=1;i<=tot;i++)printf("%d %d %d\n",au[i],av[i],ad[i]);
    return 0;
}