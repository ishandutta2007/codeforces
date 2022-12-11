#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=500005;

vector <int> G[MAXN];
int n,size[MAXN],vis[MAXN];
LL ans=LLONG_MAX,dp[MAXN],tmp[MAXN];

LL sqr(int x)
{
    return (LL)x*x;
}

void dfs(int u,int fa)
{
    size[u]=1;
    for (int v:G[u])
        if (v!=fa)
        {
            dfs(v,u);
            size[u]+=size[v];
        }
    dp[u]=sqr(size[u]);
    vector <int> s;
    for (int v:G[u])
        if (v!=fa)
        {
            dp[u]=min(dp[u],dp[v]+sqr(size[u]-size[v]));
            if (vis[size[v]]!=u)
            {
                vis[size[v]]=u;
                s.pb(size[v]);
                tmp[size[v]]=dp[v];
            }
            else
            {
                ans=min(ans,tmp[size[v]]+dp[v]+sqr(n-size[v]*2));
                tmp[size[v]]=min(tmp[size[v]],dp[v]);
            }
        }
    for (int i=0;i<s.size();i++)
    {
        ans=min(ans,tmp[s[i]]+sqr(n-s[i]));
        for (int j=i+1;j<s.size();j++)
            ans=min(ans,tmp[s[i]]+tmp[s[j]]+sqr(n-s[i]-s[j]));
    }
}

int main()
{
    #ifdef KeyID
        freopen("read.txt","r",stdin);
    #endif
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,0);
    printf("%lld",((LL)n*n-ans)/2+(LL)n*(n-1)/2);
    return 0;
}