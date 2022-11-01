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
const int N=105;
int n,m;
struct node
{
    int x,y,t;
    bool operator<(const node&o)const
    {
        return t<o.t;
    }
}a[N],b[N];
int dp[1<<14][N],g[1<<14][N];
int dis[1<<14][N<<1];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n,m);
    rep(i,1,n) sc(a[i].x,a[i].y);
    rep(i,1,m) sc(b[i].x,b[i].y,b[i].t);
    sort(b+1,b+1+m);
    int u=0;
    memset(g,inf,sizeof(g));
    memset(dp,-inf,sizeof(dp));
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=n;i++)
        g[1<<i-1][0]=0;
    for(int i=1;i<=m;i++)
        dp[0][i]=1;
    int up=1<<n;
    for(int i=1;i<up;i++)
    {
        int y,z;
        for(int j=0;j<n;j++)
            if(i>>j&1)
            y=i^(1<<j),z=j+1;
        for(int j=1;j<=n+m;j++)
            dis[i][j]=min(j<=m?abs(a[z].x-b[j].x)+abs(a[z].y-b[j].y):abs(a[z].x-a[j-m].x)+abs(a[z].y-a[j-m].y),dis[y][j]);
    }
    int ans=0;
    for(int s=0;s<up;s++)
    {
        for(int i=0;i<=m;i++)
            if(g[s][i]!=inf)
            for(int j=1;j<=m;j++)
            if(g[s][i]+dis[s][j]<=b[j].t)
            dp[s][j]=max(dp[s][j],i+1);
        for(int i=1;i<=m;i++)
        if(dp[s][i]>=0)
        {
            ans=max(ans,dp[s][i]);
            g[s][dp[s][i]]=min(g[s][dp[s][i]],b[i].t);
            for(int j=i+1;j<=m;j++)
            if(b[i].t+min(dis[s][j],abs(b[i].x-b[j].x)+abs(b[i].y-b[j].y))<=b[j].t)
                dp[s][j]=max(dp[s][j],dp[s][i]+1);
            for(int j=0;j<n;j++)
                if(!(s>>j&1))
                g[s^(1<<j)][dp[s][i]]=min(g[s^(1<<j)][dp[s][i]],b[i].t+min(dis[s][m+j+1],abs(a[j+1].x-b[i].x)+abs(a[j+1].y-b[i].y)));
        }
        for(int i=0;i<=m;i++)
            for(int j=0;j<n;j++)
            if(!(s>>j&1))
            g[s^(1<<j)][i]=min(g[s^(1<<j)][i],g[s][i]+dis[s][m+j+1]);
    }
    out(ans);
}