#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define inf 1e18
using namespace std;
typedef long long ll;
const int N=3e3+10;
ll tot,n,m,si[N],a[N],b[N],head[N],nex[N<<1],to[N<<1];
void add(int u,int v) {
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}
pair<ll,ll>dp[N][N],f[N];
void dfs(int u,int p)
{
    si[u]=1;
    dp[u][1]= {0,b[u]};
    for(int i=head[u]; i; i=nex[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u);
        for(int j=1;j<=si[u]+si[v];j++) f[j]={0,-inf};
        for(int j=si[u]; j>=1; j--)
        {
            for(int k=si[v]; k>=1; k--)
            {
                f[j+k]=max(f[j+k], {dp[u][j].first+dp[v][k].first+(dp[v][k].second>0),dp[u][j].second});
                f[j+k-1]=max(f[j+k-1], {dp[u][j].first+dp[v][k].first,dp[u][j].second+dp[v][k].second});
            }
        }
        si[u]+=si[v];
        for(int j=1; j<=si[u]; j++) dp[u][j]=f[j];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        tot=0;
        memset(head,0,sizeof(head));
        scanf("%lld%lld",&n,&m);
        for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
        for(int i=1; i<=n; i++) scanf("%lld",&b[i]),b[i]-=a[i];
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,0);
        printf("%d\n",dp[1][m].first+(dp[1][m].second>0));
    }
    return 0;
}