#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=1e5+5;
int n,m,X[N],Y[N];
struct node
{
    int l,r,t;
    bool operator<(const node&o)const
    {
        return t<o.t;
    }
};
vector<node>v[N];
int ans[N],tot,rt[N],t[N*200],ls[N*200],rs[N*200];
void ins(int l,int r,int &now,int x,int v)
{
    if(!now) now=++tot;
    t[now]=min(t[now],v);
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) ins(l,m,ls[now],x,v);
    else ins(m+1,r,rs[now],x,v);
}
int query(int l,int r,int now,int x)
{
    if(r<x||!now) return inf;
    if(l>=x) return t[now];
    int m=l+r>>1;
    return min(query(l,m,ls[now],x),query(m+1,r,rs[now],x));
}
void ins(int l,int r,int t)
{
    int x=r;
    while(x<=n)
        ins(1,n,rt[x],l,t),x+=x&-x;
}
int query(int l,int r)
{
    int x=r;
    int ans=inf;
    while(x) ans=min(ans,query(1,n,rt[x],l)),x-=x&-x;
    return ans;
}
int tim;
int cal(int l,int r)
{
    if(l>r) return 0;
    int id=query(l,r);
    if(id==inf) return 0;
    return cal(l,X[id]-1)+cal(Y[id]+1,r)+Y[id]-X[id]+1;
}
int main()
{
    memset(t,inf,sizeof(t));
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n,m);
    rep(i,1,m)
    {
        int l,r;sc(l,r);
        X[i]=l;Y[i]=r;
        v[r-l+1].push_back({l,r,i});
    }
    for(int i=n;i>=1;i--)
    {
        tim++;
        for(node x:v[i])
            ins(x.l,x.r,x.t);
        ans[i]=cal(1,n);
    }
    rep(i,1,n) out(ans[i]);
}