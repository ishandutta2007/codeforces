#include <iostream>
#include<algorithm>

using namespace std;

int n,m;
long long a[2000][2000],dp1[2000][2000],dp2[2000][2000],dp3[2000][2000],dp4[2000][2000],ans;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=m;j>0;j--)
        {
            dp2[i][j]=max(dp2[i-1][j],dp2[i][j+1])+a[i][j];
        }
    for(int i=n;i>0;i--)
        for(int j=1;j<=m;j++)
        {
            dp4[i][j]=max(dp4[i+1][j],dp4[i][j-1])+a[i][j];
        }
    for(int i=n;i>0;i--)
        for(int j=m;j>0;j--)
        {
            dp3[i][j]=max(dp3[i+1][j],dp3[i][j+1])+a[i][j];
        }
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
        {
            ans=max(ans,max(dp1[i][j-1]+dp2[i-1][j]+dp3[i][j+1]+dp4[i+1][j],dp1[i-1][j]+dp2[i][j+1]+dp3[i+1][j]+dp4[i][j-1]));
           // cout<<i<<" "<<j<<" "<<dp1[i][j-1]<<" "<<dp2[i-1][j]<<" "<<dp3[i][j+1]<<" "<<dp4[i+1][j]<<" "<<dp1[i-1][j]+dp2[i][j+1]+dp3[i+1][j]+dp4[i][j-1]<<endl;
        }
    cout<<ans<<endl;
}