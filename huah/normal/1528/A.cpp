#include<bits/stdc++.h>
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
const int N=4e5+5;
int n,l[N],r[N];
ll f[N][2];
vector<int>e[N];
void dfs(int u,int p)
{
    f[u][0]=f[u][1]=0;
    for(int v:e[u])
        if(v!=p)
    {
        dfs(v,u);
        f[u][0]+=max(abs(l[v]-l[u])+f[v][0],abs(r[v]-l[u])+f[v][1]);
        f[u][1]+=max(abs(l[v]-r[u])+f[v][0],abs(r[v]-r[u])+f[v][1]);
    }
}
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) e[i].clear();
        rep(i,1,n) sc(l[i],r[i]);
        rep(i,1,n-1)
        {
            int u,v;sc(u,v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        out(max(f[1][0],f[1][1]));
    }
}