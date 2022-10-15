#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    int r,g,b;
    cin>>r>>g>>b;

    int red[r],green[g],blue[b];
    for(int i=0;i<r;i++) cin>>red[i];
    for(int i=0;i<g;i++) cin>>green[i];
    for(int i=0;i<b;i++) cin>>blue[i];

    sort(red,red+r);
    sort(green,green+g);
    sort(blue,blue+b);

    long long int dp[r+1][g+1][b+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=r;i++)
    {
        for(int j=0;j<=g;j++)
        {
            for(int k=0;k<=b;k++)
            {
                if(i>0 && j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+red[i-1]*green[j-1]);
                if(i>0 && k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+red[i-1]*blue[k-1]);
                if(j>0 && k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+green[j-1]*blue[k-1]);
            }
        }
    }
    cout<<dp[r][g][b]<<endl;
}