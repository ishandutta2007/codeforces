#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,a[1000],dp[1000][1000],ans,x;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i+1];
    for(int j=0;j<m;j++)
    {
        cin>>x;
        for(int i=1;i<=n;i++)
            if(i!=x)
                ans+=dp[x][i]*a[i];
        for(int i=1;i<=n;i++)
        {
            dp[x][i]=0;
            dp[i][x]=1;
        }
        dp[x][x]=0;
    }
    cout<<ans<<endl;
}