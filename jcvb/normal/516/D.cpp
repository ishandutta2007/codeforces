#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
#define inf 10000000000000ll
using namespace std;
typedef long long ll;
int n;

struct edge{
    int v,next,w;
}e[200005];int etot=0;int g[100005];
void ae(int u,int v,int w){
    e[etot].v=v;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
}
int deg[100005]={0};

ll dis1[100005],dis2[100005];
int qu[100005];
int pre[100005];
void bfs(int rt,ll *dis){
    pre[rt]=0;
    int p=0,q=0;
    dis[rt]=0;
    qu[q++]=rt;
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
            pre[e[i].v]=u;
            dis[e[i].v]=dis[u]+e[i].w;
            qu[q++]=e[i].v;
        }
    }
}

ll d[100005];

int pr[18][100005];
ll up[18][100005];
void bfs2(int rt){
    pr[0][rt]=0;
    up[0][rt]=inf;
    int p=0,q=0;
    qu[q++]=rt;
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pr[0][u]){
            pr[0][e[i].v]=u;
            up[0][e[i].v]=d[e[i].v]-d[u];
            qu[q++]=e[i].v;
        }
    }
    for (int i=1;i<=17;i++){
        for (int u=1;u<=n;u++)pr[i][u]=pr[i-1][pr[i-1][u]],up[i][u]=up[i-1][u]+up[i-1][pr[i-1][u]];
    }
}

int r=1;

int su[100005];
int work(ll x){
    memset(su,0,sizeof(su));
    for (int u=1;u<=n;u++){
        ll tx=x;
        int v=u;
        for (int i=17;i>=0;i--){
            if(up[i][v]<=tx){
                tx-=up[i][v];
                v=pr[i][v];
            }
        }
        su[pr[0][v]]--;
        su[u]++;
    }
    for (int i=n-1;i>=0;i--)su[pr[0][qu[i]]]+=su[qu[i]];
    int ma=0;
    for (int i=1;i<=n;i++)ma=max(ma,su[i]);
    return ma;
}
    
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        deg[x]++;deg[y]++;
        ae(x,y,w);
        ae(y,x,w);
    }
    bfs(1,dis1);
    int u=1;
    for (int i=2;i<=n;i++)if(dis1[i]>dis1[u])u=i;
    bfs(u,dis1);
    int v=1;
    for (int i=2;i<=n;i++)if(dis1[i]>dis1[v])v=i;
    bfs(v,dis2);
    for (int i=1;i<=n;i++)d[i]=max(dis1[i],dis2[i]);
    for (int i=2;i<=n;i++)if(d[i]<d[r])r=i;
    bfs2(r);
    int q;
    scanf("%d",&q);
    while(q--){
        ll x;cin>>x;
        printf("%d\n",work(x));
    }
    return 0;
}