#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int n,m,id,s,t;
int a[maxn][maxn];
int d[maxn],in[maxn];
struct Edge{int to,w,c,nxt;}e[8*maxn*maxn];
int cnt;
int head[maxn*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w,int c){
    e[cnt]=(Edge){v,w,c,head[u]};
    head[u]=cnt++;
    return ;
}
int inc[maxn*maxn],pre[maxn*maxn];
int dis[maxn*maxn];
bool vis[maxn*maxn];
queue<int>q;
bool spfa(){
    for(int i=s;i<=t;i++)vis[i]=0,dis[i]=inf;
    q.push(s);inc[s]=n;vis[s]=1;dis[s]=0;
    while(q.size()){
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(int i=head[k];i!=-1;i=e[i].nxt){
            int tmp=e[i].to;
            if(dis[tmp]<=dis[k]+e[i].c||!e[i].w)continue;
            dis[tmp]=dis[k]+e[i].c;
            inc[tmp]=min(inc[k],e[i].w);
            pre[tmp]=i^1;
            if(!vis[tmp])q.push(tmp),vis[tmp]=1;
        }
    }
    return dis[t]<inf;
}
int mincost;
void update(){
    int x=t;
    mincost+=dis[t]*inc[t];
    while(x^s){
        int id=pre[x];
        e[id].w+=inc[t];
        e[id^1].w-=inc[t];
        x=e[id].to;
    }
    return ;
}
int main(){
    n=read();m=read();id=n;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)a[i][j]=2;
    for(int i=1;i<=m;i++){
        int x,y;
        x=read();y=read();
        a[x][y]=1,a[y][x]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            x=a[i][j];
            if(x==1)in[j]++;
            if(x==2)d[i]++;
            if(x==2&&i<j){
                id++;
                add(s,id,1,0),add(id,s,0,0);
                add(id,i,1,0),add(i,id,0,0);
                add(id,j,1,0),add(j,id,0,0);
            }
        }
    }
    t=id+1;
    int res=n*(n-1)*(n-2)/6;
    for(int i=1;i<=n;i++){
        res-=in[i]*(in[i]-1)/2;
        for(int j=1;j<=d[i];j++){
            int val=in[i]+j-1;
            add(i,t,1,val),add(t,i,0,-val);
        }
    }
    while(spfa())update();
    for(int i=n+1;i<=id;i++){
        int x,y;
        for(int j=head[i];j!=-1;j=e[j].nxt){
            int tmp=e[j].to;
            if(tmp==s)continue;
            if(e[j].w)x=tmp;
            else y=tmp;
        }
        a[x][y]=1,a[y][x]=0;
    }
    for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d",a[i][j]);
    return 0;
}