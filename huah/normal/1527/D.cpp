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
const int N=3e5+5;
int n,a[N],fa[N],si[N];
vector<int>e[N];
ll ans[N];
void dfs(int u,int p)
{
    si[u]=1;fa[u]=p;
    for(int v:e[u])
        if(v!=p)
        dfs(v,u),si[u]+=si[v];
}
bool vis[N];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,0,n) e[i].clear(),ans[i]=vis[i]=0;
        rep(i,1,n-1)
        {
            int u,v;sc(u,v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(0,-1);
        ans[0]=1ll*n*(n-1)/2;
        int sum=1;
        for(int v:e[0])
        {
            ans[1]+=1ll*sum*si[v];
            sum+=si[v];
        }
        vis[0]=true;
        int u=1;
        int x=0,y=1,z;
        while(u)
        {
            vis[u]=true;
            if(fa[u]==0) z=u;
            u=fa[u];
        }
        ans[2]=1ll*si[y]*(n-si[z]);
        rep(i,2,n-1)
        {
            if(!vis[i])
            {
                int u=i;
                while(!vis[u])
                {
                    vis[u]=true;
                    u=fa[u];
                }
                if(u==x) x=i;
                else if(u==y) y=i;
                else break;
            }
            if(x==0) ans[i+1]=1ll*si[y]*(n-si[z]);
            else ans[i+1]=1ll*si[x]*si[y];
        }
        rep(i,0,n-1) ans[i]-=ans[i+1];
        rep(i,0,n)
            printf(i==n?"%lld\n":"%lld ",ans[i]);
    }
}