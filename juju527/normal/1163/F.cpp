#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,maxm=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,Q;
struct Edge{
    int to,w,nxt;
}e[2*maxm];
int cnt;
int head[maxn];
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
struct que{
    int id;
    ll data;
    bool operator <(que i)const{return data>i.data;}
};
priority_queue<que>q;
bool in[maxn],ban[2*maxm];
bool vis[maxn];
ll dis1[maxn],dis2[maxn];
int pre[maxn];
int l[maxn],r[maxn];
void dijkstra(int s,ll *dis,int *v,int op){
    for(int i=1;i<=n;i++)dis[i]=inf;dis[s]=0;
    memset(vis,0,sizeof(vis));
    q.push((que){s,0});
    while(!q.empty()){
        int k=q.top().id;
        q.pop();
        if(vis[k])continue;
        vis[k]=1;
        for(int i=head[k];i!=-1;i=e[i].nxt){
            int tmp=e[i].to;
            if(!in[tmp]&&dis[tmp]>=dis[k]+e[i].w){
                if(dis[tmp]>dis[k]+e[i].w)v[tmp]=v[k];
                else{
                    if(!op)v[tmp]=min(v[tmp],v[k]);
                    else v[tmp]=max(v[tmp],v[k]);
                }
            }
            if(dis[tmp]<=dis[k]+e[i].w)continue;
            dis[tmp]=dis[k]+e[i].w;
            pre[tmp]=i^1;
            q.push((que){tmp,dis[tmp]});
        }
    }
    return ;
}
ll mn[maxn<<2];
void modify(int k,int l,int r,int x,int y,ll v){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){mn[k]=min(mn[k],v);return ;}
    int mid=l+((r-l)>>1);
    modify(k<<1,l,mid,x,y,v);
    modify(k<<1|1,mid+1,r,x,y,v);
    return ;
}
ll query(int k,int l,int r,int x){
    if(l==r)return mn[k];
    int mid=l+((r-l)>>1);
    if(x<=mid)return min(mn[k],query(k<<1,l,mid,x));
    return min(mn[k],query(k<<1|1,mid+1,r,x));
}
int main(){
    n=read();m=read();Q=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v,w;
        u=read();v=read();w=read();
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++)in[i]=1,l[i]=n+1;
    dijkstra(1,dis1,l,0);
    memset(in,0,sizeof(in));
    vector<int>path;path.clear();
    int p=n,len;
    while(p!=1){path.push_back(p);in[p]=1;ban[pre[p]]=ban[pre[p]^1]=1;p=e[pre[p]].to;}
    path.push_back(1);in[1]=1;
    len=path.size();
    for(int i=len-1;i>=0;i--)l[path[i]]=r[path[i]]=len-i;
    dijkstra(1,dis1,l,0);
    dijkstra(n,dis2,r,1);
    memset(mn,0x3f,sizeof(mn));
    for(int i=1;i<=n;i++){
        for(int j=head[i];j!=-1;j=e[j].nxt){
            int tmp=e[j].to;
            if(ban[j])continue;
            modify(1,1,len,l[i],r[tmp]-1,dis1[i]+dis2[tmp]+e[j].w);
        }
    }
    while(Q--){
        int t,x;
        t=read();x=read();
        int u=e[2*t-1].to,v=e[2*t-2].to,w=e[2*t-1].w;
        if(l[u]>l[v])swap(u,v);
        if(ban[2*t-1]){
            if(x<=w)printf("%lld\n",dis1[n]-w+x);
            else printf("%lld\n",min(dis1[n]-w+x,query(1,1,len,l[u])));
        }
        else{
            if(x>=w)printf("%lld\n",dis1[n]);
            else printf("%lld\n",min(dis1[n],min(dis1[u]+x+dis2[v],dis1[v]+x+dis2[u])));
        }
    }
    return 0;
}