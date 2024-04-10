#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int n;
struct edge{
    int v,next;
}e[444444];int etot=0;int g[222222];
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int hi[222222],deg[222222]={0};

int qu[222222],pre[222222],sz[222222];
void bfs(int rt){
    hi[rt]=0;
    int p=0,q=0;qu[q++]=rt;
    while(p!=q){
        int u=qu[p++];
        if(deg[u]==0)sz[u]=1;
        for (int i=g[u];~i;i=e[i].next){
            hi[e[i].v]=hi[u]+1;
            qu[q++]=e[i].v;
        }
    }
    for (int i=q-1;i>=1;i--)sz[pre[qu[i]]]+=sz[qu[i]];
}
int ma[222222],mi[222222];
#define inf 1000000000
void dp(int u){
    if(deg[u]==0)ma[u]=mi[u]=1;
    else{
        int f=hi[u]&1;//0 : maxi   1: mini
        if(f==0){
            int mini=inf;
            for (int i=g[u];~i;i=e[i].next)mini=min(mini,sz[e[i].v]-ma[e[i].v]);
            ma[u]=sz[u]-mini;
        }else{
            int su=0;
            for (int i=g[u];~i;i=e[i].next)su+=ma[e[i].v]-1;
            ma[u]=su+1;
        }
        if(f==1){
            int mini=inf;
            for (int i=g[u];~i;i=e[i].next)mini=min(mini,mi[e[i].v]);
            mi[u]=mini;
        }else{
            int su=0;
            for (int i=g[u];~i;i=e[i].next)su+=mi[e[i].v];
            mi[u]=su;
        }
    }
}

int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        ae(u,v);
        deg[u]++;
        pre[v]=u;
    }
    bfs(1);
    for (int i=n-1;i>=0;i--)dp(qu[i]);
    printf("%d %d\n",ma[1],mi[1]);
    return 0;
}