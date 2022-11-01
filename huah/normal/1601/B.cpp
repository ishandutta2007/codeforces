#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N],b[N];
vector<int>e[N];
queue<int>q1,q2;
int dis[N];
int t[N<<2];
priority_queue<int>q[N];
void ins(int l,int r,int k,int x,int y)
{
    if(l==r)
    {
        q[l].push(y);
        t[k]=q[l].top();
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) ins(l,m,k<<1,x,y);
    else ins(m+1,r,k<<1|1,x,y);
    t[k]=max(t[k<<1],t[k<<1|1]);
}
int curret,to[N];
void Del(int x,int pre)
{
    dis[x]=curret;
    to[x]=pre;
    q1.push(x);
}
bool del(int l,int r,int k,int x)
{
    if(t[k]<x||l>x) return false;
    if(l==r)
    {
        Del(q[l].top(),x);
        q[l].pop();
        t[k]=q[l].top();
        return true;
    }
    int m=(l+r)>>1;
    bool ans=del(m+1,r,k<<1|1,x);
    t[k]=max(t[k<<1],t[k<<1|1]);
    if(ans) return ans;
    ans=del(l,m,k<<1,x);
    t[k]=max(t[k<<1],t[k<<1|1]);
    return ans;
}
int main()
{
    // freopen("1.in","r",stdin);
    memset(dis,inf,sizeof(dis));
    sc(n);
    rep(i,1,n) q[i].push(0);
    rep(i,1,n) sc(a[i]);
    rep(i,1,n) sc(b[i]);
    rep(i,1,n)
        e[i+b[i]].push_back(i);
    rep(i,1,n)
        if(a[i]==i)
        {
            dis[i]=1;
            q1.push(i);
        }
        else ins(1,n,1,i-a[i],i);
    curret=1;
    while(q1.size()||q2.size())
    {
        if(q1.size())
        {
            while(!q1.empty())
            {
                int u=q1.front();q1.pop();
                for(int v:e[u]) q2.push(v);
            }
        }
        else
        {
            curret++;
            while(!q2.empty())
            {
                int u=q2.front();q2.pop();
                while(del(1,n,1,u));
            }
        }
    }
    if(dis[n]==inf) out(-1);
    else
    { 
        out(dis[n]);
        int u=n;
        rep(i,1,dis[n])
        {
            u=to[u];
            printf(i==dis[n]?"%d\n":"%d ",u);
            u+=b[u];
        }
    }
}
/*
y>=x
y-a[i]<=x
*/
/*
y.xy.x.x.
*/