#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long double db;
typedef long long ll;
int n;
struct edge{
    int v,next,w;
}e[200005];int etot=0;int g[100005];
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int len[200005];
int qu[200005],p,q;
int sz[200005]={0};
int pre[200005]={0};
void bfs(int rt){
    p=q=0;
    qu[q++]=rt;
    while(p!=q){
        int u=qu[p++];
        sz[u]=1;
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
            pre[e[i].v]=u;
            qu[q++]=e[i].v;
        }
    }
    for (int i=q-1;i>=0;i--)sz[pre[qu[i]]]+=sz[qu[i]];
}
db co[200005];
ll c[200005];
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d",&n);
    for (int i=0;i<n-1;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        ae(a,b);
        ae(b,a);
        len[i]=w;
    }
    bfs(1);
    for (int i=1;i<=n;i++)c[i]=1ll*i*(i-1)*(i-2)/6;
    for (int i=0;i<n-1;i++){
        int u=e[i*2].v,v=e[i*2+1].v;
        if(pre[u]==v)swap(u,v);
        co[i]=2.0-2.0*((long double)c[sz[v]]+c[n-sz[v]])/c[n];
    }
    db ans=0.0;
    for (int i=0;i<n-1;i++)ans+=co[i]*len[i];
    int q;scanf("%d",&q);
    while(q--){
        int id,w;
        scanf("%d%d",&id,&w);
        id--;
        ans-=co[id]*len[id];
        len[id]=w;
        ans+=co[id]*len[id];
        printf("%.15lf\n",(double)ans);
    }
    return 0;
}