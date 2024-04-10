#include <bits/stdc++.h>
using namespace std;

const int MAXN=110,MAXK=24,MOD=1e9+7;
bool mark[MAXN];
long long dp[MAXN][MAXK][MAXK],dp1[MAXK][MAXK],n,ans,k;
vector<int>G[MAXN];

void dfs(int v)
{
    mark[v]=true;
    dp[v][k+1][1]=dp[v][0][0]=1;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            dfs(u);
            memset(dp1,0,sizeof dp1);
            for(int x=0;x<=k+1;x++)
                for(int y=0;y<=k+1;y++)
                    for(int r=0;r<=k+1;r++)
                        for(int t=0;t<=k+1;t++)
                        {
                            int tmp=max(y,t+1);
                            if(min(x,r+1)+tmp<=k+1)
                                tmp=0;
                          //  cout<<x<<" "<<y<<" "<<r<<" "<<t<<" "<<dp[v][x][y]<<" "<<dp[u][r][t]<<endl;
                            dp1[min(x,r+1)][tmp]=(dp1[min(x,r+1)][tmp]+dp[v][x][y]*dp[u][r][t])%MOD;
                        }
            memcpy(dp[v],dp1,sizeof dp1);
        }
    }
  /*  for(int i=0;i<=k+1;i++)
        for(int j=0;j<=k+1;j++)
            cout<<v<<" "<<i<<" "<<j<<" "<<dp[v][i][j]<<endl;*/
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1);
    for(int i=0;i<=k;i++)
        ans=(ans+dp[1][i][0])%MOD;
    cout<<ans<<endl;
}