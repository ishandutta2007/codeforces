#include<bits/stdc++.h>
using namespace std;
const int maxn=205,inf=0x3f3f3f3f;
int n,s,t;
struct Edge{int to,w,nxt;}e[maxn*maxn];
int cnt;
int head[maxn];
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
    e[cnt]=(Edge){v,w,head[u]};
    head[u]=cnt++;
    return ;
}
bool bj[20005];
int len;
int p[20005];
void pre(){
    int N=20000;
    for(int i=2;i<=N;i++){
        if(!bj[i])p[++len]=i;
        for(int j=1;i*p[j]<=N&&j<=len;j++){
            bj[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    return ;
}
int lev[maxn];
queue<int>q;
bool bfs(){
    for(int i=s;i<=t;i++)lev[i]=0;
    while(q.size())q.pop();
    q.push(s);lev[s]=1;
    while(q.size()){
        int k=q.front();
        q.pop();
        for(int i=head[k];i!=-1;i=e[i].nxt){
            int tmp=e[i].to;
            if(lev[tmp]||!e[i].w)continue;
            lev[tmp]=lev[k]+1;
            q.push(tmp);
            if(tmp==t)return 1;
        }
    }
    return 0;
}
int dinic(int x,int flow){
    if(x==t)return flow;
    int rest=flow;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(lev[tmp]!=lev[x]+1||!e[i].w)continue;
        int inc=dinic(tmp,min(rest,e[i].w));
        if(!inc)lev[tmp]=0;
        e[i].w-=inc;
        e[i^1].w+=inc;
        rest-=inc;
        if(!rest)break;
    }
    return flow-rest;
}
int m=0;
bool vis[maxn];
vector<int>res[maxn];
void dfs(int x,bool op){
    res[m].push_back(x);
    vis[x]=1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==s||tmp==t||vis[tmp]||e[i].w==op)continue;
        dfs(tmp,op^1);
    }
    return ;
}
int main(){
    n=read();s=0,t=n+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]%2==0)add(s,i,2),add(i,s,0);
        else add(i,t,2),add(t,i,0);
    }
    pre();
    for(int i=1;i<=n;i++){
        if(a[i]&1)continue;
        for(int j=1;j<=n;j++){
            if(bj[a[i]+a[j]])continue;
            add(i,j,1),add(j,i,0);
        }
    }
    int maxflow=0;
    while(bfs()){
        int flow=dinic(s,inf);
        while(flow)maxflow+=flow,flow=dinic(s,inf);
    }
    if(maxflow!=n){puts("Impossible");return 0;}
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        m++;
        dfs(i,(a[i]&1)^1);
    }
    printf("%d\n",m);
    for(int i=1;i<=m;i++){
        printf("%d ",res[i].size());
        for(size_t j=0;j<res[i].size();j++)printf("%d ",res[i][j]);
        puts("");
    }
    return 0;
}