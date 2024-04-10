#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn = 310,MOD=1e9+7;
ll c[maxn][maxn],dp[maxn][maxn],n,ans=1;
pll P[maxn];
vector<ll>v;

int f(ll x)
{
  ll y=x;
  vector<ll>tmp;
  for(ll i=2;i*i<=x;i++)
    {
      if(x%i==0)
	{
	  tmp.push_back(i);
	  while(x%i==0)
	    x/=i;
	}
    }
  for(int i=0;i<tmp.size();i++)
    {
      while(y%(tmp[i]*tmp[i])==0)
	y/=tmp[i]*tmp[i];
    }
  return y;
}

int main()
{
  for(int i=0;i<maxn;i++)
    c[i][0]=c[i][i]=1;
  for(int i=1;i<maxn;i++)
    for(int j=1;j<i;j++)
      c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>P[i].Y;
      P[i].X=f(P[i].Y);
    }
  sort(P,P+n);
  ll t=1;
  for(int i=1;i<n;i++)
    {
      if(P[i].X!=P[i-1].X)
	{
	  v.push_back(t);
	  t=1;
	}
      else
	t++;
      ans=(ans*t)%MOD;
    }
  v.push_back(t);
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  dp[0][v[0]-1]=1;
  ll sum=0;
  for(int i=1;i<v.size();i++)
    {
      sum+=v[i-1];
      for(int j=1;j<=v[i];j++)
	{
	  if(sum+1<j) continue;
	  for(int x=0;x<sum;x++)
	    for(int k=0;k<=j && k<=x;k++)
	      {
		if(j-k>sum+1-x) continue;
		dp[i][x-k+v[i]-j]+=((dp[i-1][x]*c[v[i]-1][j-1])%MOD)*((c[x][k]*c[sum+1-x][j-k])%MOD);
		dp[i][x-k+v[i]-j]%=MOD;
	      }
	}
    }
  cout<<(dp[v.size()-1][0]*ans)%MOD<<endl;
}