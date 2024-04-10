#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll ans;
int n,a[N],b[N],c[N],tot,head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
void dfs(int u,int fa)
{
    a[u]=min(a[u],a[fa]);
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==fa)continue;
        dfs(v,u);
        b[u]+=b[v];
        c[u]+=c[v];
    }
    ll k=min(b[u],c[u]);
    b[u]-=k;c[u]-=k;
    ans+=a[u]*k*2;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        if(b[i]==c[i]) b[i]=c[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    a[0]=1e9;
    dfs(1,0);
    if(b[1]||c[1]) printf("-1\n");
    else printf("%lld\n",ans);
}