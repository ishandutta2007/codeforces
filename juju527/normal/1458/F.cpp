#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
    e[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
    return ;
}
int f[maxn][18],dep[maxn],siz[maxn],hson[maxn];
void dfs1(int x,int fa){
    f[x][0]=fa;siz[x]=1;dep[x]=dep[fa]+1;
    for(int i=1;i<18;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs1(tmp,x);
        if(siz[tmp]>siz[hson[x]])hson[x]=tmp;
        siz[x]+=siz[tmp];
    }
    return ;
}
int dfsnum;
int top[maxn],dfn[maxn],num[maxn];
void dfs2(int x,int tpfa){
    top[x]=tpfa;
    dfn[x]=++dfsnum;num[dfsnum]=x;
    if(hson[x])dfs2(hson[x],tpfa);
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==f[x][0]||tmp==hson[x])continue;
        dfs2(tmp,tmp);
    }
    return ;
}
int jump(int x,int k){
    for(int i=17;i>=0;i--)if(k&(1<<i))x=f[x][i];
    return x;
}
int lca(int x,int y){
    while(top[x]^top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y);x=f[top[x]][0];}
    if(dep[x]<dep[y])swap(x,y);
    return y;
}
int dist(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
struct seg{ll laz,sum;}t[maxn<<2];
void pushup(int k){t[k].sum=t[k<<1].sum+t[k<<1|1].sum;return ;}
void add_laz(int k,int l,int r,ll v){t[k].laz+=v,t[k].sum+=1ll*(r-l+1)*v;return ;}
void pushdown(int k,int l,int r){
    int mid=l+((r-l)>>1);
    add_laz(k<<1,l,mid,t[k].laz),add_laz(k<<1|1,mid+1,r,t[k].laz);
    t[k].laz=0;
    return ;
}
void modify(int k,int l,int r,int x,int y,int v){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){add_laz(k,l,r,v);return ;}
    int mid=l+((r-l)>>1);
    pushdown(k,l,r);
    modify(k<<1,l,mid,x,y,v);modify(k<<1|1,mid+1,r,x,y,v);
    pushup(k);
    return ;
}
ll query(int k,int l,int r,int x,int y){
    if(l>y||r<x)return 0;
    if(l>=x&&r<=y)return t[k].sum;
    int mid=l+((r-l)>>1);
    pushdown(k,l,r);
    return query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y);
}
void modifyp(int x,int v){
//    if(v==1)cout<<"+"<<x<<endl;
//    else cout<<"-"<<x<<endl;
    while(top[x]^1)modify(1,1,m,dfn[top[x]],dfn[x],v),x=f[top[x]][0];
    modify(1,1,m,1,dfn[x],v);
    return ;
}
ll queryp(int x){
    ll res=0;
    while(top[x]^1)res+=query(1,1,m,dfn[top[x]],dfn[x]),x=f[top[x]][0];
    res+=query(1,1,m,2,dfn[x]);
    return res;
}
ll query_sum(int x){
    ll S=query(1,1,m,1,m),P=queryp(x),s=query(1,1,m,1,1);
    return S-P+s*(dep[x]-1)-P-s;
}
ll res=0;
struct cir{int c,r;};
cir a[maxn];
int get_middle(int x,int y,int r1,int r2,int d){
    int z=lca(x,y);
    if(dep[x]-dep[z]+r1>=d)return jump(x,d-r1);
    return jump(y,d-r2);
}
int get_d(cir a,cir b){return (dist(a.c,b.c)+a.r+b.r)/2;}
cir merge(cir a,cir b){
    cir o;
    int d=get_d(a,b);
    o.r=max(max(a.r,b.r),d);
    if(o.r==a.r)o.c=a.c;
    else if(o.r==b.r)o.c=b.c;
    else o.c=get_middle(a.c,b.c,a.r,b.r,d);
    return o;
}
ll suf[maxn];
void solve(int l,int r){
    if(l==r)return ;
    int mid=l+((r-l)>>1);
//    cerr<<"*"<<l<<" "<<r<<" "<<mid<<endl;
    a[mid]=(cir){mid,0};a[mid+1]=(cir){mid+1,0};
    for(int i=mid-1;i>=l;i--)a[i]=merge(a[i+1],(cir){i,0});
    for(int i=mid+2;i<=r;i++)a[i]=merge(a[i-1],(cir){i,0});
    suf[r+1]=0;
    for(int i=r;i>mid;i--)suf[i]=suf[i+1]+a[i].r;
//    for(int i=l;i<=r;i++)cout<<i<<" "<<a[i].c<<" "<<a[i].r<<endl;
    int p=mid,q=mid;
    ll sr2=0;
    for(int i=mid;i>=l;i--){
        while(p<r&&merge(a[p+1],a[i]).r==a[i].r)p++,modifyp(a[p].c,-1),sr2-=a[p].r;
        while(q<r&&merge(a[q+1],a[i]).r==get_d(a[q+1],a[i]))q++,modifyp(a[q].c,1),sr2+=a[q].r;
        ll cur=0;
        cur+=1ll*(p-mid)*a[i].r;
        cur+=(query_sum(a[i].c)+1ll*(q-p)*a[i].r+sr2)/2;
//        cerr<<i<<" "<<p<<" "<<q<<endl;
//        assert((query_sum(a[i].c)+1ll*(q-p)*a[i].r+sr2)%2==0);
//        cout<<query_sum(a[i].c)<<" "<<a[i].r<<" "<<sr2<<endl;
        cur+=suf[q+1];
        res+=cur;
//        cerr<<i<<" "<<mid+1<<" "<<r<<" "<<p<<" "<<q<<" "<<cur<<endl;
    }
    while(p<q)p++,modifyp(a[p].c,-1);
    solve(l,mid);
    solve(mid+1,r);
    return ;
}
int main(){
//    freopen("dist.in","r",stdin);
//	freopen("dist.out","w",stdout);
    n=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        add(u,n+i),add(n+i,u);
        add(v,n+i),add(n+i,v);
    }
    m=2*n-1;
    dfs1(1,0);
    dfs2(1,1);
    solve(1,n);
    printf("%lld\n",res);
    return 0;
}