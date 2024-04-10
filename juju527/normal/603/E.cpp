#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=3e5+5;
struct edge{
    int id,u,v,w;
    bool operator <(edge i)const{return w<i.w;}
}e1[maxm],e2[maxm];
int val[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int f[maxn],rk[maxn];
bool siz[maxn];
int find(int x){return f[x]==x?x:find(f[x]);}
int tp;
int st[maxm][2];
int block=0;
bool ins(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return 0;
    if(rk[u]>rk[v])swap(u,v);
    tp++,st[tp][0]=u,st[tp][1]=rk[v];
    f[u]=v;if(rk[u]==rk[v])rk[v]++;siz[v]^=siz[u];
    if(!siz[v]&&siz[u])block-=2;
    return 1;
}
void revoke(){
    int u=st[tp][0],v=f[u];
    f[u]=u,rk[v]=st[tp][1],siz[v]^=siz[u],tp--;
    if(siz[v]&&siz[u])block+=2;
    return ;
}
int ans[maxm];
void solve(int l,int r,int L,int R){
    if(l>r)return ;
    int mid=l+((r-l)>>1),num=0;
    for(int i=l;i<=mid;i++)if(val[i]<L)num+=ins(e1[i].u,e1[i].v);
    int res=0;
    for(int i=L;i<=R;i++){
        if(e2[i].id<=mid)num+=ins(e2[i].u,e2[i].v);
        if(!block){res=i;break;}
    }
    ans[mid]=res;
    while(num--)revoke();
    if(res>0){
        num=0;for(int i=L;i<res;i++)if(e2[i].id<l)num+=ins(e2[i].u,e2[i].v);
        solve(l,mid-1,res,R);
        while(num--)revoke();
    }
    else for(int i=l;i<=mid;i++)ans[i]=0;
    num=0;for(int i=l;i<=mid;i++)if(val[i]<L)num+=ins(e1[i].u,e1[i].v);
    solve(mid+1,r,L,(!res)?R:res);
    while(num--)revoke();
    return ;
}
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=m;i++)e1[i]=e2[i]=(edge){i,read(),read(),read()};
    sort(e2+1,e2+m+1);
    for(int i=1;i<=m;i++)val[e2[i].id]=i;
    block=n;
    for(int i=1;i<=n;i++)f[i]=i,rk[i]=1,siz[i]=1;
    solve(1,m,1,m);
    e2[0].w=-1;
    for(int i=1;i<=m;i++)printf("%d\n",e2[ans[i]].w);
    return 0;
}