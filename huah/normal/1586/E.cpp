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
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
int n,m,q,f[N],s[N],fa[N],dep[N],a[N],b[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
vector<int>e[N];
vector<int>ans1[N],ans2[N];
void dfs(int u,int p)
{
    fa[u]=p;
    dep[u]=dep[p]+1;
    for(int v:e[u])
        if(v!=p) dfs(v,u);
}
void link(int u,int v,int id)
{
    while(u!=v)
    {
        if(dep[u]>dep[v]) ans1[id].push_back(u),s[u]^=1,u=fa[u];
        else ans2[id].push_back(v),s[v]^=1,v=fa[v];
    }
    ans1[id].push_back(u);
    reverse(ans2[id].begin(),ans2[id].end());
    ans1[id].insert(ans1[id].end(),ans2[id].begin(),ans2[id].end());
}
int ans;
void printPath()
{
    printf("YES\n");
    for(int i=1;i<=q;i++)
    {
        printf("%d\n",ans1[i].size());
        for(int j=0;j<ans1[i].size();j++)
            printf(j==ans1[i].size()-1?"%d\n":"%d ",ans1[i][j]);
    }
}
void cal(int u,int p)
{
    int z=0;
    for(int v:e[u])
        if(v!=p)
    {
        cal(v,u);
        z+=s[v];
    }
    ans-=z/2;
    if(z%2&&s[u]) ans--;
}
int main()
{
    srand(time(0));
    // freopen("1.in","w",stdout);
    sc(n,m);
    rep(i,1,n) f[i]=i;
    rep(i,1,m)
    {
        int u,v;sc(u,v);
        if(getf(u)==getf(v)) continue;
        e[u].push_back(v);
        e[v].push_back(u);
        f[getf(u)]=getf(v);
    }
    dfs(1,0);
    sc(q);
    rep(i,1,q)
    {
        sc(a[i],b[i]);
        link(a[i],b[i],i);
    }
    rep(i,1,n) ans+=s[i];
    if(ans==0) printPath();
    else
    {
        cal(1,0);
        printf("NO\n");
        out(ans);
    }
}