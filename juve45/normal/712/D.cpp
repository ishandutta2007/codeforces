#include <iostream>
#define M 1000000007

using namespace std;

long long sum[200010][110],dp[200010][110],i,j,a,b,k,t,ans;

long long maxim(long long a,long long b)
{
    if (a>=b)
        return a;
    return b;
}

long long minim(long long a,long long b)
{
    if (a>=b)
        return b;
    return a;
}

int main()
{
    cin>>a>>b>>k>>t;
    for (i=k*(t-1); i<=k*(t+1); i++)
        dp[i][1]=1;
    sum[0][1]=dp[0][1];
    for (i=1; i<=2*k*t; i++)
        sum[i][1]=(sum[i-1][1]+dp[i][1])%M;
    for (i=2; i<=t; i++)
    {
        j=0;
        dp[j][i]=(dp[j][i]+sum[minim(j+k,2*k*t)][i-1]-sum[maxim(j-k-1,0)][i-1])%M;
        sum[0][i]=dp[0][i];
        for (j=1; j<=2*k*t; j++)
            dp[j][i]=(dp[j][i]+sum[minim(j+k,2*k*t)][i-1]-sum[maxim(j-k-1,0)][i-1])%M,sum[j][i]=(sum[j-1][i]+dp[j][i])%M;
    }
    int x=(b-a)%M;
    if (x>=0)
    {
        for (i=0; i<=2*k*t; i++)
            if (i+x<=2*k*t)
                ans=(ans+(sum[2*k*t][t]-sum[i+x][t])*dp[i][t]%M)%M;
    }
    else
        for (i=0; i<=2*k*t; i++)
            if (i+x<=2*k*t)
                if (i+x<0)
                ans=(ans+(sum[2*k*t][t])*dp[i][t]%M)%M;
            else
                ans=(ans+(sum[2*k*t][t]-sum[maxim(i+x,0)][t])*dp[i][t]%M)%M;
                if(ans<0) ans+=M;
    cout<<ans<<'\n';
}