#include <iostream>
#include<algorithm>

using namespace std;

int n,m,a[200],b[200],dp[2][2000000];
char c[200];
bool mark[2][2000000];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    sort(a,a+n);
    reverse(a,a+n);
    n=m;
    for(int i=0;i<m;i++)
        cin>>c[i]>>b[i];
    for(int i=0;i<(1<<m);i++)
        mark[m%2][i]=true;
    for(int i=m-1;i>-1;i--)
    {
        if(b[i]==1)
        {
            for(int j=0;j<(1<<m);j++)
            {
                dp[i%2][j]=-1000000000;
                if(c[i]=='b' && mark[1-i%2][j])
                {
                    mark[i%2][j]=true;
                    dp[i%2][j]=dp[1-i%2][j];
                }
                for(int x=0;x<m;x++)
                    if(!((1<<x)&j))
                    {
                        if(c[i]=='b' && mark[1-i%2][j+(1<<x)])
                        {
                            mark[i%2][j]=true;
                            dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j+(1<<x)]);
                        }
                        if(c[i]=='p' && mark[1-i%2][j+(1<<x)])
                        {
                            mark[i%2][j]=true;
                            dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j+(1<<x)]+a[x]);
                        }
                    }
               // cout<<i<<" "<<j<<" "<<dp[i%2][j]<<endl;
            }
        }
        else
        {
            for(int j=0;j<(1<<m);j++)
            {
                dp[i%2][j]=1000000000;
                if(c[i]=='b' && mark[1-i%2][j])
                {
                    mark[i%2][j]=true;
                    dp[i%2][j]=dp[1-i%2][j];
                }
                for(int x=0;x<m;x++)
                    if(!((1<<x)&j))
                    {
                        if(c[i]=='b' && mark[1-i%2][j+(1<<x)])
                        {
                            mark[i%2][j]=true;
                            dp[i%2][j]=min(dp[i%2][j],dp[1-i%2][j+(1<<x)]);
                        }
                        if(c[i]=='p' && mark[1-i%2][j+(1<<x)])
                        {
                            mark[i%2][j]=true;
                            dp[i%2][j]=min(dp[i%2][j],dp[1-i%2][j+(1<<x)]-a[x]);
                        }
                    }
               // cout<<i<<" "<<j<<" "<<dp[i%2][j]<<endl;
            }
        }
    }
    cout<<dp[0][0]<<endl;
}