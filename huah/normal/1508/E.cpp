/*
time complex:O(n)
*/
#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=3e5+5,mod=1e9+7;
int n,f[N],a[N],bit[N],fa[N];
void add(int x,int v)
{
    while(x<=n) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int ans=0;
    while(x) ans+=bit[x],x-=x&-x;
    return ans;
}
vector<int>e[N];
ll ans;
void dfs(int u,int p,int dep)
{
    // ans+=query(n)-query(a[u]);
    // add(a[u],1);
    if(p&&a[p]>a[u]) ans+=dep;
    for(int v:e[u])
        if(v!=p) dfs(v,u,dep+1);
    // add(a[u],-1);
}
int top,id,s[N];
bool flag=true;
bool cmp(int x,int y){return a[x]<a[y];}
void gfs(int u,int p)
{
    ++id;
    if(a[u]!=id) flag=false;
    sort(e[u].begin(),e[u].end(),cmp);
    for(int v:e[u])
        if(v!=p) gfs(v,u);
}
bool judge()
{
    gfs(1,0);
    return flag;
}
bool vis[N];
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(a[i]);
    rep(i,1,n-1)
    {
        int u,v;sc(u,v);
        e[u].push_back(v);
        fa[v]=u;
    }
    dfs(1,0,0);
    rep(i,1,n) f[a[i]]=i;
    int lim=0;
    for(int i=n;i>=1;i--)
        if(a[fa[f[i]]]>a[f[i]])
        {
            int u=f[i];
            s[top=1]=u;
            while(u!=1) u=fa[u],s[++top]=u;
            reverse(s+1,s+1+top);
            deque<int>q;
            rep(i,1,top-1) q.push_back(a[s[i]]);
            rep(i,1,top) vis[s[i]]=true;
            q.push_front(a[s[top]]);
            for(int j=i-1;j>=1;j--)
            {
                int u=f[j];
                if(vis[u]){printf("NO\n");exit(0);}
                vector<int>vc;
                while(!vis[u])
                {
                    vc.push_back(u);
                    u=fa[u];
                }
                while(top&&s[top]!=u) a[s[top]]=q.back(),q.pop_back(),top--;
                if(top==0){printf("NO\n");exit(0);}
                reverse(vc.begin(),vc.end());
                for(int i=0;i<vc.size()-1;i++) q.push_back(a[vc[i]]);
                q.push_front(a[vc.back()]);
                for(int x:vc) s[++top]=x,vis[x]=true;
            }
            while(top) a[s[top]]=q.back(),q.pop_back(),top--;
            break;
        }
    if(judge())
    {
        printf("YES\n");
        printf("%lld\n",ans);
        oary(a,1,n);
    }
    else printf("NO\n");
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {    
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/