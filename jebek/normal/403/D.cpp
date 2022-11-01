#include <iostream>
#include<algorithm>

using namespace std;

const long long MOD=1000000007;
long long f,c[2100][2100],dp[1100][1100],k,t,n,m,x[1100][1100],ans1;

int main()
{
    f=1;
    for(int i=0;i<=2000;i++)
    {
        c[i][0]=1;
        c[i][i]=1;
    }
    for(int i=0;i<=1000;i++)
    {
        x[i][1]=1;
        for(int j=2;j<=1000;j++)
        {
            x[i][j]=x[i][j-1];
            if(j<=i)
            {
                x[i][j]+=x[i-j][j];
                x[i][j]=x[i][j]%MOD;
            }
            //cout<<i<<" "<<j<<" "<<x[i][j]<<endl;
        }
    }
    for(int i=2;i<=2000;i++)
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    for(int i=1;i<=1000;i++)
    {
        f*=i;
        f=f%MOD;
        k=i*(i+1)/2;
        if(k>1000)
            break;
        dp[i][k]=f;
       // cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
        for(int j=k+1;j<=1000;j++)
        {
          //  dp[i][j]=dp[i][j-1];
            m=j-k;
            for(int u=0;u<=m;u++)
            {
                ans1=(c[u+i][i]*x[m-u][i])%MOD;
                dp[i][j]+=(ans1*f)%MOD;
                if(dp[i][j]<0)
                {
                    cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
              //  cout<<dp[i][j]<<"*"<<c[u+i][i]<<" "<<x[m-u][i]<<endl;
                dp[i][j]=dp[i][j]%MOD;
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        cout<<dp[k][n]<<endl;
    }
}