#include <iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000007;
long long dp1[200][200],dp2[200][200],ans,a;
int n,m,k;

int main()
{
    cin>>n>>k>>m;
    m--;
    dp1[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int u=1;u<=min(k,j);u++)
            {
                dp1[i][j]+=dp1[i-1][j-u];
                dp1[i][j]%=MOD;
            }
    }
    for(int i=1;i<=n;i++)
        ans+=dp1[i][n];
  //  cout<<ans<<endl;
    if(m==0)
    {
        cout<<ans%MOD<<endl;
        return 0;
    }
    dp2[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int u=1;u<=min(j,m);u++)
            {
                dp2[i][j]+=dp2[i-1][j-u];
                dp2[i][j]%=MOD;
            }
    }
    for(int i=1;i<=n;i++)
        ans-=dp2[i][n];
    if(ans<0)
    {
        a=(ans-MOD+1)/MOD;
        ans-=MOD*a;
    }
    cout<<ans%MOD<<endl;
}