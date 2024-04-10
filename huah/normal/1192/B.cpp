#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
struct node
{
    ll dis,a,b,lp,lm,rp,rm;
    node(){a=b=0;lp=lm=rp=rm=dis=0;}
}t[N<<2];
ll w,ss[N];
int n,m,k,s[N],tot,in[N],out[N],head[N],nex[N<<1],to[N<<1],id[N<<1];
ll wi[N<<1];
void add(int u,int v,ll w,int _id)
{
    to[++tot]=v;nex[tot]=head[u];head[u]=tot;
    wi[tot]=w;id[tot]=_id;
}
void update(int x,int k)
{
    t[k]=node();
    if(s[x]==-1) t[k].b=ss[x];
    else if(s[x]==-2) t[k].a=ss[x];
}
node Merge(node a,node b)
{
    node ans=node();
    if(a.b>b.a) ans.a=a.a,ans.b=b.b+a.b-b.a;
    else ans.a=a.a+b.a-a.b,ans.b=b.b;
    ans.dis=max(max(a.dis,b.dis),max(a.rp+b.lm,a.rm+b.lp));
    ans.rp=max(b.rp,max(a.rp-b.a+b.b,a.rm+b.a+b.b));
    ans.rm=max(b.rm,a.rm+b.a-b.b);
    ans.lp=max(a.lp,max(a.a-a.b+b.lp,b.lm+a.a+a.b));
    ans.lm=max(a.lm,b.lm-a.a+a.b);
    return ans;
}
void build(int l,int r,int k)
{
    if(l==r)
    {update(l,k);return;}
    int m=l+r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=Merge(t[k<<1],t[k<<1|1]);
}
void fix(int l,int r,int k,int x)
{
    if(l==r){update(l,k);return;}
    int m=l+r>>1;
    if(x<=m) fix(l,m,k<<1,x);
    else fix(m+1,r,k<<1|1,x);
    t[k]=Merge(t[k<<1],t[k<<1|1]);
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==fa) continue;
        in[id[i]]=++m;
        ss[m]=wi[i];
        s[m]=-1;
        s[++m]=0;
        dfs(v,u);
        out[id[i]]=++m;
        s[m]=-2;
        ss[m]=wi[i];
    }
}
int main()
{
    scanf("%d%d%lld",&n,&k,&w);
    for(int i=1;i<n;i++)
    {
        ll w;
        int u,v;scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w,i);add(v,u,w,i);
    }
    s[++m]=-1;
    s[++m]=0;
    dfs(1,0);
    s[++m]=-2;
    build(1,m,1);
    ll lastans=0;
    while(k--)
    {
        int d;ll e;scanf("%d%lld",&d,&e);
        d=(d+lastans)%(n-1)+1;
        e=(e+lastans)%w;
        ss[in[d]]=e;ss[out[d]]=e;
        fix(1,m,1,in[d]);
        fix(1,m,1,out[d]);
        printf("%lld\n",lastans=t[1].dis);
    }
}