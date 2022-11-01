#include<bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=605;
int n,m;
vector<pair<int,int>>e[N];
ll dis[N],tim[N];
bool vis[N];
ll cost[N];
int res[N];
void ins(int x,ll v,int i)
{
    if(cost[x]>v)
        cost[x]=v,res[x]=i;
}
void push()
{
    for(int i=0;i<n;i++)
        if(cost[i+1]>cost[i]+1)
        cost[i+1]=cost[i]+1,res[i+1]=res[i];
}
void sol(int s)
{
    memset(vis,false,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    dis[s]=0;tim[s]=0;
    for(int i=1;i<n;i++)
    {
        int p;
        ll mn=inf;
        for(int j=0;j<n;j++)
            if(!vis[j]&&dis[j]<mn)
                mn=dis[j],p=j;
        vis[p]=true;
        memset(cost,inf,sizeof(cost));
        int id=0;
        for(pair<int,int>x:e[p])
        {
            int y=(x.first+tim[p])%n;
            ins(y,0+x.second,id);
            ins(0,n-y+x.second,id);
            id++;
        }
        push();
        for(int j=0;j<n;j++)
        {
            int k=res[j];
            if(dis[j]>dis[p]+cost[j])
            {
                dis[j]=dis[p]+cost[j];
                int s=(j-e[p][k].first+n)%n;
                tim[j]=(s+e[p][k].second)%n;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf(i==n-1?"%lld\n":"%lld ",dis[i]);
}
int main()
{
    sc(n,m);
    rep(i,1,m)
    {
        int a,b,c;
        sc(a,b,c);
        e[a].push_back({b,c});
    }
    rep(i,0,n-1)
        sol(i);
}