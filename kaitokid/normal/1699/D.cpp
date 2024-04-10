#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>id[5009];
int dp[5009];
int mx[5009][5009],fr[5009],a[5009];
bool can(int x,int y)
{
    if(y<x)return true;
    if(mx[x][y]>y-x+1-mx[x][y])return false;
    if((y-x+1)%2)return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)id[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            id[a[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n;j++)fr[j]=0;
            int u=0;
            for(int j=i;j<n;j++)
            {
                fr[a[j]]++;
                u=max(u,fr[a[j]]);
                mx[i][j]=u;
            }
        }
        int ans=0;
        for(int r=0;r<=n;r++)
        {
           //cout<<r<<endl;
            if(id[r].empty())continue;
            int z=id[r].size();
            for(int i=z-1;i>=0;i--)
            {
                dp[i]=-1000000000;
                if(can(id[r][i]+1,n-1))dp[i]=1;
                for(int j=i+1;j<z;j++)
                {
                    if(can(id[r][i]+1,id[r][j]-1))dp[i]=max(dp[i],1+dp[j]);
                    if(can(id[r][i],id[r][j]-1))dp[i]=max(dp[i],dp[j]);
                }
             // cout<<dp[i]<<" ";
               if(can(0,id[r][i]-1))ans=max(ans,dp[i]);
            }
            //cout<<endl;

        }
        cout<<ans<<endl;


        }

    return 0;
}