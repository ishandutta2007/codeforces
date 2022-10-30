#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN=3100;
long long dp[MAXN][MAXN],n,m,ans,t[MAXN][MAXN];
vector<int>G[MAXN],G1[MAXN];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        t[v][u]++;
        G[v].push_back(u);
        G1[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<G[i].size();j++)
            for(int u=0;u<j;u++)
            {
                if(G[i][j]!=G[i][u])
                    dp[G[i][j]][G[i][u]]++;
                 //   cout<<i<<" "<<G[i][j]<<"->"<<G[i][u]<<endl;
            }
    for(int i=1;i<=n;i++)
        for(int j=0;j<G1[i].size();j++)
            for(int u=0;u<j;u++)
            {
              //  cout<<iG1[i][j]<<" "<<G1[i][u]<<endl;
                ans+=dp[G1[i][j]][G1[i][u]]+dp[G1[i][u]][G1[i][j]]-t[i][G1[i][j]]*t[i][G1[i][u]];
            }
    cout<<ans<<endl;
}