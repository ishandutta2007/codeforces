#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define inf 1000000000
using namespace std;
int n,m;
struct edge{
    int u,v,w,next;
}e[10005];int etot=0;
int g[1005];
void ae(int u,int v,int w){
    e[etot].v=v;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
}
int vis[1005]={0};
void dfs2(int u){
    vis[u]|=2;
    for (int i=g[u];~i;i=e[i].next)if(e[i].w==2 && !(vis[e[i].v]&2))dfs2(e[i].v);
}
void dfs1(int u){
    vis[u]|=1;
    for (int i=g[u];~i;i=e[i].next)if(e[i].w==-1 && !(vis[e[i].v]&1))dfs1(e[i].v);
}
int d[1005];
int qu[1005],inq[1005],len[1005];
int p,q;
void bell(){    
    d[1]=0;
    p=q=0;
    qu[q++]=1;inq[1]=1;len[1]=1;
    while(p!=q){
        int u=qu[p++];inq[u]=0;if(p==1005)p=0;
        for (int i=g[u];~i;i=e[i].next)if(vis[e[i].v]==3 && d[e[i].v]>d[u]+e[i].w){
            d[e[i].v]=d[u]+e[i].w;
            len[e[i].v]=len[u]+1;
            if(len[e[i].v]>n){
                printf("No\n");
                exit(0);
            }
            if(!inq[e[i].v]){
                inq[e[i].v]=1;
                qu[q++]=e[i].v;
                if(q==1005)q=0;
            }
        }
    }
}
int main(){
    memset(g,-1,sizeof(g));
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        ae(u,v,2);
        ae(v,u,-1);
    }
    dfs2(1);
    dfs1(n);
    for (int i=1;i<=n;i++)d[i]=inf;
    bell();
    printf("Yes\n");
    for (int i=0;i<etot;i+=2){
        int u=e[i^1].v,v=e[i].v;
        if(vis[u]==3 && vis[v]==3)printf("%d\n",d[v]-d[u]);
        else printf("1\n");
    }
    return 0;
}