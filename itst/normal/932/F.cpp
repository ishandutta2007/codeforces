#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int maxn=100010;
typedef long long ll;
struct node
{
    ll x,y;
    node () {}
    node (ll a,ll b) {x=a,y=b;}
    bool operator < (const node &a) const {return (x==a.x)?(y<a.y):(x<a.x);}
    long double operator * (const node &a) const {return (long double)x*a.y-(long double)y*a.x;}
    node operator - (const node &a) const {return node(x-a.x,y-a.y);}
};
set<node> s[maxn];
set<node>::iterator it,iit;
int n,cnt,tot;
int to[maxn<<1],nxt[maxn<<1],head[maxn],siz[maxn],rt[maxn];
ll va[maxn],vb[maxn],f[maxn];
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
inline void add(int a,int b)
{
    to[cnt]=b,nxt[cnt]=head[a],head[a]=cnt++;
}
inline void insert(int a,node x)
{
    it=s[a].lower_bound(x);
    if(it!=s[a].end()&&(*it).x==x.x)    s[a].erase(it),it=s[a].lower_bound(x);
    if(it!=s[a].begin())
    {
        it--;
        if((*it).x==x.x)    return ;
        it++;
    }
    node l,r;
    if(it!=s[a].end()&&it!=s[a].begin())
    {
        r=*it,it--,l=*it;
        if((x-l)*(r-x)<=0)   return ;
    }
    while(1)
    {
        it=s[a].lower_bound(x);
        if(it==s[a].end())  break;
        l=*it,it++;
        if(it==s[a].end())  break;
        r=*it;
        if((l-x)*(r-l)<=0)   s[a].erase(l);
        else    break;
    }
    while(1)
    {
        it=s[a].lower_bound(x);
        if(it==s[a].begin())    break;
        it--,r=*it;
        if(it==s[a].begin())    break;
        it--,l=*it;
        if((r-l)*(x-r)<=0)   s[a].erase(r);
        else    break;
    }
    s[a].insert(x);
}
inline int merge(int a,int b)
{
    if(s[a].size()<s[b].size())  swap(a,b);
    for(iit=s[b].begin();iit!=s[b].end();iit++) insert(a,*iit);
    s[b].clear();
    return a;
}
void dfs(int x,int fa)
{
    rt[x]=++tot;
    for(int i=head[x],y;i!=-1;i=nxt[i]) if(to[i]!=fa)
    {
        y=to[i],dfs(y,x),rt[x]=merge(rt[x],rt[y]);
    }
    if(!s[rt[x]].size())    f[x]=0;
    else
    {
        int l=-100001,r=100001,mid;
        node a,b;
        while(l<r)
        {
            mid=(l+r)>>1;
            it=s[rt[x]].lower_bound(node(mid,-1ll<<60));
            if(it==s[rt[x]].begin())
            {
                l=mid+1;
                continue;
            }
            if(it==s[rt[x]].end())
            {
                r=mid;
                continue;
            }
            b=*it,it--,a=*it;
            if((b.y-a.y)<=-va[x]*(b.x-a.x))  l=mid+1;
            else    r=mid;
        }
        it=s[rt[x]].lower_bound(node(l-1,-1ll<<60));
        f[x]=va[x]*(*it).x+(*it).y;
    }
    insert(rt[x],node(vb[x],f[x]));
}
int main()
{
    //freopen("cf932F.in","r",stdin);
    //freopen("cf932F.out","w",stdout);
    n=rd();
    int i,a,b;
    memset(head,-1,sizeof(head));
    for(i=1;i<=n;i++)    va[i]=rd();
    for(i=1;i<=n;i++)    vb[i]=rd();
    for(i=1;i<n;i++) a=rd(),b=rd(),add(a,b),add(b,a);
    dfs(1,0);
    for(i=1;i<=n;i++)    printf("%I64d ",f[i]);
    return 0;
}//3 1 -1 1 -1 -1 -1 1 2 2 3