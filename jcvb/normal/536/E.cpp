#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
typedef long long ll;
#define mo 1000000007
void gn(int &x){
    char c;while((c=getchar())<'0'||c>'9');x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
}
using namespace std;
int n,m;
int g[100005]={0};
struct edge{
       int v,w,next;
}e[200005];int etot=0;
void ae(int u,int v,int w){
     e[etot].v=v;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
     e[etot].v=u;e[etot].w=w;e[etot].next=g[v];g[v]=etot++;
}
int sz[100005];
int bfs[100005],p,q,fa[100005],son[100005]={0},up[100005],h[100005],id[100005],idtot=0;
void build(){
     p=q=0;
     bfs[q++]=1;
     fa[1]=0;h[1]=0;
     int u,v,i;
     while(p<q){
               u=bfs[p++];
               for ( i=g[u];~i;i=e[i].next)if((v=e[i].v)!=fa[u]){
                   fa[v]=u;
                   bfs[q++]=v;
                   h[v]=h[u]+1;
               }
     }
     for (i=1;i<=n;i++)sz[i]=1;
     sz[0]=0;
     for (i=n-1;i>=0;i--){
         sz[fa[bfs[i]]]+=sz[bfs[i]];
         if(sz[bfs[i]]>sz[son[fa[bfs[i]]]])son[fa[bfs[i]]]=bfs[i];
     }
     for (i=n-1;i>=0;i--)if(!son[v=bfs[i]]){         
         while(v!=1 && son[fa[v]]==v)v=fa[v];
         p=v;
         while(v)up[v]=p,id[v]=++idtot,v=son[v];
     }
}
int f[111111];
struct que{
    int u,v,l,id;
}Q[111111];
struct edg{
    int u,v,w;
}E[111111];
int cmpe(const edg&a,const edg&b){
    return a.w>b.w;
}
int cmpq(const que&a,const que&b){
    return a.l>b.l;
}
int ans[111111];

struct data{
    int l,su,r,len;
};
inline data rev(const data&a){
    return (data){a.r,a.su,a.l,a.len};
}
inline int eval(const data&a){
    if(a.l==a.len)return f[a.l];
    else return f[a.l]+f[a.r]+a.su;
}
inline data operator+(const data&a,const data&b){
    data ans;
    ans.len=a.len+b.len;
    if(a.l!=a.len && b.l!=b.len){
        ans.l=a.l,ans.r=b.r,ans.su=a.su+b.su+f[a.r+b.l];
    }else if(a.l==a.len && b.l==b.len){
        ans.l=ans.r=ans.len;ans.su=0;
    }else if(a.l==a.len){
        ans.l=a.l+b.l,ans.r=b.r,ans.su=b.su;
    }else ans.l=a.l,ans.r=b.r+a.r,ans.su=a.su;
    return ans;
}

data seg[444444];
int I;
data v;

void upd(int l,int r,int x){
    if(l==r)seg[x]=v;
    else{
        int mid=l+r>>1;
        if(I<=mid)upd(l,mid,x<<1);
        else upd(mid+1,r,x<<1|1);
        seg[x]=seg[x<<1]+seg[x<<1|1];
    }
}
int l1,r1;
void qr(int l,int r,int x){
    if(l1<=l && r<=r1)v=v+seg[x];
    else{
        int mid=l+r>>1;
        if(l1<=mid)qr(l,mid,x<<1);
        if(r1>mid)qr(mid+1,r,x<<1|1);
    }
}
int query(int x,int y){
    data mex,mey;
    mex=mey=(data){0,0,0,0};
    while(up[x]!=up[y]){
        if(h[up[x]]>h[up[y]])swap(x,y),swap(mex,mey);
        l1=id[up[y]],r1=id[y];
        v=(data){0,0,0,0};
        qr(1,n,1);
        mey=v+mey;
        y=fa[up[y]];
    }
    if(h[x]>h[y])swap(x,y),swap(mex,mey);
    l1=id[x]+1,r1=id[y];
    v=(data){0,0,0,0};
    if(l1<=r1)qr(1,n,1);
    data ans=rev(mex)+v+mey;
    return eval(ans);
}
void init(int l,int r,int x){
    if(l==r){
        seg[x]=(data){0,0,0,1};
    }else{
        int mid=l+r>>1;
        init(l,mid,x<<1);
        init(mid+1,r,x<<1|1);
        seg[x]=seg[x<<1]+seg[x<<1|1];
    }
}
int main()
{
    memset(g,-1,sizeof(g));
    int q;
    scanf("%d%d",&n,&q);
    f[0]=0;for (int i=1;i<=n-1;i++)scanf("%d",&f[i]);
    for (int i=1;i<=n-1;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        ae(u,v,w);
        E[i]=(edg){u,v,w};
    }
    for (int i=1;i<=q;i++){
        scanf("%d%d%d",&Q[i].u,&Q[i].v,&Q[i].l);
        Q[i].id=i;
    }
    sort(Q+1,Q+1+q,cmpq);
    sort(E+1,E+1+(n-1),cmpe);
    init(1,n,1);
    build();
    for (int i=1;i<=n-1;i++)if(h[E[i].u]>h[E[i].v])swap(E[i].u,E[i].v);
    for (int i=1,cur=1;i<=q;i++){
        while(cur<=n-1 && E[cur].w>=Q[i].l){
            I=id[E[cur].v];
            v=(data){1,0,1,1};
            upd(1,n,1);
            cur++;
        }
        ans[Q[i].id]=query(Q[i].u,Q[i].v);
    }
    for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}