#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=4000;
bool mark[MAXN];
int dp1[MAXN],dp2[MAXN],t,ans,MAX,n;
vector<int>G[MAXN],G1[MAXN],child1[MAXN],child2[MAXN];

void dfs(int v)
{
    mark[v]=true;
    child1[v].clear();
    child2[v].clear();
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            dfs(u);
            dp1[v]+=dp1[u];
            child1[v].push_back(u);
        }
    }
    for(int i=0;i<G1[v].size();i++)
    {
        int u=G1[v][i];
        if(!mark[u])
        {
            t++;
            dfs(u);
            dp1[v]+=dp1[u]+1;
            child2[v].push_back(u);
        }
    }
    for(int i=0;i<child1[v].size();i++)
    {
        int u=child1[v][i];
        dp2[v]=min(dp2[v],dp2[u]+dp1[v]-dp1[u]+1);
    }
    for(int i=0;i<child2[v].size();i++)
    {
        int u=child2[v][i];
        dp2[v]=min(dp2[v],dp2[u]+dp1[v]-dp1[u]-1);
    }
    dp2[v]=min(dp2[v],dp1[v]);
    MAX=max(MAX,dp1[v]-dp2[v]);
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        G[v].push_back(u);
        G1[u].push_back(v);
    }
    ans=100000000;
    for(int i=1;i<=n;i++)
    {
        memset(mark,false,sizeof mark);
        memset(dp1,0,sizeof dp1);
        memset(dp2,127,sizeof dp2);
        t=0;
        MAX=0;
        dfs(i);
     //   cout<<i<<"#"<<t<<" "<<MAX<<endl;
      //  for(int j=1;j<=n;j++)
       //     cout<<" "<<j<<" "<<dp1[j]<<" "<<dp2[j]<<endl;
        ans=min(ans,t-MAX);
    }
    cout<<ans<<endl;
}