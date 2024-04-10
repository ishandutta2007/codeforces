#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxk=5000,MOD=1e9+7;
ll n,k,C[maxk+100],c[maxk+100][maxk+100],dp[maxk+100],ans;

ll p(ll a,ll b)
{
  ll c=1;
  while(b)
    {
      if(b%2) c=(c*a)%MOD;
      a=a*a%MOD;
      b/=2;
    }
  return c;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=maxk;i++)
    c[i][0]=c[i][i]=1;
  for(int i=2;i<=maxk;i++)
    for(int j=1;j<i;j++)
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;

  C[0]=1;
  for(int i=1;i<=min((ll)maxk,n);i++)
    C[i]=C[i-1]*(n-i+1)%MOD*p(i,MOD-2)%MOD;
    
  for(int i=1;i<=min(k,n);i++)
    {
      dp[i]=p(i,k);
      for(int j=1;j<i;j++)
	{
	   dp[i]=(dp[i]-dp[j]*c[i][j]%MOD+MOD)%MOD;
	   //else dp[i]=(dp[i]+dp[j]*c[i][j]%MOD)%MOD;
	}
      ans=(ans+ dp[i]*C[i]%MOD*p(2,n-i)%MOD )%MOD;
      // cerr<<dp[i]<<" "<<ans<<endl;
    }
  cout<<ans<<endl;
}