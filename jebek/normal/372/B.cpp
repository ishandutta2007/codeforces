#include <iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n,m,a[50][50],q,dp[50][50][50][50],dp1[50][50][50][50];
int MAX1;

int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            a[i][j]=int(c-'0');
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
                continue;
            MAX1=0;
            for(int u=i;u>0;u--)
            {
                if(a[u][j])
                    MAX1=max(MAX1,u+1);
              //  MAX2=0;
                for(int v=j;v>0;v--)
                {
                  //  if(a[i][v])
                      //  MAX2=max(MAX2,v);
                    dp[i][j][u][v]=dp[i][j-1][max(MAX1,u)][v]+1+dp[i-1][j][u][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int u=1;u<=i;u++)
            {
                for(int v=1;v<=j;v++)
                {
                    dp1[i][j][u][v]=dp1[i-1][j][u][v]+dp1[i][j-1][u][v]-dp1[i-1][j-1][u][v]+dp[i][j][u][v];
                  //  cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<dp1[i][j][u][v]<<endl;
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        ll x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        cout<<dp1[max(x,x1)][max(y,y1)][min(x,x1)][min(y,y1)]<<endl;
    }
}