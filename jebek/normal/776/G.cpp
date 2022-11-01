#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[20][20][20],dp1[20][20][20],p[20][20];
vector<int>v;

ll toNumb(string s)
{
  ll ret=0;
  for(int i=0;i<s.size();i++)
    {
      int tmp=(isdigit(s[i])?s[i]-'0':s[i]-'a'+10);
      ret=ret*16+tmp;
    }
  return ret;
}

void initialize()
{
  for(int i=0;i<20;i++)
    {
      p[i][0]=1;
      for(int j=1;j<20;j++)
	p[i][j]=p[i][j-1]*i;
    }
  for(int k=15;k>-1;k--)
    {
      for(int i=1;i<(1<<16);i++)
	{
	  int MAX=0, tmp=i, cnt=0;
	  while(tmp) { MAX=max(MAX,tmp%16); tmp/=16; cnt++;}
	  if(i&(1<<max(MAX,k))) dp[k][cnt][MAX]++;
	}
      for(int i=1;i<=4;i++)
	for(int j=1;j<16;j++)
	  {
	    dp[k][i][j]+=dp[k][i-1][j];
	    dp1[k][i][j]=dp[k][i][j]+dp1[k][i][j-1];
	  }
      for(int i=5;i<20;i++)
	for(int j=1;j<16;j++){
	  dp[k][i][j]=dp1[max(k,j)][i-1][j];
	  for(int x=0;x<j;x++)
	    dp[k][i][j]+=dp[max(k,x)][i-1][j];
	  dp1[k][i][j]=dp[k][i][j]+dp1[k][i][j-1];
	}
    }
}

ll Dp(ll x)
{
  v.clear();
  while(x)
    {
      v.push_back(x%16);
      x/=16;
    }
  ll ans=0,sum=0;int MAX=0;
  for(int i=v.size()-1;i>-1;i--)
    {
      if(i>=4) {
	for(int j=0;j<v[i];j++)
	  ans+=dp1[max(MAX,j)][i][15];
      }
      else
	{
	  for(int j=0;j<v[i];j++)
	    {
	      if(i>0 && max(MAX,j)<i*4) ans+=dp1[max(MAX,j)][i][i*4-1];
	      for(int k=max(4*i,max(MAX,j));k<16;k++)
		if((1<<k)&sum)
		  ans+=p[k+1][i]-(k>max(MAX,j)?p[k][i]:0);
	      sum+=(1<<(4*i));
	    }
	}
      MAX=max(MAX,v[i]);
    }
  return ans;
}

int main()
{
  initialize();
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
    {
      string l,r;
      cin>>l>>r;
      cout<<Dp(toNumb(r)+1)-Dp(toNumb(l))<<endl;
    }
}