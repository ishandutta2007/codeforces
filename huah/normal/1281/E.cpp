#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll ans,res;
int k,tot,head[N],si[N],nex[N<<1],to[N<<1],wi[N<<1];
void add(int u,int v,int w){to[++tot]=v;nex[tot]=head[u];head[u]=tot;wi[tot]=w;}
void dfs(int u,int p)
{
    si[u]=1;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==p) continue;
        dfs(v,u);
        si[u]+=si[v];
        ans+=(ll)min(si[v],k-si[v])*wi[i];
        if(si[v]%2==0&&(k-si[v])%2==0) res-=wi[i];
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(head,0,sizeof(head));tot=0;
        scanf("%d",&k);
        k*=2;
        ans=res=0;
        for(int i=1;i<k;i++)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
            res+=w;
        }
        dfs(1,0);
        printf("%lld %lld\n",res,ans);
    }
}