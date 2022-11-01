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
const int N=105,mod=998244353;
int n,m,k;
const ll inf=1e18;
vector<int>e[N];
bool vis[N],del[N];
int match[N];
bool sol(int u)
{
    vis[u]=true;
    for(int v:e[u])
        if(!del[v]&&(!match[v]||!vis[match[v]]&&sol(match[v])))
    {
        match[u]=v;match[v]=u;
        return true;
    }
    return false;
}
ll x[N],y[N],use[N];
ll sum[N],pre[N];
vector<int>ans[N];
pair<int,int>op[N];
vector<pair<int,int>>res;
ll curans=inf;
int mark=-1;
void Del(int m)
{
    int dd;
    for(int i=1;i<=n+n;i++)
    if(match[i])
    {
        int y=match[i];
        match[i]=match[y]=0;
        del[i]=true;
        memset(vis,false,sizeof(vis));
        if(sol(y))
            del[i]=false;
        else
        {
            dd=i;break;
        }
    }
    ll mn=1e9+7,mnx=1e9+7,p;
    for(int i=1;i<=m;i++)
    if(min(y[i],x[i]-y[i]*use[i])<mn||min(y[i],x[i]-y[i]*use[i])==mn&&x[i]<mnx)
    {
        mnx=x[i];
        mn=min(y[i],x[i]-y[i]*use[i]);
        p=i;
    }
    sum[m]=mn;
    pre[m]=pre[m-1]+mn;
    op[m]={p,dd};
    use[p]++;
    ans[p].push_back(dd<=n?dd:-(dd-n));
    ll cost=0;
    for(int i=m;i>=1;i--)
    {
        cost+=sum[i];
        if(cost>=x[i]&&x[i]+pre[i-1]<curans)
        {
            curans=x[i]+pre[i-1];
            mark=i;
            for(int k=1;k<i;k++)
                res.push_back(op[k]);
        }
    }
}
int main()
{
    sc(n,m,k);
    while(m--)
    {
        int u,v;sc(u,v);
        e[u].push_back(v+n);
        e[v+n].push_back(u);
    }
    for(int i=1;i<=k;i++)
        scanf("%d%d",&x[i],&y[i]);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(vis));
        if(sol(i)) sum++;
    }
    for(int i=1;i<=k;i++)
    {
        while(n-sum<=i)
            Del(i),sum--;
    }
    if(mark==-1)
    {
        int res=0;
        for(int i=1;i<=k;i++)
            res+=ans[i].size()+1;
        printf("%d\n",res);
        for(int i=1;i<=k;i++)
        {
            for(int x:ans[i]) printf("%d ",x);
            printf(i==k?"%d\n":"%d ",0);
        }
    }
    else
    {
        memset(del,false,sizeof(del));
        printf("%d\n",2*n+k);
        for(int i=1;i<=k;i++) ans[i].clear();
        for(pair<int,int>x:res)
            ans[x.first].push_back(x.second<=n?x.second:-(x.second-n));
        for(int i=1;i<mark;i++)
        {
            for(int x:ans[i]) printf("%d ",x),del[x]=true;
            printf("%d ",0);
        }
        for(int i=1;i<=2*n;i++)
            if(!del[i])
        {
            if(i<=n) printf("%d ",i);
            else printf("%d ",-(i-n));
        }
        for(int i=mark;i<=k;i++)
            printf(i==k?"%d\n":"%d ",0);
    }
}