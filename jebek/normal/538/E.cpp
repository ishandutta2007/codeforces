#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=300000;
int n,dp[MAXN],t[MAXN],dp1[MAXN],h[MAXN];
bool mark[MAXN];
vector<int>G[MAXN];

void dfs(int v)
{
    mark[v]=true;
    if(h[v]==0)
        dp[v]=-100000000;
    if(h[v]==1)
        dp1[v]=100000000;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=1-h[v];
            dfs(u);
            t[v]+=t[u];
            if(h[v]==0)
            {
                dp[v]=max(dp[v],dp[u]-t[u]);
                dp1[v]+=dp1[u];
            }
            else
            {
                dp[v]+=dp[u]-1;
                dp1[v]=min(dp1[v],dp1[u]);
            }
        }
    }
    if(t[v]==0)
        t[v]=dp[v]=dp1[v]=1;
    else if(h[v]==0)
        dp[v]+=t[v];
    else
        dp[v]++;
}

int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1);
    cout<<dp[1]<<" "<<dp1[1]<<endl;
}