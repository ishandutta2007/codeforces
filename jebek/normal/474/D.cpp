#include <iostream>

using namespace std;

const int MAXN=200000,MOD=1000000007;
long long n,k,dp1[MAXN],dp2[MAXN],sum[MAXN];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        dp1[i]=1;
        sum[i]=i;
    }
    sum[k]++;
    dp2[k]=1;
    for(int i=k+1;i<200000;i++)
    {
        dp1[i]=(dp1[i-1]+dp2[i-1])%MOD;
        dp2[i]=(dp1[i-k]+dp2[i-k])%MOD;
        sum[i]=(sum[i-1]+dp1[i]+dp2[i])%MOD;
      //  cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<" "<<sum[i]<<endl;
    }
   // sum[0]=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<(sum[b]-sum[a-1]+MOD)%MOD<<endl;
    }
}