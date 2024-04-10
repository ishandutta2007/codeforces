#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl a[100005];
long n,m,K,x,u,v,i,dp[100005][12][4]={0},ans=0,h=1e9+7;

void dfs(long node,long par)
{
    long i,j,k,temp[12][4]={0},t[12][4]={0},f=0;
    if(a[node].size()==0 || (a[node].size()==1 && a[node][0]==par))
    {
        dp[node][0][0]=K-1;
        dp[node][0][2]=m-K;
        dp[node][1][1]=1;
        return ;
    }
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node);

    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    {
        if(f==0)
        {
            for(j=0;j<=x;++j)
            {
                temp[j][0]=(dp[a[node][i]][j][0]+dp[a[node][i]][j][1]+dp[a[node][i]][j][2])%h;
                temp[j][1]=dp[a[node][i]][j][0];
                temp[j][2]=(dp[a[node][i]][j][2]+dp[a[node][i]][j][0])%h;
            }
            f=1;
            continue;
        }
        for(j=0;j<=x;++j)
        for(k=0;k<=x;++k)
        {
            if(j+k>x) continue;
            t[j+k][0]=(t[j+k][0]+((temp[j][0]*((dp[a[node][i]][k][0]+dp[a[node][i]][k][1]+dp[a[node][i]][k][2])%h))%h))%h;
            t[j+k][1]=(t[j+k][1]+((temp[j][1]*dp[a[node][i]][k][0])%h))%h;
            t[j+k][2]=(t[j+k][2]+((temp[j][2]*(dp[a[node][i]][k][0]+dp[a[node][i]][k][2]))%h))%h;
        }
        for(j=0;j<=x;++j)
        {
            temp[j][0]=t[j][0];
            temp[j][1]=t[j][1];
            temp[j][2]=t[j][2];
        }
        memset(t,0,sizeof t);
    }
    for(i=0;i<=x;++i)
    {
        dp[node][i][0]=((K-1)*temp[i][0])%h;
        if(i)
        dp[node][i][1]=temp[i-1][1];
        dp[node][i][2]=((m-K)*temp[i][2])%h;
    }
}
int main()
{
    io
    long i,j;
    cin>>n>>m;
    for(i=0;i<n-1;++i)
    {
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    cin>>K>>x;
    dfs(1,-1);
    for(i=0;i<=x;++i)
    ans=(ans+dp[1][i][0]+dp[1][i][1]+dp[1][i][2])%h;
    cout<<ans;
    return 0;
}