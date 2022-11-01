#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
int dp[2000];
ll c[2000][2000];
int k;

ll find(int t,int rem)
{
  ll ret=0;
  for(int i=0;i<=rem;i++)
    if(dp[t+i]==k-1)
      ret=(ret+c[rem][i])%MOD;
  return ret;
}

ll go(string s)
{
  int t=0;
  ll ans=0;
  for(int i=0;i<s.size();i++)
    if(s[i]=='1')
      {
	ans=(ans+find(t,s.size()-i-1))%MOD;
	t++;
      }
  ans=(ans+find(t,0))%MOD;
  return ans;
}

int main()
{
  dp[0]=-10000;
  for(int i=2;i<=1000;i++)
    dp[i]=dp[__builtin_popcount(i)]+1;
  for(int i=0;i<=1000;i++)
    c[i][i]=c[i][0]=1;
  for(int i=2;i<=1000;i++)
    for(int j=1;j<i;j++)
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
  string s;
  cin>>s;
  cin>>k;
  if(k==0){
    cout<<1<<endl;
    return 0;
  }
  cout<<go(s)-(k==1)<<endl;
}