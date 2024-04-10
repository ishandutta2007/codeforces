#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
typedef long long ll;
int n,tot,son[N],head[N],nex[N<<1],to[N<<1];
ll dp[N],f[N];
void add(int u,int v)
{
    to[++tot]=v;nex[tot]=head[u];head[u]=tot;
    to[++tot]=u;nex[tot]=head[v];head[v]=tot;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i;i=nex[i])
        if(to[i]!=fa)
        dfs(to[i],u),son[u]++;
    dp[u]=f[son[u]+(u!=1)];
    for(int i=head[u];i;i=nex[i])
        if(to[i]!=fa)
        dp[u]=dp[u]*dp[to[i]]%mod;
}
int main()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=f[i-1]*i%mod;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    printf("%lld\n",n*dp[1]%mod);
}