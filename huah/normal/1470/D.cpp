#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,tot,f[N],head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
vector<int>ans;
bool vis[N];
int a[N];
bool judge(int u)
{
    if(vis[u]) return false;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];
        if(a[v]==1) return false;
    }
    return true;
}
void dfs(int u,int c)
{
    vis[u]=true;
    a[u]=c;
    if(c==1)
    {
        ans.push_back(u);
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];a[v]=2;
        }
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];
            if(!vis[v])
            {
                dfs(v,2);
            }
        }
    }
    else
    {
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];
            if(a[v]) continue;
            if(judge(v))
            {
                dfs(v,1);
            }
        }
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) f[i]=i;
        tot=0;memset(head,0,sizeof(head[0])*(n+3));
        memset(vis,false,sizeof(vis[0])*(n+3));
        memset(a,0,sizeof(a[0])*(n+3));
        for(int i=1;i<=m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
            f[getf(u)]=getf(v);
        }
        int x=getf(1);
        bool flag=true;
        for(int i=2;i<=n;i++) if(getf(i)!=x) flag=false;
        if(!flag){printf("NO\n");continue;}
        printf("YES\n");
        ans.clear();
        dfs(1,1);
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
    }
}