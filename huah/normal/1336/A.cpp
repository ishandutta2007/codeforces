#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,k,tot,si[N],f[N],head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
void dfs(int u,int p,int dep)
{
    f[u]=dep;
    if(u==1) f[u]++;
    si[u]=1;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==p)continue;
        dfs(v,u,dep+1);
        f[u]-=si[v];
        si[u]+=si[v];
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,0,0);
    sort(f+1,f+1+n,greater<int>());
    ll ans=0;
    for(int i=1;i<=k;i++)
        ans+=f[i];
    printf("%lld\n",ans);
}