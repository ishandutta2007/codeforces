#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,x,y,tot,dep[N],fa[N],a[N],head[N],nex[N<<1],to[N<<1];
bool use[N],lev[N];
int clev[N];
void add(int u,int v)
{
    to[++tot]=v;nex[tot]=head[u];head[u]=tot;
}
void dfs(int u)
{
    lev[u]=true;
    dep[u]=dep[fa[u]]+1;
    a[dep[u]]++;
    m=max(m,dep[u]);
    for(int i=head[u];i;i=nex[i])
        dfs(to[i]),lev[u]=false;
    if(lev[u]) clev[dep[u]]++;
}
bitset<50001>b;
bitset<50001>c[20001],g[10];
int main()
{
    scanf("%d%d",&n,&x);y=n-x;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&fa[i]);
        add(fa[i],i);
    }
    dfs(1);
    vector<pair<int,int>>v;
    for(int i=1;i<=m;i+=20000)
        v.push_back({i,min(i+20000-1,m)});
    b[0]=g[0][0]=1;
    for(int i=1,j=0;i<=m;i++)
    {
        b|=b<<a[i];
        if(i==v[j].second)
        {
            j++;
            g[j]=b;
        }
    }
    if(b[min(x,y)])
    {
        printf("%d\n",m);
        int t=x,s=1;
        if(y<x) t=y,s^=1;
        for(int i=v.size();i>=1;i--)
        {
            int l=v[i-1].first,r=v[i-1].second;
            c[0]=g[i-1];
            for(int j=l;j<=r;j++)
                c[j-l+1]=c[j-l]|(c[j-l]<<a[j]);
            for(int j=r;j>=l;j--)
                if(t>=a[j]&&c[j-l][t-a[j]])
                t-=a[j],use[j]=s;
                else use[j]=s^1;
        }
        assert(t==0);
        for(int i=1;i<=n;i++)
            if(use[dep[i]]) putchar('a');
            else putchar('b');
    }
    else
    {
        printf("%d\n",m+1);
        int mx=-1,p=-1;
        for(int i=1;i<=m;i++)
            if(clev[i]>mx)
            mx=clev[i],p=i;
        assert(p!=-1);
        a[p]-=mx;
        b.reset();
        b[0]=1;
        for(int i=1,j=0;i<=m;i++)
        {
            b|=b<<a[i];
            if(i==v[j].second)
            {
                j++;
                g[j]=b;
            }
        }
        int t=x,s=1;
        if(y<x) t=y,s^=1;
        bool flag=false;
        for(int i=t;i>=0;i--)
            if(b[i]&&n-mx-i<=n-t)
        {
            flag=true;t=i;break;
        }
        assert(flag);
        for(int i=v.size();i>=1;i--)
        {
            int l=v[i-1].first,r=v[i-1].second;
            c[0]=g[i-1];
            for(int j=l;j<=r;j++)
                c[j-l+1]=c[j-l]|(c[j-l]<<a[j]);
            for(int j=r;j>=l;j--)
                if(t>=a[j]&&c[j-l][t-a[j]])
                t-=a[j],use[j]=s;
                else use[j]=s^1;
        }
        assert(t==0);
        for(int i=1;i<=m;i++)
            if(use[i]) x-=a[i];
        else y-=a[i];
        assert(x>=0);assert(y>=0);assert(x+y==mx);
        for(int i=1;i<=n;i++)
            if(lev[i]&&dep[i]==p)
        {
            clev[p]--;
            if(x) putchar('a'),x--;
            else
            {
                assert(y>=0);
                putchar('b'),y--;
            }
        }
        else if(use[dep[i]]) putchar('a');
        else putchar('b');
        assert(clev[p]==0);
    }
}