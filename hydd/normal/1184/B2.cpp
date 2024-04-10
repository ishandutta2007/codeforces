#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,n1,n2,k,h,s,t;
int dis[110][110],x[1100],a[1100],f[1100];
vector<int> vec[110000];

int edgenum=1,vet[2100000],flow[2100000],Next[2100000],Head[2100],cur[2100];
void addedge(int u,int v,int f){
    vet[++edgenum]=v; flow[edgenum]=f;
    Next[edgenum]=Head[u]; Head[u]=edgenum;
}
void Add(int u,int v,int f){
    addedge(u,v,f);
    addedge(v,u,0);
}
int head,tail,que[2100],d[2100],maxflow;
bool bfs(){
    for (int i=s;i<=t;i++) d[i]=INF;
    head=1; tail=1; que[1]=t; d[t]=0;
    while (head<=tail){
        int u=que[head++];
        for (int e=Head[u];e;e=Next[e])
            if (flow[e^1]&&d[vet[e]]>d[u]+1){
                d[vet[e]]=d[u]+1;
                que[++tail]=vet[e];
            }
    }
    return d[s]!=INF;
}
int dfs(int u,int f){
    if (u==t){
        maxflow+=f;
        return f;
    }
    int t=0;
    for (int &e=cur[u];e;e=Next[e])
        if (flow[e]&&d[vet[e]]+1==d[u]){
            int tmp=dfs(vet[e],min(flow[e],f-t));
            flow[e]-=tmp; flow[e^1]+=tmp; t+=tmp;
            if (f==t) break;
        }
    return t;
}
void dinic(){
    while (bfs()){
        for (int i=s;i<=t;i++) cur[i]=Head[i];
        dfs(s,INF);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dis[i][j]=(i==j?0:INF);
    int u,v;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        dis[u][v]=1; dis[v][u]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    scanf("%d%d%d%d",&n1,&n2,&k,&h);
    s=0; t=n1+n2+1;
    for (int i=1;i<=n1;i++){
        Add(s,i,1);
        scanf("%d%d%d",&x[i],&a[i],&f[i]);
    }
    int y,b;
    for (int i=1;i<=n2;i++){
        scanf("%d%d",&y,&b);
        for (int j=1;j<=n1;j++)
            if (dis[x[j]][y]<=f[j]&&a[j]>=b) Add(j,i+n1,1);
        Add(i+n1,t,1);
    }
    dinic();
    printf("%lld\n",min(1ll*k*maxflow,1ll*n1*h));
    return 0;
}