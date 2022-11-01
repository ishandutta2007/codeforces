#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n,t,dp[200][2000],ans;
vector<int>v[200];

int main()
{
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[t-a].push_back(b);
    }
    memset(dp[0],-127,sizeof dp[0]);
    dp[0][1]=0;
    sort(v[0].begin(),v[0].end());
    if(v[0].size())
        dp[0][0]=v[0].back();
    for(int i=1;i<t;i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-100000000;
            for(int x=(j+1)/2;x<=n;x++)
            {
                ans=dp[i-1][x];
                for(int y=0;y<2*x-j && y<v[i].size();y++)
                    ans+=v[i][y];
                dp[i][j]=max(dp[i][j],ans);
            }
        }
    }
    ans=0;
    for(int i=0;i<=n;i++)
        ans=max(ans,dp[t-1][i]);
    cout<<ans<<endl;
}