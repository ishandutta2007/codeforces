#include <iostream>
#include<algorithm>

using namespace std;

int n,m,a[200],b[200],dp[200][200];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(abs(a[i]-b[j])<2)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    cout<<dp[n][m]<<endl;
}